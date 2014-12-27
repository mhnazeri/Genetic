#ifndef G2_H
#define G2_H
#include "interface.h"
#include "ui_interface.h"
#include "random_generator.h"
#include <vector>
#include <chrono>

class Interface;
class Random_Generator;
class G2
{
public:

    ~G2();
    G2(Interface *u, int pop, int gen, float mut, int geno, float cross);
    struct chro
    {
        double x=23;
        double y =33;
        double fit = -0.5231;
    };
    void InitialPopulation();
    void Fitness();
    bool isFinished();
    void Selection();
    void CrossOver();
    void Mutate();
    void Swap();

    void Best();

    void Run();

private:
    Interface *ui;
    const int POPULATION_SIZE;
    const int GENERATION_NUMBER;
    const float MUTATION_RATE;
    //const float ELITISM_RATE;
    const float CROSSOVER_RATE;
    const int GENOME;
    std::vector<double> *latitude = new std::vector<double>();
    std::vector<double> *longitude = new std::vector<double>();
    Random_Generator dice;
    std::vector<chro> population;
    std::vector<chro> middle;

    G2::chro *minimum = new G2::chro;
};


#endif // G2_H
