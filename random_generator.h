#ifndef RANDOM_GENERATOR_H
#define RANDOM_GENERATOR_H

class Random_Generator
{
public:
    Random_Generator();
    ~Random_Generator();
    double Double(double Min, double Max);
    int Integer(int Min, int Max);
};

#endif // RANDOM_GENERATOR_H
