#ifndef DYNAMIC_QUEUE_H_INCLUDED
#define DYNAMIC_QUEUE_H_INCLUDED

#include<iomanip>
#include<iostream>
using namespace std;

class DynamicQueue
{
private:
    // We can use classes instead of structures for linked lists. Not needed for
    // this assignment. However, since this is how the books solves it,
    // I figured it might be useful.
    class QueueNode
    {
        friend class DynamicQueue;
        int value;
        QueueNode *next;
        QueueNode(int value1 = 0, QueueNode *next1 = NULL) // (CONSTRUCTOR)
        {
            value = value1;
            next = next1;
        }
    };
    // These track the front and rear of the queue
    QueueNode *head;
    QueueNode *tail;

    // Checks for a full list (VARIABLE)
    // Since list is dynamic, the only time it should return true is when we
    // run out of memory.
    bool isFull;
public:
    DynamicQueue();   // (CONSTRUCTOR)
    ~DynamicQueue(); // (DESTRUCTOR)

    void enqueue(int); // Adds value to the tail (MUTATOR)
    void dequeue(int &); // Deletes the head value (MUTATOR)
    void clearQueue(); // Dequeues every value in the list (MUTATOR)
    bool isEmpty() const; // Checks for an empty list (ACCESSOR)
};


#endif // DYNAMIC_QUEUE_H_INCLUDED
