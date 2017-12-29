#ifndef SEARCHABLE_VECTOR_H_INCLUDED
#define SEARCHABLE_VECTOR_H_INCLUDED

#include "simple_vector.cpp"

template <class T>
class SearchableVector : public SimpleVector<T>
{
public:
    // (CONSTRUCTOR)
    SearchableVector(int s) : SimpleVector<T>(s)
    {}

    // (COPY CONSTRUCTOR)
    SearchableVector(SearchableVector &);

    // (COPY CONSTRUCTOR)
    SearchableVector(SimpleVector<T> &obj) : SimpleVector<T>(obj)
    {}

    /********************************************************
    * BELOW ARE THE FUNCTIONS WE ADD TO COMPLETE ASSIGNMENT *
    *********************************************************
    */

    int findItem(T);
    int binarySearch(T);
};

#endif // SEARCHABLE_VECTOR_H_INCLUDED
