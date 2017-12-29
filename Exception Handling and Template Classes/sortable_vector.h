#ifndef SORTABLE_VECTOR_H_INCLUDED
#define SORTABLE_VECTOR_H_INCLUDED

#include "searchable_vector.cpp"

template <class T>
class SortableVector : public SimpleVector<T>
{
private:
    // Look up QUICK SORT ALGORITHM in Chapter 14, page 915 if you want to
    // know more but you can use whatever algorithm you prefer.
    int partitions(int, int, T); // (MUTATOR)
    void quickSort(int, int); // (MUTATOR)

public:
    // (CONSTRUCTOR)
    SortableVector(int s) : SimpleVector<T>(s)
    {}

    // (COPY CONSTRUCTOR)
    SortableVector(SortableVector &);

    // (COPY CONSTRUCTOR)
    SortableVector(SimpleVector<T> &obj) : SimpleVector<T>(obj)
    {}

    /********************************************************
    * BELOW ARE THE FUNCTIONS WE ADD TO COMPLETE ASSIGNMENT *
    *********************************************************
    */

    // int partitions(int, int, T); (PRIVATE)
    // void quickSort(int, int); (PRIVATE)
    void useQuickSort()
    {
        quickSort(0, this->sizeOfElements() - 1);
    }
};

#endif // SORTABLE_VECTOR_H_INCLUDED
