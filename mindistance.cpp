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

//minDistance::minDistance(){}

minDistance::~minDistance()
{
    delete latitude;
    delete longitude;
}

minDistance::minDistance(Interface *u, int pop, int gen, float mut, float elit, float cross) :
    ui(u), POPULATION_SIZE(pop), GENERATION_NUMBER(gen), MUTATION_RATE(mut), ELITISM_RATE(elit), CROSSOVER_RATE(cross)
{
    minimum->fit = 1000;
    std::ifstream file("../Genetic/position.txt");
    std::ifstream myfile1("../Genetic/position.txt");
    CITY_COUNT = 0;
    string line;
    if(myfile1.is_open())
    {
        while(getline(myfile1,line))
        {
            CITY_COUNT++;
        }
        myfile1.close();
    }
    string temp="";
    if( file.is_open())
    {
        for(int i = 0; i < CITY_COUNT; i++)
        {
            file >> temp;
            latitude->push_back(std::stold(temp));
            file >> temp;
            longitude->push_back(std::stold(temp));
        }
        file.close();
    }else{
        std::cout << "Can't Load The Postion File!" << std::endl;
    }
    ui->Plot(*longitude, *latitude, Qt::blue, QCPScatterStyle::ssCross, QCPGraph::lsNone, 0.5, 0.5, "Longitude", "Latitude", 55, 59, 27, 31, 10);
}

void minDistance::Run()
{
    InitialPopulation();
    for(int i = 0; i < GENERATION_NUMBER; i++)
    {
        Fitness();
        Best();
        Selection();
        CrossOver();
        Mutate();
        Swap();
    }
    Fitness();
    Best();
    ui->ui->text_answer->setText("Latitude = " + QString::number(minimum->y) + " , Longitude = " + QString::number(minimum->x));
    std::vector<double> la;
    std::vector<double> lo;
    la.push_back(minimum->y);
    lo.push_back(minimum->x);
    ui->Plot(lo, la, Qt::green, QCPScatterStyle::ssStar, QCPGraph::lsNone, 0.5, 0.5, "Longitude", "Latitude", 55, 59, 27, 31, 20);
}

void minDistance::InitialPopulation()
{
    std::vector<double> la;
    std::vector<double> lo;
    for(int i = 0; i < POPULATION_SIZE; i++)
    {
        chro citizen;
        citizen.x = dice.Double(55, 59);
        citizen.y = dice.Double(28, 31);
        lo.push_back(citizen.x);
        la.push_back(citizen.y);
        citizen.fit = 1000.0;
        population.push_back(citizen);
    }
//    ui->Plot(lo, la, Qt::black, QCPScatterStyle::ssCrossCircle, QCPGraph::lsNone, 0.5, 0.5, "Longitude", "Latitude", 55, 59, 27, 31, 5);
    middle.resize(POPULATION_SIZE);
}

void minDistance::Fitness()
{
    double fitness = 0.0;
    chro *citizen = new chro;
    for(int i = 0; i < POPULATION_SIZE; i++)
    {
        citizen = &population[i];
        for(int j = 0; j < CITY_COUNT; j++)
        {
            fitness += sqrt(pow(citizen->y - latitude->at(j),2) + pow(citizen->x - longitude->at(j),2));
        }
        citizen->fit = fitness;
    }
    citizen = nullptr;
    delete citizen;
}

bool minDistance::isFinished()
{
    return true;
}

void minDistance::Selection()
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

void minDistance::CrossOver()
{
    chro temp1;
    chro temp2;
    chro temp3;
    chro temp4;
    for(int i = 0; i < POPULATION_SIZE; i++)
    {
        if(dice.Double(0,1) <= CROSSOVER_RATE)
        {
            temp1 = middle[i];
            temp2 = middle[i+1];
            temp3.x = (temp1.x + temp2.x)/2;
            temp4.y = (temp1.y + temp2.y)/2;
            temp4.x = std::abs(temp1.x - temp2.x)/2 + 55.0;
            temp4.y = std::abs(temp1.y - temp2.y)/2 + 28.0;
            middle[i] = temp3;
            middle[i+1] = temp4;
        }
    }
}

void minDistance::Mutate()
{
    chro *citizen;
    double random;
    for(int i = 0; i < POPULATION_SIZE; i++)
    {
        if(dice.Double(0,1) < MUTATION_RATE)
        {
            random = dice.Double(0, 4);
            citizen = &middle[i];
            if((citizen->x + random > 59))
            {
                    citizen->x = fmod((citizen->x + random), 59.0) + 55.0;
            }else{
                citizen->x = citizen->x + random;
            }
            random = dice.Double(0, 3);
            if((citizen->y + random > 31))
            {
                citizen->y = fmod((citizen->y + random), 31.0) + 28.0;
            }else{
                citizen->y = citizen->y + random;
            }
        }
    }
    citizen = nullptr;
    delete citizen;
}

void minDistance::Swap()
{
    for(int i = 0; i < POPULATION_SIZE; i++)
    {
        population[i] = middle[i];
    }
}

void minDistance::Elitism()
{
    int eli = ELITISM_RATE * POPULATION_SIZE;
    for(int i = 0; i < eli; i++)
    {
        middle[i] = population[i];
    }
}

void minDistance::Best()
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
    std::vector<double> la;
    std::vector<double> lo;
    la.push_back(min.y);
    lo.push_back(min.x);
    ui->Plot(lo, la, Qt::red, QCPScatterStyle::ssCircle, QCPGraph::lsNone, 0.5, 0.5, "Longitude", "Latitude", 55, 59, 27, 31, 10);
}
