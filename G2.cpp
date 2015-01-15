
#include "G2.h"
#include "interface.h"
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
//#include<stdlib.h>
using std::string;
using std::stold;
using std::fmod;
using std::abs;

G2::~G2()
{
    delete latitude;
    delete longitude;
}

G2::G2(Interface *u, int pop, int gen, float mut, int geno, float cross) :
    ui(u), POPULATION_SIZE(pop), GENERATION_NUMBER(gen), MUTATION_RATE(mut),GENOME(geno), CROSSOVER_RATE(cross)
{
    minimum->fit = -0.5231;
}


void G2::Run()
{
        InitialPopulation();


            Fitness();
            for(int i=1 ; i<= GENERATION_NUMBER ; i++)
            {
            Selection();
            CrossOver();
            Mutate();
            Swap();
        Fitness();
        Best();


        ui->ui->text_answer->setText("Latitude = " + QString::number(minimum->y) + " , Longitude = " + QString::number(minimum->x));
        std::cout << "Latitude = " + QString::number(minimum->y).toStdString() + " , Longitude = " + QString::number(minimum->x).toStdString() << std::endl;
        std::vector<double> la;
        std::vector<double> lo;
        la.push_back(minimum->y);
        lo.push_back(minimum->x);
        ui->Plot(lo, la, Qt::blue, QCPScatterStyle::ssCrossSquare, QCPGraph::lsNone, 5, 5, "Longitude", "Latitude",1 , 100, 1, 100, 20);

}
}

void G2::InitialPopulation()
{

    double random ;
    random =dice.Double( 1,2000);
    double POPULATION_SIZE=random;
    for(int i = 0; i < POPULATION_SIZE; i++)
    {
        chro citizen;
        double random;
        random =dice.Double(1, 1000);
        citizen.x = random ;
        random=dice.Double(1, 1000);
        citizen.y = random;



        citizen.fit =-0.5231;
        population.push_back(citizen);
    }



}

void  G2::Fitness()
{
    double fitness = 0.0;
    chro * citizen = new chro;
    for(int i = 0; i < POPULATION_SIZE; i++)
    {
            fitness=(0.5+(sin(pow(sqrt(pow(citizen->x ,2)+pow(citizen->y ,2)) ,2))/(1+(0.1*(pow(citizen->x ,2)+pow(citizen->y ,2))))));
        citizen->fit = fitness;
        fitness = 0.0;
    }
    citizen = nullptr;
    delete citizen;
}




bool  G2::isFinished()
{
    return true;
}

void  G2::Selection()
{
    chro chro1, chro2;
    chro selected;
    for(int i = 0; i < POPULATION_SIZE; i++)
    {
        chro1 = population[dice.Integer(0,POPULATION_SIZE)];
        chro2 = population[dice.Integer(0,POPULATION_SIZE)];

        if(chro1.fit < chro2.fit)
        {
                selected.fit = chro1.fit;
                selected.x = chro1.x;
                selected.y = chro1.y;
            }else{
                selected.fit = chro2.fit;
                selected.x = chro2.x;
                selected.y = chro2.y;
            }

        middle.push_back(selected);
    }
}





void  G2::CrossOver()
{

    chro temp1;
    chro temp2;
    chro temp3;
    chro temp4;
    for(int i = 0; i < POPULATION_SIZE; i++)
    {
        if(dice.Double(0,1) <= CROSSOVER_RATE)
        {
            temp1= middle[i];
            temp2 = middle[i+1];
            temp3.x = (temp1.x + temp2.x);
            temp3.y = (temp1.y + temp2.y);
            temp4.x =abs(temp1.x - temp2.x);
            temp4.y = abs(temp1.y - temp2.y);
            middle[i]=temp3;
            middle[i+1] = temp4;
        }
    }
}



void  G2::Mutate()
{ chro *citizen;
    double random;
    for(int i = 0; i <POPULATION_SIZE ; i++)
    {
        if( dice.Double(1,6) < MUTATION_RATE)
        {
            random = dice.Double(0,fmod(POPULATION_SIZE ,2) );
            citizen = &middle[i];
            if((citizen->x + random > 100) &&  (citizen->x <1))
            {
                    citizen->x = fmod((citizen->x + random), 100.0) + 1;
            }else{
                citizen->x = citizen->x + random;
            }
            citizen->y=citizen->y;
        }
    }
    citizen = nullptr;
    delete citizen;


}

void  G2::Swap()
{

    chro* temp;
    chro mid;
    for(int i = 0; i < POPULATION_SIZE; i++)
    {
        temp = &population[i];
        mid = middle[i];
        if(mid.fit<=temp->fit)
    {
        temp->x = mid.x;
        temp->y = mid.y;
        temp->fit = mid.fit;
    }
    }
    temp = nullptr;
    delete temp;

}



void  G2::Best()
{
 chro temp;
    chro min;
    for(int i = 0; i < POPULATION_SIZE; i++)
    {
        temp = population[i];
        if(min.fit > temp.fit)
        {
            min.fit = temp.fit;
            min.x = temp.x;
            min.y = temp.y;
        }
        if(minimum->fit > temp.fit)
        {
            minimum->fit = temp.fit;
            minimum->x = temp.x;
            minimum->y = temp.y;
        }
    }
}


