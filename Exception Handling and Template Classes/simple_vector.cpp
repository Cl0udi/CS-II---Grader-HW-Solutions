 #include "simple_vector.h"


 // Constructor for SimpleVector class. Sets the size of the array
 // and allocates memory for it.
 template <class T>
 SimpleVector<T>::SimpleVector(int s)
 {
     arraySize = s;\
     elements  = 0;
     aptr      = new T[s];

     for(int i = 0; i < arraySize; i++)
     {
         aptr[i]  = T();
         this->operator[](i) = 0;
     }
 }

 // Copy Constructor
 template <class T>
 SimpleVector<T>::SimpleVector(SimpleVector &obj)
 {
     arraySize = obj.arraySize;
     elements  = obj.elements;
     aptr      = new T[arraySize];

     for(int i = 0; i < arraySize; i++)
      {aptr[i] = obj[i];}
 }

 // Destructor
 template <class T>
 SimpleVector<T>::~SimpleVector()
 {
     if(arraySize > 0)
     {delete [] aptr;}
 }

 // Displays an error message and terminates the program when a
 // subscript is out of range.
 template <class T>
 void SimpleVector<T>::subError()
 {
     cout << " Error subscript out of range.\n";
     exit (0);
 }

 // Overloaded [] operator. The argument is a subscript. This function returns
 // a reference to the element in the array indexed by the subscript.
 template <class T>
 T &SimpleVector<T>::operator[](int sub)
 {
     if(sub < 0 || sub >= arraySize)
     {subError();}
     return aptr[sub];
 }

 // Prints all entries in array
 template <class T>
 void SimpleVector<T>::print() const
 {
     cout << " Items in array: ";

     for (int i = 0; i < arraySize; i++)
     {
         cout << aptr[i] << ", ";
     }

     cout << endl;
 }

 /********************************************************
 * BELOW ARE THE FUNCTIONS WE ADD TO COMPLETE ASSIGNMENT *
 *********************************************************
 */

 // We have an int ELEMENTS that checks what element of the array we are on.
 // It helps us treat the array like a stack. When elements is the size of
 // ARRAYSIZE then we cannot push any more items. Conversely, when ELEMENTS
 // is 0 then we can not pop any more items. We cannot delete the array
 // because it is not dynamic so we simply set the popped array elements to
 // 0.
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
