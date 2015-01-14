#ifndef MINDISTANCE_H
#define MINDISTANCE_H

#include "interface.h"
#include "ui_interface.h"
#include "random_generator.h"
#include <vector>

class Interface;
class Random_Generator;
class minDistance
{
public:
    minDistance();
    ~minDistance();
    minDistance(Interface *u, int pop, int gen, float mut, float elit, float cross);
    struct chro
    {
        double x = 58.0;
        double y = 28.0;
        double fit = 1000.0;
    };
    void InitialPopulation();
    void Fitness();
    bool isFinished();
    void Selection();
    void CrossOver();
    void Mutate();
    void Swap();
    void Elitism();
    void Best();
    bool Fitness_Sort(chro x, chro y);
    void Run();

private:
    Interface *ui;
    const int POPULATION_SIZE;
    const int GENERATION_NUMBER;
    const float MUTATION_RATE;
    const float ELITISM_RATE;
    const float CROSSOVER_RATE;
    std::vector<double> *latitude = new std::vector<double>();
    std::vector<double> *longitude = new std::vector<double>();
    Random_Generator dice;
    std::vector<chro> population;
    std::vector<chro> middle;
    int CITY_COUNT;
    minDistance::chro *minimum = new minDistance::chro;
};


#endif // MINDISTANCE_H
