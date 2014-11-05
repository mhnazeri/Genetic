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
    void rePlace();
    void Elitism();

private:
    Interface *ui;
    const int POPULATION_SIZE;
    const int GENERATION_NUMBER;
    const float MUTAION_RATE;
    const float ELITISM_RATE;
    const float CROSSOVER_RATE;
    QVector<double> *latitude = new QVector<double>();
    QVector<double> *longitude = new QVector<double>();
    Random_Generator prandom;
    std::vector<chro> population;
    std::vector<chro> middle;
};


#endif // MINDISTANCE_H
