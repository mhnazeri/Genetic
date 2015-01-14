#include "sphere.h"

//Sphere::Sphere()
//{
//}

Sphere::Sphere(Interface *u, int pop, int gen, float mut, int geno, float cross) :
    ui(u), POPULATION_SIZE(pop), GENERATION_NUMBER(gen), MUTATION_RATE(mut), GENOME(geno), CROSSOVER_RATE(cross)
{
}
