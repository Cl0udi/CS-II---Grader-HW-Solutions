 #include "dynamic_stack.h"

 // (CONSTRUCTOR)
 DynamicStack::DynamicStack()
 {top = NULL; current = NULL; bottom = NULL; isFull = false;}

 // Creates a new object, stores insertValue in it. If there is no bottom
 // then the new element becomes the bottom of the stack; else it just becomes
 // the new top
 void DynamicStack::push(char insertVal)
 {

     // If we don't have enough memory to create a new node just return
     // and don't waste runtime.
     try{
     stackNode* tempNode = new stackNode;
     }
     catch(bad_alloc)
     {
         cout << "Exception caught: overflow\n";
         return;
     }

     stackNode* tempNode = new stackNode;
     tempNode->value = insertVal;
     tempNode->next = NULL;

     if(!bottom)
     {bottom = tempNode; top = tempNode;}

     else
     {
         top->next = tempNode;
         top = tempNode;
     }

 }

 // Checks if stack is empty.
 // Else it assigns top->value to returnVal, makes the element under top the
 // new top and deletes the old top.
 void DynamicStack::pop(char& returnVal)
 {
     returnVal = '\0';

     if(isEmpty())
     {cout << " Stack is empty.\n";}

     else if(!bottom->next)
     {
         returnVal = top->value;
         top = NULL;
         current = NULL;
         bottom = NULL;
     }

     else
     {
         returnVal = top->value;
         current = bottom;

         while(current)
         {
             if(current->next == top){break;}
             else current = current->next;
         }
         top = current;
         current = current->next;
         top->next = NULL;
         delete current;
     }
 }

 // Checks for values in stack
 bool DynamicStack::isEmpty() const
 {return(!bottom);}

 // Displays all values in stack from bottom to top.
 void DynamicStack::print()
 {
     current = bottom;
     cout << " Displaying stack elements bottom to top:\n";

     while(current)
     {
         cout << current->value;
         current = current->next;
     }
 }
