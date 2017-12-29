#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

 #include<iostream>
 using namespace std;

 class LinkedList
 {
 public:

     /*
        Structure node stores a double (data) and a node pointer (next)
        that points to another structure of type [node].
        A little confusing at first. Just think of it as a double with a
        pointer to the next double. If the next double does not exist,
        the pointer points to NULL.
        You can also use a (previous) pointer to point to the element
        before it but we will leave that for another day.
     */

     struct node
     {
         double data;
         node* next;

     };

     // We use (head) and (current) pointers to know where to start and
     // where we are in the list.
     node* head;
     node* current;

     LinkedList ();// (CONSTRUCTOR)
     LinkedList (const LinkedList&);// Copy (CONSTRUCTOR)

     // Adds data to the beginning of the list (MUTATOR)
     void add(double x);

     // Checks for a data value in list (ACCESSOR)
     bool isMember(double x) const;

     // Checks for a data value in list with a recursive algorithm (ACCESSOR)
     bool isMemberRecursive(double x, node*) const;

     // Prints all data in list (ACCESSOR)
     void print() const;
 };

#endif // LINKEDLIST_H_INCLUDED
