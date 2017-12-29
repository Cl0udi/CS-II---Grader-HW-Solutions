 #include "DivSales.h"

 //Initialize Static Variable

 int DivSales::totalSales = 0;

 // Dynamically allocate our integer array,
 // in real world this would probably be a double
 DivSales::DivSales()
 {
     quarterSales = new int[4];

 }

 // Access element 0 - 3 in array
 int DivSales::returnsQuarterSales(int quarter) const
 {
     if(quarter < 0 || quarter > 3){return -1;}

     return quarterSales[quarter];
 }

 void DivSales::setQuarterSales(int q1,int q2,int q3,int q4)
 {
     // Store values in array
     quarterSales[0] = q1;
     quarterSales[1] = q2;
     quarterSales[2] = q3;
     quarterSales[3] = q4;

     // Add values to totalSales
     totalSales = totalSales + q1 + q2 + q3 + q4;
 }
