#ifndef Rosenbrock_H
#define Rosenbrock_H
#include "interface.h"
#include "ui_interface.h"
#include "random_generator.h"
#include <vector>
#include <chrono>


class Interface;
class Random_Generator;
class Rosenbrock
{
public:
//    Rosenbrock();
    ~Rosenbrock();
    Rosenbrock(Interface *u, int pop, int gen, float mut, int geno, float cross);
    struct chro
    {
        double x=13;
        double y=22 ;
        double fit = 20;
    };
    void InitialPopulation();
    void Fitness();
    bool isFinished();
    void Selection();
    void CrossOver();
    void Mutate();
    void replace();
    //void Elitism();
    void Best();
    bool Fitness_Sort(chro x, chro y);
    void Run();

private:
    Interface *ui;
    const int POPULATION_SIZE;
    const int GENERATION_NUMBER;
    const float MUTATION_RATE;
    const int GENOME;
    const float CROSSOVER_RATE;
    std::vector<double> *latitude = new std::vector<double>();
    std::vector<double> *longitude = new std::vector<double>();
    Random_Generator dice;
    std::vector<chro> population;
    std::vector<chro> middle;
    Rosenbrock::chro *minimum = new Rosenbrock::chro;
};



#endif // Rosenbrock_H
