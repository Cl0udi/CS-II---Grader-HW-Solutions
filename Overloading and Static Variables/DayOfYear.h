#ifndef DAYOFYEAR_H_INCLUDED
#define DAYOFYEAR_H_INCLUDED

#include<iostream>
using namespace std;

 class DayOfYear
 {
     private:
        int day;
     public:
         static string month; // Keeps track of current month (STATIC)
         DayOfYear(); // (CONSTRUCTOR)
         DayOfYear(int); // Custom (CONSTRUCTOR)
         DayOfYear(string, int); // Custom (CONSTRUCTOR)

         void print() const; // Prints month then day in a line (ACCESSOR)
         string currentMonth(int) const; // Calculates current month (ACCESSOR)
         int currentDay(int) const; // Calculates current day (ACCESSOR)
         void setDay(int); // Sets value of day (MUTATOR)
         void setMonth(string); // Sets value of month (MUTATOR)

         // Overloads + operator (FRIEND)
         friend DayOfYear operator +(DayOfYear, int);

         // Overloads - operator (FRIEND)
         friend DayOfYear operator -(DayOfYear, int);
 };

#endif // DAYOFYEAR_H_INCLUDED
