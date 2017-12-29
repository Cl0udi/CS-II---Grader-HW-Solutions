 #include "dynamic_queue.h"

 DynamicQueue::DynamicQueue()
 {
     head = NULL;
     tail = NULL;
     isFull = false;
 }

 DynamicQueue::~DynamicQueue()
 {
     clearQueue();
 }

 // TRY will attempt to run any code contained in its brackets. The bad_alloc
 // CATCH will trigger if the NEW command fails to create a NEW QUEUENODE
 // object because the system runs out of memory. In reality, we could have
 // contained only the NEW command within the TRY block but it would have made
 // our code harder to read.
 void DynamicQueue::enqueue(int num)
 {
     if(isEmpty())
     {
         try
         {
             head = new QueueNode(num);
             tail = head;
             isFull = false;
         }
         catch(bad_alloc)
         {
             cout << "Exception caught: overflow\n";
             isFull = true;
         }
     }
     else
     {
         try
         {
             tail->next = new QueueNode(num);
             tail = tail->next;
             isFull = false;
         }
         catch(bad_alloc)
         {
             cout << "Exception caught: overflow\n";
             isFull = true;
         }
     }
 }

 // Just showing how to use the THROW command. This TRY and CATCH is not
 // doing anything particularly useful.
 void DynamicQueue::dequeue(int & num)
 {
     QueueNode *temp;

     try
     {
         if(isEmpty())
         {
             string a = "underflow";
             throw(a);
         }
     }

     catch(string error)
     {
         cout << " Exception caught: " << error << endl;
         num = -1;
         return;
     }

     num = head->value;
     temp = head;
     head = head->next;
     delete temp;

 }

 bool DynamicQueue::isEmpty() const
 {
     return (head == NULL);
 }

 // DEQUEUE until the list ISEMPTY
 void DynamicQueue::clearQueue()
 {
     int catchVal;

     while(!isEmpty())
     {
         dequeue(catchVal);
     }
 }
