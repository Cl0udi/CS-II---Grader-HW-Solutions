#include "Tips.h"

 Tips::Tips()
 {
     taxRate = 0.065;

 }

 Tips::Tips(double a)
 {
     if(a <= 0){taxRate = 0.065;}
     else taxRate = a;
 }

 void Tips::setTaxRate(double a)
 {
     if(a <= 0)
    {cout << "Tax rate too small, set to default\n"; taxRate = 0.065;}
     else taxRate = a;
 }

 double Tips::computeTip(double totalBill, double tipRate) const
 {
     if(totalBill <= 0)
     {
         cout << "\nBill must be larger than 0\n"; return 0;
     }

     if(tipRate <= 0)
     {
         cout << "\nTip Rate must be larger than 0\n"; return 0;
     }

     totalBill += totalBill*taxRate;

     return(totalBill * tipRate);

 }
