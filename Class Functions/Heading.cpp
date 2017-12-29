 #include "Heading.h"

 Heading::Heading()
 {
     company = "ABS Industries";
     report  = "Report";
 }

 Heading::Heading(string a, string b)
 {
     company = a;
     report  = b;
 }

 void Heading::oneLinePrint() const
 {
     cout << company << " " << report;
 }

 void Heading::fourLinePrint() const
 {
     //50 of these: *
     for(int i = 0; i <50; i++)
     {cout << "*";}

     /*

        I'm sure theres many ways to do this, I did is the following:
        -Top and bottom have 50 * characters
        -The middle is at a length of 25 characters
        -Tricky part: take that middle point, add half the length of your
         string to it and output the last character of your string to that new
         point. That way the middle of your string lines of with the 25
         character point.

     */

     cout << endl
          << fixed << setw(25 + (company.length()/2)) << company
          << endl
          << fixed << setw(25 + (report.length()/2)) << report
          << endl;

     for(int i = 0; i <50; i++)
     {cout << "*";}
 }
