 #include "Population.h"

 Population::Population()
 {
     population = 2;
     annualBirths  = 0;
     annualDeaths = 0;
 }

 Population::Population(double a, double b, double c)
 {
     if(a <= 2){population = 2;}
     else population = a;

     if(b <= 0){annualBirths = 0;}
     else annualBirths = b;

     if(c <= 0){annualDeaths = 0;}
     else annualDeaths = c;
 }

 void Population::setPopulation(double a)
 {
    population = a;
 }

 void Population::setAnnualBirths(double a)
 {
     annualBirths = a;
 }

 void Population::setAnnualDeaths(double a)
 {
     annualDeaths = a;
 }

 double Population::birthRate() const
 {
     return(annualBirths/population);
 }

 double Population::deathRate() const
 {
     return(annualDeaths/population);
 }






