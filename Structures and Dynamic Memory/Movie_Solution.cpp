/*
	Structures and Dynamic Memory

	Date Posted: 10/22/2017
	Language: C++
	Files: 2 cpp files
	Executable: Circle_Solution.cpp and Movie_Solution.cpp
	Libraries: iostream

*/

#include <iostream>

using namespace std;

void userInInt(int&); //To check input of int
void bubbleSort(int arr[], const int SIZE); // Lets reuse this, why not?
void calcAverage(const int arr[], double&, const int SIZE);
void calcMode(const int arr[], double&, const int SIZE);


int main()
{

    int totalMovies, studentMovies;
    double average, median, mode;

    cout << "How many students are we surveying?\n";
    userInInt(totalMovies);

    int* ptr = new int[totalMovies];

    for(int i = 0; i < totalMovies; i++)
    {
        cout << "How many movies did student " << i + 1 << " see?\n";
        userInInt(ptr[i]);
    }

    //Sort array
    bubbleSort(ptr, totalMovies);

    //Calculate average, median and mode
    median = ptr[totalMovies/2];
    calcAverage(ptr, average, totalMovies);
    calcMode(ptr, mode, totalMovies);

    cout << "Median: " << median << endl
         << "Average: " << average << endl
         << "Mode: " << mode << endl;

    return 0;
}

void calcAverage(const int arr[], double& average, const int SIZE)
{
    double total = 0;

    for(int i = 0; i < SIZE; i++)
    {
        total += arr[i];
    }

    average = total / SIZE;
}

void calcMode(const int arr[], double& mode, const int SIZE)
{

    /*
        Array is sorted so this is really easy.
        Go once along the loop, count the number of repeated terms.
        Your mode is the number with most repeated term.
    */

    int repetitions = 1, mostRepetitions = 1;

    mode = arr[0];

    for (int i = 0; i < SIZE - 1; i++)
    {
        if ( arr[i] == arr[i+1] )
        {
            repetitions++;
            if ( repetitions > mostRepetitions )
            {
                mostRepetitions = repetitions;
                mode = arr[i];
            }
        } else
            repetitions = 1; //Reset repetitions.
    }
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

//A function to check for correct input of int
void userInInt(int& variable)
{
    cin  >> variable;
    while(!cin)
    {
    cout << "That was no int! Please enter an int: \n";
    cin.clear();
    cin.ignore();
    cin >> variable;
    }
}
