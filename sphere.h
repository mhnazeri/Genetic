#ifndef SPHERE_H
#define SPHERE_H
#include "interface.h"
#include "random_generator.h"

class Interface;
class Random_Generator;

class Sphere
{
public:
//    Sphere();
    Sphere(Interface *u, int pop, int gen, float mut, int geno, float cross);

private:
    Interface *ui;
    const int POPULATION_SIZE;
    const int GENERATION_NUMBER;
    const float MUTATION_RATE;
    const int GENOME;
    const float CROSSOVER_RATE;
    Random_Generator dice;
    std::vector<std::vector<int>> population;
    std::vector<std::vector<int>> middle;
};

#endif // SPHERE_H
