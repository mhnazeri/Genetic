#ifndef MINDISTANCE_H
#define MINDISTANCE_H

#include "interface.h"
#include "ui_interface.h"

class Interface;
class minDistance
{
public:
    minDistance(Interface *u);
    ~minDistance();
    minDistance(int pop, int gen, int mut, int elit);
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
    void GenerateOffspring();
    void Mutate();
    void rePlace();

private:
    Interface *ui;
    int population_number;
    int generation;
    int mutation;
    int elitism;
};


#endif // MINDISTANCE_H
