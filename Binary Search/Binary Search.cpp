/*
 *    Binary Search
 *    
 *    Date Posted: 09/29/2017
 *    Language: C++
 *    Files: 1 cpp file
 *    Executable: Binary_Search.cpp
 *    Libraries: iostream, cstdlib
 *    Largest Run Time <= O(log(N))
 *
 */

#include <cstdlib> //For system("PAUSE>NUL"); (optional)
#include<iostream>

using namespace std;

int binarySearch(int searchArray[], const int arraySize, int account);

int main()
{
    //initialize and sort the array manually

    int const SIZE = 18;
    int accounts[SIZE] = {1005231, 1250255, 1302850, 3852085, 4520125, 4562555,
                         4581002, 5050552, 5552012, 5658845, 6545231, 7576651,
                         7825877, 7881200, 7895122, 8080152, 8451277, 8777541};
    int account = 0, results = 0;

    cout << "Please enter account number: \n";
    cin  >> account;

    ///////////////////////////////////////////////////////////
    //Optional check for correct input, always a good habit.
    while(!cin)
    {
    cout << "That was no integer! Please enter an integer: \n";
    cin.clear();
    cin.ignore();
    cin >> account;
    }
    //////////////////////////////////////////////////////////

    //Calling Binary Search Function
    results = binarySearch(accounts, SIZE, account);

    if(results == -1)
    {cout << "\n\nAccount not found.\n\n";}
    else
    {cout << "\nAccount number: " << results + 1;}

    //To make screen output nicer, #include <cstdlib> needed
    system("PAUSE>NUL");
    return 0;
}

int binarySearch(int searchArray[], const int ARRAYSIZE, int account)
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

        //Checks to see if middle value matches account we want
        if(searchArray[middle] == account)
        {return middle;}

        /*
        If value is bigger than middle then bottom half of array does not
        contain the value. You get rid of it by making middle the new bottom.
        You then recalculate middle to run the loop again so you can keep
        searching for the value.
        */
        else if(account > searchArray[middle])
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
