 #include "dynamic_stack.h"

 // (CONSTRUCTOR)
 DynamicStack::DynamicStack()
 {top = NULL; current = NULL; bottom = NULL;}

 // Creates a new object, stores insertValue in it. If there is no bottom
 // then the new element becomes the bottom of the stack; else it just becomes
 // the new top
 void DynamicStack::push(char insertVal)
 {
     stackNode* tempNode = new stackNode;
     tempNode->value = insertVal;
     tempNode->next = NULL;

     cout << " Pushing: " << insertVal << endl;

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
         cout << " Popping: " << top->value << endl;
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
         cout << " Popping: " << current->value << endl;
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
