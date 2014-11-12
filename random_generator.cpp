#include "random_generator.h"
#include <random>

Random_Generator::Random_Generator(){}

Random_Generator::~Random_Generator(){}

double Random_Generator::Double(double Min, double Max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(Min, Max);
    return dis(gen);
}

int Random_Generator::Integer(int Min, int Max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(Min, Max);
    return dis(gen);
}
