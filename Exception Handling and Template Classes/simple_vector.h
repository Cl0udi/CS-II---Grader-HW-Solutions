#ifndef SIMPLE_VECTOR_H_INCLUDED
#define SIMPLE_VECTOR_H_INCLUDED

#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
class SimpleVector
{
private:
    T *aptr;
    int arraySize;
    int elements; // To keep track of number of items in stack.
    void subError(); // Handles subscripts out of range.
public:
    SimpleVector(int); // (CONSTRUCTOR)
    SimpleVector(SimpleVector &); // (COPY CONSTRUCTOR)
    ~SimpleVector(); // (DESTRUCTOR)

    int sizeOfArray()// Returns size of array (ACCESSOR)
    {return arraySize;}

    void print() const; // Prints content of vector (ACCESSOR)
    T &operator[](int); // Overloads [] operator (OVERLOADER)

    /********************************************************
    * BELOW ARE THE FUNCTIONS WE ADD TO COMPLETE ASSIGNMENT *
    *********************************************************
    */
    int sizeOfElements()// Returns size of elements (ACCESSOR)
    {return elements;}
    void push(T); // Adds element to top of array (MUTATOR)
    void pop(T &); // Removes element from top of array (MUTATOR)
};

// Adds element to top of array (MUTATOR)
#endif // SIMPLE_VECTOR_H_INCLUDED
