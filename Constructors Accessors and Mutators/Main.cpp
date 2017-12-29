/*
 *	Constructors, Accessors and Mutators
 *
 *	Date Posted: 10/25/2017
 *	Language: C++
 *	Files: 2 cpp files, 1 header file
 *	Executable: Main.cpp
 *	Libraries: iostream
 *
 */

 #include "HW_5.cpp"

 int main()
 {
     int arrSize = 0;
     bool fiveOrMore = false, oddsDoubleEvens = false;

     cout << "What is the size of your array?\n";
     userInInt(arrSize);

     //Create our object
     Array dog(arrSize);

     //Call its public functions
     dog.countEvenOdd(); //Counts even and odd elements in a1 (MUTATOR)
     fiveOrMore = dog.ev5(); //Checks if evens is bigger than 5 (ACCESSOR)
     oddsDoubleEvens = dog.od2ev(); //Checks if odds >= evens*2 (ACCESSOR)

     //Easy output trick
     cout << "Your array does ";
     if(!fiveOrMore)
    {cout << "not ";}
     cout << "have more than 5 even numbers\n";

     cout << "Your array has ";
     if(!oddsDoubleEvens)
    {cout << "not ";}
     cout << "double or more odd elements compared to even elements.\n";

     cin.get();
     return 0;
 }
