#include "Rosenbrock.h"
#include "mindistance.h"
#include "interface.h"
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using std::string;
using std::stold;
using std::fmod;
using std::abs;

Rosenbrock::~Rosenbrock()
{
    delete latitude;
    delete longitude;
}

Rosenbrock::Rosenbrock(Interface *u, int pop, int gen, float mut, int geno, float cross) :
    ui(u), POPULATION_SIZE(pop), GENERATION_NUMBER(gen), MUTATION_RATE(mut), GENOME(geno), CROSSOVER_RATE(cross)
{
    minimum->fit = 20;

    for(int i=0;i< GENOME;i++)
    {
        longitude->push_back(dice.Double(0,100));
        latitude->push_back(minimum->fit);
}
    ui->Plot(*longitude, *latitude, Qt::green, QCPScatterStyle::ssCrossCircle, QCPGraph::lsNone, 10, 10, "Longitude", "Latitude", 0, 100, 0, 100, 10);
}

void Rosenbrock::Run()
{
    InitialPopulation();
    for(int i = 0; i < GENERATION_NUMBER; i++)
    {
        Fitness();
        Best();
        Selection();
        CrossOver();
        Mutate();
        replace();
    }
    Fitness();
    Best();
    ui->ui->text_answer->setText("Latitude = " + QString::number(minimum->fit) + " , Longitude = " + QString::number(minimum->x));
    std::cout << "Latitude = " + QString::number(minimum->fit).toStdString() + " , Longitude = " + QString::number(minimum->x).toStdString() << std::endl;
    std::vector<double> lx;
    std::vector<double> ly;
    ly.push_back(minimum->fit);
    lx.push_back(minimum->x);
    ui->Plot(lx, ly, Qt::blue, QCPScatterStyle::ssDisc, QCPGraph::lsNone, 10, 10, "Longitude", "Latitude", -1, 100, -1, 100, 10);
}



void Rosenbrock::InitialPopulation()
{
    std::vector<double> ly;
    std::vector<double> lx;

    for(int i = 0; i < POPULATION_SIZE; i++)
    {
        for(int j=0;j<GENOME;j++)
        {

        chro chromozom;
        chromozom.x = dice.Integer(-1,100);
        chromozom.fit = 1000.0;
        lx.push_back(chromozom.x);
        ly.push_back(chromozom.fit);
        population.push_back(chromozom);
       }
    }
    ui->Plot(lx, ly, Qt::blue, QCPScatterStyle::ssCrossCircle, QCPGraph::lsNone, 10, 10, "Longitude", "Latitude", -1, 100, -1, 100, 10);
//    middle.resize(POPULATION_SIZE);
}

void Rosenbrock::Fitness()
{
    double fitness = 0.0;
    chro *chromozom = new chro;
    chro *chromozom1 = new chro;
    for(int i = 0; i < POPULATION_SIZE; i++)
    {
        chro *chromozom = new chro;
        chro *chromozom1 = new chro;
        int f;
        chromozom=&population[i];
        //chromozom = &population[i];
        for(int j = 1; j < GENOME ; j++)
        {

            chromozom1 = &population[j];
             f = i;
            fitness +=((100*(pow((chromozom1->x)- (pow((chromozom->x),2)),2)))+(pow(((chromozom->x)-1),2))) ;
            f++;
            chromozom = &population[f];
        }
         f=0;
        chromozom->fit = fitness;
        fitness = 0.0;
    }
    chromozom = nullptr;
    delete chromozom;
}

bool Rosenbrock::isFinished()
{
    return true;
}

void Rosenbrock::Selection()
{
    chro p1, p2, p3;
    chro selected;
    for(int i = 0; i < POPULATION_SIZE; i++)
    {
        p1 = population[dice.Integer(0,POPULATION_SIZE)];
        p2 = population[dice.Integer(0,POPULATION_SIZE)];
        p3 = population[dice.Integer(0,POPULATION_SIZE)];
        if(p1.fit < p2.fit)
        {
            if(p1.fit < p3.fit)
            {
                selected.fit = p1.fit;
                selected.x = p1.x;

            }else{
                selected.fit = p3.fit;
                selected.x = p3.x;

            }
        }else{
            if(p2.fit < p3.fit)
            {
                selected.fit = p2.fit;
                selected.x = p2.x;

            }else{
                selected.fit = p3.fit;
                selected.x = p3.x;

            }
        }
        middle.push_back(selected);
    }
}

void Rosenbrock::CrossOver()
{
    chro temp1;
    chro temp2;
    chro temp;

    for(int i = 0; i < POPULATION_SIZE; i++)
    {
        if(dice.Double(0,1) <= CROSSOVER_RATE)
        {
            temp1 = middle[dice.Integer (0,POPULATION_SIZE)];
            temp2 = middle[dice.Integer (0,POPULATION_SIZE)];
            temp = temp1;
            temp1 = temp2;
            temp2 = temp;
        }
    }
}

void Rosenbrock::Mutate()
{
    chro *chromozom;
    int random;
    for(int i = 0; i < POPULATION_SIZE; i++)
    {
        if(dice.Integer(0,1)  < MUTATION_RATE)
        {
            random = dice.Integer(0,5);
            chromozom = &middle[i];
            if((chromozom->x >= 10))
            {
                    chromozom->x = (chromozom->x + random) - 10;
            }else{
                chromozom->x = chromozom->x + random;
            }

        }
    }
    chromozom = nullptr;
    delete chromozom;
}

void Rosenbrock::Replace()
{
    chro* temp;
    chro* mid;
    for(int i = 0; i < POPULATION_SIZE; i++)
    {
        temp = &population[i];
        mid = middle[i];
        temp->x = mid.x;
        temp->fit = mid.fit;
    }
    temp = nullptr;
}

void Rosenbrock::Best()
{
    chro temp;
    chro min;
    for(int i = 0; i < POPULATION_SIZE; i++)
    {
        temp = population[i];
        if(min.fit > temp.fit)
        {
            min.fit = temp.fit;
            min.x = temp.x;

        }

    }
    if(minimum->fit > min.fit)
    {
        minimum->fit = min.fit;
        minimum->x = min.x;

    }
    std::vector<double> lx;
    std::vector<double> ly;
    lx.push_back(min.fit);
    ly.push_back(min.x);
    ui->Plot(lx, ly, Qt::red, QCPScatterStyle::ssStar, QCPGraph::lsNone, 10, 10, "Longitude", "Latitude", -1, 100, -1, 100, 20);
    std::cout << "Latitude = " + QString::number(min.fit).toStdString() + " , Longitude = " + QString::number(min.x).toStdString() << std::endl;
}
