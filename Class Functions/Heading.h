#ifndef HEADING_H_INCLUDED
#define HEADING_H_INCLUDED

#include<iostream>
#include<iomanip>//For setw in fourLinePrint
using namespace std;

 class Heading
 {
     private:
         string company;
         string report;
     public:
         Heading(); //(CONSTRUCTOR)
         Heading(string,string); //Custom (CONSTRUCTOR)
         void oneLinePrint() const; //Prints in one line format (ACCESSOR)
         void fourLinePrint() const; //Prints in four line format (ACCESSOR)
 };

#endif // HEADING_H_INCLUDED
