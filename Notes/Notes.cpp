HW4:

 

1) Use of new operator with structure.

struct Circle
{
    double radius;
    string color;
};

...

const int NUM = 10;

Circle *temp = new Circle[NUM];

 

HW5:

 

1) Dynamically allocating space for an array inside of a class.

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

...

 Array::Array(const int SIZE)
 {
     //Dynamically allocate the array
     l1 = SIZE;
     a1 = new int[l1];
     evens = 0;
     odds = 0;

     //Initiate all the values in the array
     for(int i = 0; i < SIZE; i++)
     {
         cout << "\nWhat is the value of the " << i + 1 << " element?\n";
         userInInt(a1[i]);
     }
 }

An array is made with a pointer. When you call element 4 of an array you are telling the compiler to return *(pointerToFirstElement + 3).

 

2) Use of .h files

 

#ifndef ARRAY_H //If not defined-->
#define ARRAY_H //-->Define it

//Class, struct, anything can go in here

#endif //End Definition

.h files are used to help organize code. The compiler does not know the difference between a .h and a .cpp file.

As long as both files are in the same folder, you can use #include "nameOfFile.extension" to write all the code that file contains in that same line as the #include.

 

General tips to save code:

 

1) Simplify output

cout << "Your array does ";
if(!fiveOrMore)
{cout << "not ";}
cout << "have 5 or more even numbers\n";

 

2) Boolean functions

 bool Array::ev5() const
 {
     if(evens > 5)
        return true;

     else
        return false;
 }

//Is the same as:

 bool Array::ev5() const
 {return(evens > 5);}
 
 

HW 6 Notes:

 

Not a lot to say. Most people did pretty well it was just very long. A lot of you did not loop the tip program.

Here is a quick menu idea for the next time. (There is a lot of ways of making a menu.)

 

     while(true)
     {
         cout << "\n\nwhat would you like to do?\n"
              << "1) Calculate Tip\n"
              << "2) Change Tax Rate\n"
              << "3) Exit\n";
        userInInt(choice);

        if(choice > 3 || choice <= 0)
        {cout << "That was not a menu choice!\n";}

        else if(choice == 3)
        {break;}

        else if(choice == 2)
        {
            cout << "Please enter new tax rate\n";
            userInDouble(taxRate);
            part3Obj1.setTaxRate(taxRate);
        }

        else if(choice == 1)
        {
            cout << "Please enter total bill\n";
            userInDouble(totalBill);
            cout << "Please enter tip percentage\n";
            userInDouble(tipRate);
            cout << "Tip amount: "
                 << part3Obj1.computeTip(totalBill, tipRate/100)
                 << endl;
        }

     }

 

HW 7 Notes:

 

The DayOfYear was more difficult than the DivSales one. Thing people had the most issues with was overloaded operators.

The easiest thing you can do to make the overloaded operator work is call the constructor. For those of you

that have the book the solution chapter starts in page 704 of edition 7.

 

 DayOfYear::DayOfYear(int insertDay)
 {
     month = numberToMonth(1);
     month = currentMonth(insertDay);
     day = currentDay(insertDay);
 }

...

 DayOfYear operator + (DayOfYear insertObject, int insertDay)
 {
     return DayOfYear(insertObject.day + insertDay);
 }

 

The full solution is in the resources tab. Also be careful with the special case of subtracting days and ending up in day 0!



H9 Notes:

 

1) On the copy constructor a lot of you just made your nodes point to the old list. This is bad because when

    you traverse your list you end up following the red lines and going back to the old list. You will never access

    any of the elements in the copied list if you do this because every element points to the old list. Worse you

    can end up mixing the information of both lists.

 

2) Recursive Search. A lot of people skipped it and it was easy points. All you need to do is have a function call itself.

    For example:

 

bool LinkedList::isMemberRecursive(double x, node* traverseNode) const
 {
     if(traverseNode)
     {
         if(traverseNode->data == x){return true;}
         return isMemberRecursive(x, traverseNode->next);
     }
     return false;
 }

 

H10 Notes:

 

1) Everyone did pretty well on creating a dynamic stack. The delimiter part was the big issue.

    The book did not offer a solution to it but the idea is as follows:

 

/************************************************************
  * Opening character = '(' , '[' , '{'                      *
  * Closing character = ')' , ']' , '}'                      *
  * We push everything that is not a closing character       *
  * Once we encounter a closing character we pop values      *
  * until we encounter the matching opening character.       *
  * If we encounter another closing character, an opening    *
  * character that does not match or the stack becomes       *
  * empty then the test has failed and we return false.      *
  * At the end we also check for stray opening characters    *
  * left in stack.                                           *
  ************************************************************
  */

The full solution was a little long but for anyone that wants to see it is posted on the resources tab.



HW11 Notes:

 

1) Main thing to learn was TRY/THROW/CATCH.

    TRY: does not do much. Helps you format where to send your THROWS and CATCHES. For example:

try{int *ptr = new int[10];}catch(bad_alloc){cout << "Error 1.\n";return;}
try{double *ptr = new int[10];}catch(bad_alloc){cout << "Error 2.\n";return;}

    is much better than:

try{int *ptr = new int[10]; double *ptr2 = new int[10];}catch(bad_alloc){cout << "Error 1.\n";return;}

    THROW: will send a variable down your code until reaches a return value.

                   If no return value is found then it will usually return your main function, replace your return 0 and end your program abruptly.

    CATCH: receives thrown values. Think of it as a function with the value you throw as the parameter.

 

In this assignment you needed to add checks like this one:

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

 

 

HW12 Notes:

 

1) A little challenging. Most of the code was in the book and just had to be copied down from chapters 16.1-16.4 of the 7th edition..

    Here are the push and pop functions:

 template <class T>
 void SimpleVector<T>::push(T item)
 {
     if(elements > arraySize - 1)
     {
         cout << " Sorry but array is full.\n";
     }
     else
     {
         cout << " Pushing: " << item << endl;
         this->operator[](elements) = item;
         elements++;
     }
 }

 template <class T>
 void SimpleVector<T>::pop(T &item)
 {
     if(elements <= 0)
     {
         cout << " Sorry but array is empty.\n";
     }
     else
     {
         item = this->operator[](elements - 1);
         cout << " Popping: " << item << endl;
         this->operator[](elements - 1) = 0;
         elements--;
     }
 }

 

2) For the sorting algorithm I used Quick Sort. You didn't need it in this course but it comes up later on so consider it a holiday present and feel free to save it as a reference:

 template <class T>
 int SortableVector<T>::partitions(int left, int right, T pivot)
 {
     T temp;

     while(left<=right)
     {
         while(this->operator[](left)  < pivot){left++;}
         while(this->operator[](right) > pivot){right--;}

         if(left <= right)
         {
             temp = this->operator[](left);
             this->operator[](left) = this->operator[](right);
             this->operator[](right) = temp;
             left++;
             right--;
         }

     }
     return left;
 }

 template <class T>
 void SortableVector<T>::quickSort(int left, int right)
 {
     if(left >= right) {return;} // Base Case

     int middle = (left+right)/2;
     T pivot = this->operator[](middle);
     int index = partitions(left,right, pivot);

     quickSort(left,index - 1);
     quickSort(index, right);
 }

 

3) Lastly, Binary Search was one of the first things we ever did in this course. Should be pretty straightforward:

 template<class T>
 int SearchableVector<T>::binarySearch(T item)
 {
     int bottom = 0;
     int top    = this->sizeOfElements() - 1;
     int middle = (top + bottom)/2;
     while(bottom <= top)
     {
         middle = (top + bottom)/2;

         if((this->operator[](middle)) == item)
        {return middle;}

        else if(item > (this->operator[](middle)))
        {bottom = ++middle;}

        else
        {top = --middle;}

     }
     return -1;
 }

If you see the solutions I wrote and have any questions, I would be happy to answer them.

PS: I also added a little Easter Egg in my last solution for those who run it.

Good luck on your finals everyone!
