#include "mindistance.h"
#include "interface.h"

minDistance::minDistance(Interface *u):ui(u){}

minDistance::~minDistance(){}

minDistance::minDistance(int pop, int gen, int mut, int elit):population_number(pop), generation(gen), mutation(mut), elitism(elit)
{}

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

void minDistance::GenerateOffspring()
{

}

void minDistance::Mutate()
{

}

void minDistance::rePlace()
{

}
