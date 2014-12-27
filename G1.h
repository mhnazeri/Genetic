#ifndef G1_H
#define G1_H
#include "interface.h"
#include "ui_interface.h"
#include "random_generator.h"
#include <vector>
#include <chrono>


class Interface;
class Random_Generator;
class G1
{
public:
//    G1();
    ~G1();
    G1(Interface *u, int pop, int gen, float mut, int geno, float cross);
    struct chro
    {
        double x=12;
        double y=20 ;
        double fit = 1;
    };
    void InitialPopulation();
    void Fitness();
    bool isFinished();
    void Selection();
    void CrossOver();
    void Mutate();
    void replace();
    void Elitism();
    void Best();
   // bool Fitness_Sort(chro x, chro y);
    void Run();

private:
    Interface *ui;
    const int POPULATION_SIZE;
    const int GENERATION_NUMBER;
    const float MUTATION_RATE;
    const int GENOME;
    const float CROSSOVER_RATE;
    std::vector<double> *mehary = new std::vector<double>();
    std::vector<double> *mehvarx = new std::vector<double>();
    Random_Generator dice;
    std::vector<chro> population;
    std::vector<chro> middle;
    G1::chro *minimum = new G1::chro;
};



#endif // G1_H
