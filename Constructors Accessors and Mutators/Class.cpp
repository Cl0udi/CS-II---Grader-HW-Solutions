 #include "HW_5.h"
 void userInInt(int &);

 //(CONSTRUCTOR)
 Array::Array()
 {
     a1 = NULL;
     l1 = 0;
     evens = 0;
     odds = 0;
 }

 //Custom (CONSTRUCTOR)
 Array::Array(const int SIZE)
 {
     //Dynamically allocate the array
     l1 = SIZE;
     a1 = new int[l1];
     evens = 0;
     odds = 0;

     //Initiate all the values in the array
     for(int i = 0; i < SIZE; i++)
     {
         cout << "\nWhat is the value of the " << i + 1 << " element?\n";
         userInInt(a1[i]);
     }
 }

 //Counts even and odd elements in a1 (MUTATOR)
 void Array::countEvenOdd()
 {
     for(int i = 0; i < l1; i++)
     {
         //If mod 2 equals 0 then it is even
         if((a1[i] % 2) == 0)
         {
             evens++;
         }
         else
            odds++;
     }
 }

 //Checks if evens is bigger than 5 (ACCESSOR)
 bool Array::ev5() const
 {
     if(evens > 5)
        return true;

     else
        return false;
 }

 //Checks if odds >= evens*2 (ACCESSOR)
 bool Array::od2ev() const
 {
     if(odds >= (evens * 2))
        return true;

     else
        return false;
 }

 //A function to check for correct input of int
 void userInInt(int & variable)
 {
     cin  >> variable;
     while(!cin)
     {
     cout << "That was no int! Please enter an int: \n";
     cin.clear();
     cin.ignore();
     cin >> variable;
     }
 }
