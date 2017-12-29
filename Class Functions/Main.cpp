/*
 *	Class Functions
 *
 *	Date Posted: 11/03/2017
 *	Language: C++
 *	Files: 4 cpp files, 3 header file
 *	Executable: Main.cpp
 *	Libraries: iostream, iomanip
 *
 */

 #include "Heading.cpp"
 #include "Population.cpp"
 #include "Tips.cpp"

 void userInDouble(double &);
 void userInInt(int &);

 int main()
 {

///////////////////////////////////////////////////////////////////////////////
///Part 1 Company Heading

     for(int i = 0; i < 50; i++){cout << '/';}
     cout << "\n///Part 1\n\nCompany Heading";

     Heading part1Obj1;
     Heading part1Obj2("Wayne Enterprises", "Human Resources");

     cout << "\n\n1 line print:\n\n";
     part1Obj1.oneLinePrint();

     cout << "\n\n4 line print:\n\n";
     part1Obj2.fourLinePrint();
     cout << endl << endl;

///////////////////////////////////////////////////////////////////////////////
///Part 2 Population Rates

     for(int i = 0; i < 50; i++){cout << '/';}
     cout << "\n///Part 2\n\nPopulation Rates";

     Population part2Obj1;
     Population part2Obj2(100000, 8000, 6000);

     part2Obj1.setPopulation(100000);
     part2Obj1.setAnnualBirths(8000);
     part2Obj1.setAnnualDeaths(6000);

     //part2Obj1 should have same values as part2Obj2
     //Test it

     cout << fixed << setprecision(2)
          << "\n\nObject 1 Birth Rate: " << part2Obj1.birthRate()
          <<   "\nObject 2 Birth Rate: " << part2Obj2.birthRate()
          <<   "\nObject 1 Death Rate: " << part2Obj1.deathRate()
          <<   "\nObject 2 Death Rate: " << part2Obj2.deathRate()
          << endl << endl;

///////////////////////////////////////////////////////////////////////////////
///Part 3 Gratuity Calculator

     for(int i = 0; i < 50; i++){cout << '/';}
     cout << "\n///Part 3\n\nGratuity Calculator";

     Tips part3Obj1;
     int choice = 0;
     double totalBill = 0, tipRate = 0, taxRate = 0;

     while(true)
     {
         cout << "\n\nwhat would you like to do?\n"
              << "1) Calculate Tip\n"
              << "2) Change Tax Rate\n"
              << "3) Exit\n";
        userInInt(choice);

        if(choice > 3 || choice <= 0)
        {cout << "That was not a menu choice!\n";}

        else if(choice == 3)
        {break;}

        else if(choice == 2)
        {
            cout << "Please enter new tax rate\n";
            userInDouble(taxRate);
            part3Obj1.setTaxRate(taxRate);
        }

        else if(choice == 1)
        {
            cout << "Please enter total bill\n";
            userInDouble(totalBill);
            cout << "Please enter tip percentage\n";
            userInDouble(tipRate);
            cout << "Tip amount: "
                 << part3Obj1.computeTip(totalBill, tipRate/100)
                 << endl;
        }

     }

     cout << "\nGoodbye!\n";

     cin.get();
     return 0;
 }

 void userInInt(int & variable)
 {
     cin  >> variable;
     while(!cin)
     {
     cout << "That was not an int! Please enter an int: \n";
     cin.clear();
     cin.ignore();
     cin >> variable;
     }
 }

 void userInDouble(double & variable)
 {
     cin  >> variable;
     while(!cin)
     {
     cout << "That was not a double! Please enter a double: \n";
     cin.clear();
     cin.ignore();
     cin >> variable;
     }
 }
