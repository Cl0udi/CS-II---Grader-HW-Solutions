#ifndef DYNAMIC_STACK_H_INCLUDED
#define DYNAMIC_STACK_H_INCLUDED

#include<iomanip>
#include<iostream>
using namespace std;

class DynamicStack
{
private:
    struct stackNode
    {
        char value;
        stackNode *next;
    };
    stackNode* top;
    stackNode* current;
    stackNode* bottom;
    bool isFull;

public:
    DynamicStack(); // (CONSTRUCTOR)

    void push(char);   // Adds value to top of stack (MUTATOR)
    void pop(char &); // Deletes value at top of stack (MUTATOR)
    bool isEmpty() const; // Tests for empty stack (ACCESSOR).
    void print();  // Prints values in stack bottom to top (ACCESSOR).
};

#endif // DYNAMIC_STACK_H_INCLUDED
