/*
 *	Overloading and Static Variables
 *
 *	Date Posted: 11/03/2017
 *	Language: C++
 *	Files: 3 cpp files, 2 header files
 *	Executable: Main.cpp
 *	Libraries: iostream
 */

 #include "DayOfYear.cpp" // Part 1
 #include "DivSales.cpp"  // Part 2

 void userInInt(int &); // Checks for correct input of an integer


 int main()
 {

///////////////////////////////////////////////////////////////////////////////
/// Part 1 Calendar

     for(int i = 0; i < 50; i++){cout << '/';}
     cout << "\n///Part 1\n\nCalendar\n\n";

     int i = 2;

     DayOfYear object1;

     // Testing static function
     DayOfYear::month = "January";

     // Setting day to i
     object1.setDay(object1.currentDay(i));
     cout << "Day 2 would be: "; object1.print();

     // Testing overloaded operator +
     object1 = object1 + 30;
     cout << "\nDay 32 would be: "; object1.print();

     // Testing overloaded operator -
     object1 = object1 - 4306;
     cout << "\nDay -4274 would be: "; object1.print();
     cout << endl << endl;

///////////////////////////////////////////////////////////////////////////////
/// Part 2 Division Sales

     for(int i = 0; i < 50; i++){cout << '/';}
     cout << "\n///Part 2\n\nDivision Sales\n\n";

     DivSales division_1, division_2, division_3,
              division_4, division_5, division_6;

     // Object pointer to point to all the different divisions
     DivSales* divisionPtr[6];

     divisionPtr[0] = &division_1;
     divisionPtr[1] = &division_2;
     divisionPtr[2] = &division_3;
     divisionPtr[3] = &division_4;
     divisionPtr[4] = &division_5;
     divisionPtr[5] = &division_6;



     // Variables for user input and temporary storage
     int userIn = 0, salesArray[4];

     cout << "Current Sales for company: " << DivSales::totalSales
          << endl;

     cout << "Please add division sales for all 6 divisions.\n\n";

     // We want to run 6 divisions 4 times, nested loop is a 6x4 = 24 loops
     for(int j = 0; j < 6; j++)
     {
         for(int i = 0; i < 4; i++)
         {
             cout << "Please enter division " << j + 1
                  << "'s sales for quarter "  << i + 1
                  << endl;
             userInInt(userIn);
             salesArray[i] = userIn;
         }

         // In the object we point to, access the setQuartersSales function
         divisionPtr[j]->setQuarterSales(salesArray[0],salesArray[1],
                                         salesArray[2],salesArray[3]);
     }

     cout << "Current Sales for company: " << DivSales::totalSales
          << endl;

     return 0;

 }

 // Checks for correct input of an integer
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
