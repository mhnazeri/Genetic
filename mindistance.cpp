#include "mindistance.h"
#include "interface.h"
#include <iostream>
#include <fstream>
#include <string>
#include <QDebug>

using std::string;

minDistance::minDistance(){}

minDistance::~minDistance()
{
    delete ui;
    delete latitude;
    delete longitude;
}

minDistance::minDistance(Interface *u, int pop, int gen, float mut, float elit) :
    ui(u), population_number(pop), generation(gen), mutation(mut), elitism(elit)
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
    ui->ui->graphInterface->graph(0)->setData(*latitude, *longitude);
    ui->ui->graphInterface->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCross, Qt::red, Qt::white,10));
    ui->ui->graphInterface->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->ui->graphInterface->replot();
}

void minDistance::InitialPopulation()
{

}

void minDistance::Fitness(choro &chrom)
{

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
