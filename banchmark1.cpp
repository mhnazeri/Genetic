#include "banchmark1.h"
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

//banchmark1::~banchmark1()
//{
//}

banchmark1::banchmark1(Interface *u, int pop, int gen, float mut, float elit, float cross) :
    ui(u), POPULATION_SIZE(pop), GENERATION_NUMBER(gen), MUTATION_RATE(mut), ELITISM_RATE(elit), CROSSOVER_RATE(cross)
{
}

void banchmark1::Run()
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
}


void banchmark1::InitialPopulation()
{
}

void banchmark1::Fitness()
{
}

bool banchmark1::isFinished()
{
    return true;
}

void banchmark1::Selection()
{
}

void banchmark1::CrossOver()
{
}

void banchmark1::Mutate()
{
}


void banchmark1::Swap()
{
}

void banchmark1::Elitism()
{
}

void banchmark1::Best()
{
}

