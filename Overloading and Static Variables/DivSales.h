#ifndef DIVSALES_H_INCLUDED
#define DIVSALES_H_INCLUDED

#include<iostream>
using namespace std;

 class DivSales
 {
     private:
        int* quarterSales;
     public:
         static int totalSales; // Keeps track of total company sales (STATIC)
         DivSales(); // (CONSTRUCTOR)

         // Returns sales quarter (ACCESSOR)
         int returnsQuarterSales(int) const;

         // Sets sales quarter (MUTATOR)
         void setQuarterSales(int,int,int,int);
 };

#endif // DIVSALES_H_INCLUDED
