/*
    Binary Search

    Date Posted: 10/06/2017
    Language: C++
    Files: 1 cpp file
    Executable: Bubble_Sort.cpp
    Libraries: iostream, cstdlib
    Largest Run Time <= O(N^2)

*/

#include <cstdlib> //For system("PAUSE>NUL"); (optional)
#include<iostream>

using namespace std;

int binarySearch(int searchArray[], const int SIZE, int val);
int linearSearch(int searchArray[], int val);
void bubbleSort(int arr[], const int SIZE);

int main()
{
    //initialize and sort the array manually

    const int SIZE                 = 10;
    int       lotteryNumbers[SIZE] = {85647, 26791, 26792, 33445, 55555,
                                      62483, 93121, 79422, 13579, 77777},
              luckyNumber          = 0,
              results              = 0;

    cout << "Please enter lottery number: \n";
    cin  >> luckyNumber;

    ///////////////////////////////////////////////////////////
    //Optional check for correct input, always a good habit.
    while(!cin)
    {
    cout << "That was no integer! Please enter an integer: \n";
    cin.clear();
    cin.ignore();
    cin >> luckyNumber;
    }
    //////////////////////////////////////////////////////////

    //Array does not need to be sorted for linearSearch
    cout <<"\n\nSearching for value using Linear Search.";
    results = linearSearch(lotteryNumbers, luckyNumber);

    //Displaying results a first time
    if(results == -1)
    {cout << "\n\nBetter luck next time!";}
    else
    {cout << "\n\nYou won the lottery!";}

    //Reset results once no longer used
    results = 0;

    //Calling Bubble Sort to organize array
    cout << "\n\nSorting array with bubble sort.";
    bubbleSort(lotteryNumbers, SIZE);


    //Calling Binary Search Function
    cout <<"\n\nSearching for value using Binary Search.";
    results = binarySearch(lotteryNumbers, SIZE, luckyNumber);

    //Displaying results a second time
    if(results == -1)
    {cout << "\n\nBetter luck next time!\n\n";}
    else
    {cout << "\n\nYou won the lottery!\n\n";}

    //To make screen output nicer, #include <cstdlib> needed
    system("PAUSE>NUL");
    return 0;
}

void bubbleSort(int arr[], const int SIZE)
{
    /*
        Initiate the variables:
        -Since we have a for loop we need 1 integer.
        -We need 1 additional integer for when we are switching values in the
         array
        -For bubble sort to work we need to go around the loop swapping terms
         whenever a smaller term is to the right of a larger term. The loops run
         until no terms are swapped for a full cycle. I will use 1 bool to mark
         whenever a change is made within a cycle.
    */

   int loop = 0, placeHolder = 0;
   bool changeInLoops = false;


   while(true)
   {
     //Always reset the break condition
     changeInLoops = false;
     for (loop = 0; loop < SIZE-1; loop++)
     {
        if (arr[loop] > arr[loop+1])
        {
            /*
                To swap values assign left value to a temporary variable. Then
                set left value equal to right value. Then set right value equal
                to the temporary variable
            */

            placeHolder = arr[loop];
            arr[loop] = arr[loop + 1];
            arr[loop + 1] = placeHolder;

            /*
                Changing bool to true means the loop will have to run again before
                it can break
            */

            changeInLoops = true;
        }
     }

     // If no two elements were swapped by inner loop, then break
     if(changeInLoops == false){break;}
   }
}

int linearSearch(int searchArray[], int val)
{
    int i = 0;

    /*
        Linear search just compares every single term starting from left to
        right and if it finds what it is looking for it returns a results
    */

    while(searchArray[i])//This will exit at the end of the array
    {
        if(searchArray[i] == val){return 0;}
        i++;
    }

    return -1;


}

int binarySearch(int searchArray[], const int ARRAYSIZE, int val)
{
    /*
    For this function you need a sorted array.
    I will create 3 variables, top, middle and bottom.
    Binary search compares the target value to the middle element of the array;
    if they are unequal, the half in which the target cannot lie is eliminated
    and the search continues on the remaining half until it is successful.
    If the search ends with the remaining half being empty, the target is
    not in the array.
    */

    int bottom = 0,
        top    = ARRAYSIZE - 1,     //To account for arrays starting at 0.
        middle = (top + bottom)/2;  //Bottom is 0 but this is basic principle.

    while(bottom <= top)
    {
        //Redefine middle every loop.
        middle = (top + bottom)/2;

        //Checks to see if middle value matches what we want
        if(searchArray[middle] == val)
        {return middle;}

        /*
        If value is bigger than middle then bottom half of array does not
        contain the value. You get rid of it by making middle the new bottom.
        You then recalculate middle to run the loop again so you can keep
        searching for the value.
        */

        else if(val > searchArray[middle])
        {bottom = ++middle;}

        /*
        Same as before we are just getting rid of the top half this time by
        assigning middle as the new top.
        */

        else
        {top = --middle;}
    }

    /*
    If value is not in array, the last loop would have bottom be equal to
    or more than top. If that happens we return a negative number.
    */

    return -1;
}
