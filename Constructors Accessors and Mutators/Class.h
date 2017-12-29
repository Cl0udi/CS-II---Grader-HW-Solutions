 #ifndef HW_5_H_INCLUDED
 #define HW_5_H_INCLUDED

 #include <iostream>
 using namespace std;

 class Array
 {
     private:
         int* a1;
         int l1;
         int evens;
         int odds;
     public:
         Array(); //(CONSTRUCTOR)
         Array(const int); //Custom (CONSTRUCTOR)
         void countEvenOdd(); //Counts even and odd elements in a1 (MUTATOR)
         bool ev5() const; //Checks if evens is bigger than 5 (ACCESSOR)
         bool od2ev() const;  //Checks if odds >= evens*2 (ACCESSOR)
 };

 #endif // HW_5_H_INCLUDED
