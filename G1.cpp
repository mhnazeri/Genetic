#include "G1.h"
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

G1::~G1()
{
    delete mehvarx;
    delete mehvary;
}

G1::G1(Interface *u, int pop, int gen, float mut, int geno, float cross) :
    ui(u), POPULATION_SIZE(pop), GENERATION_NUMBER(gen), MUTATION_RATE(mut), GENOME(geno), CROSSOVER_RATE(cross)
{
    minimum->fit = 1;
}

void G1::Run()
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
    ui->ui->text_answer->setText("mehvary = " + QString::number(minimum->y) + " , mehvarx = " + QString::number(minimum->x));
    std::cout << "mehvary = " + QString::number(minimum->y).toStdString() + " , mehvarx = " + QString::number(minimum->x).toStdString() << std::endl;
    std::vector<double> lx;
    std::vector<double> ly;
    la.push_back(minimum->y);
    ly.push_back(minimum->x);
    ui->Plot(lx, ly, Qt::yellow, QCPScatterStyle::ssDisc, QCPGraph::lsNone, 10, 10, "mehvarx", "mehvary", -30, 100, -30, 100, 20);
}




void G1::InitialPopulation()
{
    std::vector<double> lx;
    std::vector<double> ly;
    for(int i = 0; i < POPULATION_SIZE; i++)
    {
        chro point;
        point.x = dice.Double(-30, 100);
        point.y = dice.Double(-30, 100);
        lx.push_back(point.x);
        ly.push_back(point.y);
        point.fit = 1;
        population.push_back(point);
    }
    ui->Plot(lx, ly, Qt::yellow, QCPScatterStyle::ssCrossSquare, QCPGraph::lsNone, 10, 10, "mehvarx", "mehvary", -30, 100, -30, 100, 20);
//    middle.resize(POPULATION_SIZE);

}

void G1::Fitness()
{
    double fitness = 0.0;
    chro *point = new chro;
    for(int i = 0; i < POPULATION_SIZE; i++)
    {
       point = &population[i];

       fitness = (((point->x)* (sin(4*(point->x)))) + (1.1*(point->y)*(sin(2*(point->y)))));

        point->fit = fitness;
        fitness = 0.0;
    }
    point = nullptr;
    delete point;
}

bool G1::isFinished()
{
    return true;
}

void G1::Selection()
{
    chro chro1, chro2, chro3;
    chro selected;
    for(int i = 0; i < POPULATION_SIZE; i++)
    {
        chro1 = population[dice.Integer(0,POPULATION_SIZE)];
        chro2 = population[dice.Integer(0,POPULATION_SIZE)];
        chro3 = population[dice.Integer(0,POPULATION_SIZE)];
        if(chro1.fit < chro2.fit)
        {
            if(chro1.fit < chro3.fit)
            {
                selected.fit = chro1.fit;
                selected.x = chro1.x;
                selected.y = chro1.y;
            }else{
                selected.fit = chro3.fit;
                selected.x = chro3.x;
                selected.y = chro3.y;
            }
        }else{
            if(chro2.fit < chro3.fit)
            {
                selected.fit = chro2.fit;
                selected.x = chro2.x;
                selected.y = chro2.y;
            }else{
                selected.fit = chro3.fit;
                selected.x = chro3.x;
                selected.y = chro3.y;
            }
        }
        middle.push_back(selected);
    }
}

void G1::CrossOver()
{
    chro t1;
    chro t2;
    chro t3;
    chro t4;
    for(int i = 0; i < POPULATION_SIZE; i++)
    {
        if(dice.Double(0,1) <= CROSSOVER_RATE)
        {
            t1 = middle[i];
            t2 = middle[i+1];
            t3.x = (t1.x + t2.x);
            t3.y = (t1.y + t2.y);
            t4.x = (t1.x - t2.x);
            t4.y = (t1.y - t2.y);
            middle[i] = t3;
            middle[i+1] = t4;
        }
    }
}

void G1::Mutate()
{
    random6 = dice.Integer(0,POPULATION_SIZE);//MIDDLE_SIZE=POPULATION_SIZE
     chro point1 = new chro;
     chro point = new chro;


       for(i=0 ; i<=random ; i++)
    {
         if(dice.Double(0,1) < MUTATION_RATE)
            {
             random7 = dice.Integer(0,POPULATION_SIZE);
             point = &middle[random1];
             najmeh=0;
        while (najmeh=0)
        {

        random8 = dice.Double(-10,10);
        if ((point->x + random8>=-30) && (point->x + random8<=100))
        {
             point1->x = (point.x)+random8;
             point->x = point1.x;
             point->y = point.y;
             najmeh=1;
        }

        }
           }
       }
}


void G1::replace()
{
    chro* t6;
    chro mid;
    for(int i = 0; i < POPULATION_SIZE; i++)
    {
        t6 = &population[i];
//        population[i] = middle[i];
        mid = middle[i];
        if(mid.fit<t6->fit)
        {
        t6->x = mid->x;
        t6->y = mid.y;
        t6->fit = mid.fit;
        }
    }
    t6 = nullptr;

}



void G1::Best()
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
            min.y = temp.y;
        }
        if(minimum->fit > temp.fit)
        {
            minimum->fit = temp.fit;
            minimum->x = temp.x;
            minimum->y = temp.y;
        }


}

    std::vector<double> lx;
    std::vector<double> ly;
    lx.push_back(min.y);
    ly.push_back(min.x);
    ui->Plot(lx, ly, Qt::red, QCPScatterStyle::ssStar, QCPGraph::lsNone, 10, 10, "mehvarx", "mehvary", -30, 100, -30, 100, 20);
    std::cout << "mehvary = " + QString::number(min.y).toStdString() + " , mehvarx = " + QString::number(min.x).toStdString() << std::endl;
}
