#ifndef TIPS_H_INCLUDED
#define TIPS_H_INCLUDED

#include<iostream>
using namespace std;

 class Tips
 {
     private:
         double taxRate;
     public:
         Tips(); //(CONSTRUCTOR)
         Tips(double); //Custom (CONSTRUCTOR)
         void setTaxRate(double);//Changes value of taxRate (MUTATOR)
         double computeTip(double, double) const; //Returns tip amount (ACCESSOR)
 };

#endif // TIPS_H_INCLUDED
