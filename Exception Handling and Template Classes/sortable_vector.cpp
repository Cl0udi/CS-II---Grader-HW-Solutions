 #include "sortable_vector.h"

 // Copy Constructor
 template <class T>
 SortableVector<T>::SortableVector(SortableVector &obj)
 : SimpleVector<T>(obj)
 {}

 /********************************************************
 * BELOW ARE THE FUNCTIONS WE ADD TO COMPLETE ASSIGNMENT *
 *********************************************************
 */

 // Using QuickSort Algorithm to sort the array. Although we have not seen
 // QuickSort, it is a very common algorithm that is good to learn.
 // I will include it here as an example, however any sorting algorithm will
 // do the job.
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
