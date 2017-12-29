/*
 *	Constructors Accessors and Mutators
 *
 *	Date Posted: 11/12/2017
 *	Language: C++
 *	Files: 2 cpp files, 1 header file
 *	Executable: Main.cpp
 *	Libraries: iostream
 */

 #include "LinkedList.cpp"

 void userInDouble(double &); // Checks for correct input of an integer

 int main()
 {
     double userIn = 0.0;
     LinkedList Object1;

     cout << "Please enter a number to add to list: ";
     userInDouble(userIn);
     Object1.add(userIn);
     cout << "Number added.\n";

     cout << "Please enter a number to add to list: ";
     userInDouble(userIn);
     Object1.add(userIn);
     cout << "Number added.\n";

     cout << "Please enter a number to add to list: ";
     userInDouble(userIn);
     Object1.add(userIn);
     cout << "Number added.\n\n";

     cout << "Displaying list: \n";
     Object1.print();
     cout << "List displayed.\n\n";

     cout << "Copying data to new list and displaying: \n";
     LinkedList Object2(Object1);
     Object2.print();
     cout << "List copied and displayed.\n\n";

     cout << "Search for number in list: \n";
     userInDouble(userIn);
     cout << "Number is ";
     if(!Object2.isMember(userIn)){cout << "not ";}
     cout << "in list.\n\n";

     cout << "Search for number in list using recursive algorithm: \n";
     userInDouble(userIn);
     cout << "Number is ";
     if(!Object1.isMemberRecursive(userIn, Object2.head)){cout << "not ";}
     cout << "in list.\n\n";

     cin.get();
     return 0;
 } // End of main.

 // Checks for correct input of an double
 void userInDouble(double & variable)
 {
     cin  >> variable;
     while(!cin)
     {
     cout << "That was not a double! Please enter an double: \n";
     cin.clear();
     cin.ignore();
     cin >> variable;
     }
 }
