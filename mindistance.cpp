#include "mindistance.h"
#include "interface.h"
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <QDebug>

using std::string;

//minDistance::minDistance(){}

minDistance::~minDistance()
{
    delete ui;
    delete latitude;
    delete longitude;
}

minDistance::minDistance(Interface *u, int pop, int gen, float mut, float elit, float cross) :
    ui(u), POPULATION_SIZE(pop), GENERATION_NUMBER(gen), MUTAION_RATE(mut), ELITISM_RATE(elit), CROSSOVER_RATE(cross)
{
    std::ifstream file("../Genetic/position.txt");
    string temp="";
    if( file.is_open())
    {
        for(int i = 0; i < 9; i++)
        {
            file >> temp;
            latitude->push_back(std::stold(temp));
            file >> temp;
            longitude->push_back(std::stold(temp));
        }
    }else{
        std::cout << "Can't Load The Postion File!" << std::endl;
    }
    ui->ui->graphInterface->addGraph();
    ui->ui->graphInterface->xAxis->setAutoTickStep(false);
    ui->ui->graphInterface->yAxis->setAutoTickStep(false);
    ui->ui->graphInterface->xAxis->setTickStep(0.5);
    ui->ui->graphInterface->yAxis->setTickStep(0.5);
    ui->ui->graphInterface->xAxis->setLabel("Longitude");
    ui->ui->graphInterface->yAxis->setLabel("Latitude");
    ui->ui->graphInterface->xAxis->setRange(55, 59);
    ui->ui->graphInterface->yAxis->setRange(28, 31);
    ui->ui->graphInterface->graph(0)->setData(*longitude, *latitude);
    ui->ui->graphInterface->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCross, Qt::blue, Qt::white,10));
    ui->ui->graphInterface->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->ui->graphInterface->replot();
}

void minDistance::InitialPopulation()
{
    for(int i = 0; i < POPULATION_SIZE; i++)
    {
        chro citizen;
        citizen.x = prandom.RandomDouble(55, 59);
        citizen.y = prandom.RandomDouble(28, 31);
        citizen.fit = 1000.0;
        population.push_back(citizen);
    }
    middle.resize(POPULATION_SIZE);
}

void minDistance::Fitness()
{
    double fitness = 0.0;
    chro *citizen = new chro;
    for(int i = 0; i < POPULATION_SIZE; i++)
    {
        citizen = &population[i];
        for(int j = 0; j < 9; j++)
        {
            fitness += sqrt(pow(citizen->y - latitude->at(j),2) + pow(citizen->x - longitude->at(j),2));
        }
        (*citizen).fit = fitness;
    }
}

bool minDistance::isFinished()
{
    return true;
}

void minDistance::Selection()
{

}

void minDistance::CrossOver()
{
    chro *temp1;
    chro *temp2;
    chro *temp3 = new chro;
    chro *temp4 = new chro;
    for(int i = 0; i < POPULATION_SIZE; i+=2)
    {
        if(prandom.RandomDouble(0,1) <= CROSSOVER_RATE)
        {
            temp1 = &middle[i];
            temp2 = &middle[i+1];
            temp3->x = (temp1->x + temp2->x)/2;
            temp3->y = (temp1->y + temp2->y)/2;
            temp4->x = (temp1->x - temp2->x)/2;
            temp4->y = (temp1->y - temp2->y)/2;
            middle[i] = *temp3;
            middle[i+1] = *temp4;
        }
    }

}

void minDistance::Mutate()
{

}

void minDistance::rePlace()
{

}

void minDistance::Elitism()
{
    int eli = ELITISM_RATE * POPULATION_SIZE;
    for(int i = 0; i < eli; i++)
    {
        middle[i] = population[i];
    }
}
