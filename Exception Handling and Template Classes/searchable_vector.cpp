 #include "searchable_vector.h"

 // Copy Constructor
 template <class T>
 SearchableVector<T>::SearchableVector(SearchableVector &obj)
 : SimpleVector<T>(obj)
 {}

 // Search for T type object in array.
 template<class T>
 int SearchableVector<T>::findItem(T item)
 {
     for(int i = 0; i < this->sizeOfArray();i++)
     {
         if(this->operator[](i) == item)
         {
             return i;
         }
     }
     return -1;
 }

 /********************************************************
 * BELOW ARE THE FUNCTIONS WE ADD TO COMPLETE ASSIGNMENT *
 *********************************************************
 */

 // Blast from the past. Back to HW2 for this one.
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
