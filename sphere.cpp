
#include "sphere.h"


Sphere::~Sphere()
{
}

Sphere::Sphere(Interface *u, int pop, int gen, float mut, float elit, float cross) :
    ui(u), POPULATION_SIZE(pop), GENERATION_NUMBER(gen), MUTATION_RATE(mut), ELITISM_RATE(elit), CROSSOVER_RATE(cross)
{
}

void Sphere::Run()
{
    InitialPopulation();
    for(int i = 0; i < GENERATION_NUMBER; i++)
    {
        Fitness();
        Best();
        Selection();
        CrossOver();
        Mutate();
        Replace();
    }
    Fitness();
    Best();
}

void Sphere::InitialPopulation()
{

    for(int i = 0; i < POPULATION_SIZE; i++)
    {
        chro chromozom;
        chromozom.x = dice.Integer(-15,15);
        chromozom.fit = 1000.0;
        population.push_back(chromozom);
    }

}

void Sphere::Fitness()
{
    Integer fitness = 0.0;
    chro *chromozom = new chro;
    for(int i = 0; i < POPULATION_SIZE; i++)
    {
        chromozom = &population[i];
        for(int j = 0; j < GENOME; j++)
        {
            fitness =sum(chromozom->x ^2);
        }
        chromozom->fit = fitness;
        fitness = 0.0;
    }
    chromozom = nullptr;
    delete chromozom;
}

bool Sphere::isFinished()
{
    return true;
}

void Sphere::Selection()
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

void Sphere::CrossOver()
{
    chro temp1;
    chro temp2;

    for(int i = 0; i < POPULATION_SIZE; i++)
    {
        if(dice.Double(0,1) <= CROSSOVER_RATE)
        {
            temp1 = middle[dice.integer(0,population_size)];
            temp2 = middle[dice.integer(0,population_size)];
            temp = temp1;
            temp1 = temp2;
            temp2 = temp;
        }
    }
}

void Sphere::Mutate()
{
    chro *chromozom;
    Integer random;
    for(int i = 0; i < POPULATION_SIZE; i++)
    {
        if(dice.Integer(0.01,0.04)  < MUTATION_RATE)
        {
            random = dice.Integer(0,5);
            chromozom = &middle[i];
            if((chromozom->x >= 5 ))
            {
                    chromozom->x = (chromozom->x + random) - 5;
            }else{
                chromozom->x = chromozom->x + random;
            }

        }
    }
    chromozom = nullptr;
    delete chromozom;
}

void Sphere::Replace()
{
    chro* temp;
    chro mid;
    for(int i = 0; i < POPULATION_SIZE; i++)
    {
        temp = &population[i];
        mid = middle[i];
        temp->x = mid.x;
        temp->fit = mid.fit;
    }
    temp = nullptr;
}

void Sphere::Best()
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
