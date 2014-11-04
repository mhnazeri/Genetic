#include "random_generator.h"
#include <random>
#include <time.h>

Random_Generator::Random_Generator(){srand(time_t(NULL));}

Random_Generator::~Random_Generator(){}

double Random_Generator::RandomDouble(double Min, double Max)
{
    double lower_bound = Min;
    double upper_bound = Max;
    std::uniform_real_distribution<double> unif(lower_bound,upper_bound);
    std::default_random_engine re;
    double random_double = unif(re);
    return random_double;
}

int Random_Generator::RandomInteger(int Min, int Max)
{
    int lower_bound = Min;
    int upper_bound = Max;
    std::uniform_int_distribution<int> unif(lower_bound,upper_bound);
    std::default_random_engine re;
    double random_int = unif(re);
    return random_int;
}
