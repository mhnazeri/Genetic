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
    minDistance(Interface *u, int pop, int gen, float mut, float elit);
    struct choro
    {
        double x;
        double y;
        double fit;
    };
    void InitialPopulation();
    void Fitness(std::vector<choro> &population);
    bool isFinished();
    void Selection();
    void CrossOver();
    void Mutate();
    void rePlace();

private:
    Interface *ui;
    const int POPULATION_NUMBER;
    const int GENERATION_NUMBER;
    const float MUTAION_RATE;
    const float ELITISM_RATE;
    QVector<double> *latitude = new QVector<double>();
    QVector<double> *longitude = new QVector<double>();
    Random_Generator prandom;
    std::vector<choro> population;
    std::vector<choro> middle;
};


#endif // MINDISTANCE_H
