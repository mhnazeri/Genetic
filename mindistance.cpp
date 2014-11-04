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

minDistance::minDistance(Interface *u, int pop, int gen, float mut, float elit) :
    ui(u), POPULATION_NUMBER(pop), GENERATION_NUMBER(gen), MUTAION_RATE(mut), ELITISM_RATE(elit)
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
    for(int i = 0; i < POPULATION_NUMBER; i++)
    {
        choro citizen;
        citizen.x = prandom.RandomDouble(55, 59);
        citizen.y = prandom.RandomDouble(28, 31);
        citizen.fit = 0.0;
        population.push_back(citizen);
    }
    middle.resize(POPULATION_NUMBER);
}

void minDistance::Fitness(std::vector<choro> &population)
{
    double fitness = 0.0;
    choro citizen;
    for(int i = 0; i < POPULATION_NUMBER; i++)
    {
        citizen = population[i];
        for(int j = 0; j < 9; j++)
        {
            fitness += sqrt(pow(citizen.y - latitude->at(j),2) + pow(citizen.x - longitude->at(j),2));
        }
        citizen.fit = fitness;
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

}

void minDistance::Mutate()
{

}

void minDistance::rePlace()
{

}
