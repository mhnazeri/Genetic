#ifndef SPHERE_H
#define SPHERE_H
#include "interface.h"


class Interface;
class Sphere
{
public:
    Sphere();
    Sphere(Interface *u, int pop, int gen, float mut, int geno, float cross);
    void Run();
    void InitialPopulation();
    void Fitness();
    bool isFinished();
    void Selection();
    void CrossOver();
    void Mutate();
    void Replace();
    void Best();

private:
    Interface *ui;
    const int POPULATION_SIZE;
    const int GENERATION_NUMBER;
    const float MUTATION_RATE;
    const int GENOME;
    const float CROSSOVER_RATE;

};

#endif // SPHERE_H
