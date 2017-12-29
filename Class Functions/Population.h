#ifndef POPULATION_H_INCLUDED
#define POPULATION_H_INCLUDED

#include<iostream>
using namespace std;

 class Population
 {
     private:
         double population;
         double annualBirths;
         double annualDeaths;
     public:
         Population(); //(CONSTRUCTOR)
         Population(double,double,double); //Custom (CONSTRUCTOR)
         void setPopulation(double);//Changes value of population (MUTATOR)
         void setAnnualBirths(double);//Changes value of annualBirths (MUTATOR)
         void setAnnualDeaths(double);//Changes value of annualDeaths (MUTATOR)
         double birthRate() const; //Returns Birth Rate (ACCESSOR)
         double deathRate() const; //Returns Death Rate (ACCESSOR)
 };

#endif // POPULATION_H_INCLUDED
