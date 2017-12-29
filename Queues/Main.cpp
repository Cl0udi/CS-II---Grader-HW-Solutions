/*
 *	Queues
 *	
 *	Date Posted: 11/25/2017
 *	Language: C++
 *	Files: 3 cpp files, 2 header files
 *	Executable: Main.cpp
 *	Libraries: iostream
 */

 #include "dynamic_queue.cpp"
 #include "dynamic_stack.cpp"

 int main()
 {
     // You can add a try and catch in main but typically we assume
     // you will have enough memory to create the first instance of the
     // object and that memory problems will occur when you are increasing
     // the size of the list within the rest of the program.

     DynamicQueue object1;
     DynamicStack object2;

     int var1 = 3, var2 = 4, var3 = 9, catchVal = 0;
     char var4 = '1', var5 = '7', var6 = '6', catchChar = '\0';

////////////////////////////////////////////////////////////////////////////////
/// Queue
     cout << " Entering values in Queue...\n"
          << " Queuing: " << var1 << endl;
     object1.enqueue(var1);

     cout << " Queuing: " << var2 << endl;
     object1.enqueue(var2);

     cout << " Queuing: " << var3 << endl;
     object1.enqueue(var3);

     cout << " Removing values from Queue...\n";
     object1.dequeue(catchVal);
     cout << " " << catchVal << " dequeued.\n";

     object1.dequeue(catchVal);
     cout << " " << catchVal << " dequeued.\n";

     object1.dequeue(catchVal);
     cout << " " << catchVal << " dequeued.\n";

     object1.dequeue(catchVal);
     cout << " " << catchVal << " dequeued.\n";

////////////////////////////////////////////////////////////////////////////////
/// Stack

     cout << " Entering values in Stack...\n"
          << " Pushing: " << var4 << endl;
     object2.push(var4);

     cout << " Pushing: " << var5 << endl;
     object2.push(var5);

     cout << " Pushing: " << var6 << endl;
     object2.push(var6);

     cout << " Removing values from Stack...\n";
     object2.pop(catchChar);
     cout << " " << catchChar << " popped.\n";

     object2.pop(catchChar);
     cout << " " << catchChar << " popped.\n";

     object2.pop(catchChar);
     cout << " " << catchChar << " popped.\n";



     cin.get();
     return 0;
 } // End of main.
