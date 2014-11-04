#ifndef MINDISTANCE_H
#define MINDISTANCE_H

#include "interface.h"
#include "ui_interface.h"

class Interface;
class minDistance
{
public:
    minDistance();
    ~minDistance();
    minDistance(Interface *u, int pop, int gen, float mut, float elit);
    struct choro
    {
        int x;
        int y;
        float fit;
    };
    void InitialPopulation();
    void Fitness(choro &chrom);
    bool isFinished();
    void Selection();
    void CrossOver();
    void Mutate();
    void rePlace();

private:
    Interface *ui;
    int population_number;
    int generation;
    float mutation;
    float elitism;
    QVector<double> *latitude = new QVector<double>();
    QVector<double> *longitude = new QVector<double>();
};


#endif // MINDISTANCE_H
