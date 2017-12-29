 #include "LinkedList.h"

////////////////////////////////////////////////////////////////////////////////
// Class Functions

 LinkedList::LinkedList ()
 {
     head    = NULL;
     current = NULL;
 }

 LinkedList::LinkedList (const LinkedList& copiedList)
 {
     // Create a pointer to traverse the linked list we will be copying.
     node* traverseList = copiedList.head;

     // If the linked list we are copying has no head then traverseList
     // will point to NULL and fail this check.
     if(traverseList)
     {
         // Create a new node to be the head of our list.
         node* newNode = new node;

         // Copy the data in copiedList's head to our new node.
         newNode->data = copiedList.head->data;

         // Set our new node to head.
         head = newNode;

         // Also set current to our new node because we could be adding
         // more data to our list and if that happens we will be making
         // use of current down below.
         current = newNode;

         // Set our next pointer to null because we do not know if there
         // is more data to be copied.
         newNode->next = NULL;
     }

     // EXPLANATION OF WHILE LOOP:
     // While the node we have already copied has a next pointer that
     // points to another node and not to NULL.
     //
     // If it passes this check, that means that there are still elements
     // in copiedList that we must add to our new list.
     while(traverseList->next)
     {
         // Point to the next element we wish to copy.
         traverseList = traverseList->next;

         // Create a new node so that we can copy the the data into it.
         node* newNode = new node;

         // Copy the data in the node to our new node.
         newNode->data = traverseList->data;

         // Add to the end of our list
         current->next = newNode;

         // Set current to our last element
         current = newNode;

         // Set pointer at the end of list to NULL
         newNode->next = NULL;


    }
 }

 void LinkedList::add(double x)
 {
     // Create a new node so it can be added to the list.
     node* newNode = new node;

     // Copy our value x into it.
     newNode->data = x;

     // Check for a head. If it does not exist then simply make our new
     // node the head.
     if(!head)
     {
         head = newNode;
         newNode->next = NULL;
     }

     // Otherwise make our node the new head and make it point to the
     // previous head with it's next pointer
     else
     {
         newNode->next = head;
         head = newNode;
     }
 }

 bool LinkedList::isMember(double x) const
 {
     // Let us start looking in the head
     node* traverseNode = head;

     // If there is a head this will condition will be met and afterwards
     // we will reset current to the next node in the list.
     while(traverseNode)
     {
         // If the value matches the value in our current node return true
         if(traverseNode->data == x){return true;}

         traverseNode = traverseNode->next;
     }

     // If we traverse the whole list and do not find our value, return false
     return false;
 }

 bool LinkedList::isMemberRecursive(double x, node* traverseNode) const
 {
     // Same as above but we are just doing it with a recursive algorithm.
     // All recursive means is that the function calls itself.

     // You want to set traverse node equal to head the first time
     // you call this function.

     if(traverseNode)
     {
         if(traverseNode->data == x){return true;}

         // Calls the function again just this time with the next
         // node in the list
         return isMemberRecursive(x, traverseNode->next);
     }

     return false;
 }

 void LinkedList::print() const
 {
     // Temporary node pointing to the head.
     node* traverseNode = head;

     // To tell user what element of the list we are printing
     int i = 1;

     while(traverseNode)
     {
         cout << "Data in node " << i++ << ": " << traverseNode->data
              << endl;
         traverseNode = traverseNode->next;
     }
 }


