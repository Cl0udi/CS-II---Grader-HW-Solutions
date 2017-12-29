/*
	Structures and Dynamic Memory

	Date Posted: 10/22/2017
	Language: C++
	Files: 2 cpp files
	Executable: Circle_Solution.cpp and Movie_Solution.cpp
	Libraries: iostream, math

*/

#include <iostream>
#include <math.h>

using namespace std;

//Typically structure is defined in a separate file but we will get to that
struct Circle
{
    double radius;
    string color;
};

double circleFunction(const int); //Adds circles to calculate total area
int userInInt(); //To check input of int
double userInDouble(); //To check input of double


int main()
{

    int circles = 0;
    double area = 0;

    cout << "How many circles are we adding?\n";
    circles = userInInt();

    area = circleFunction(circles);

    cout << "\nTotal area is: " << area;


    return 0;
}

double circleFunction(const int NUM)
{
    /*
        A little confusing at first.
        First create a Circle structure pointer.
        Then at that address allocate space for an array of Circle structures.
    */

    Circle *temp = new Circle[NUM];

    /*
        Area of a circle is (pi)r^2.
        Area of n circles is (pi)(r1)^2 + (pi)(r2)^2 + ... + (pi)(rn)^2
        Factor out (pi) --> (pi)[ (r1)^2 + (r2)^2 + ... + (rn)^2 ]
        We can simply add our r values squared and multiply them by pi at the
        end. This is not necessary to receive full credit!
    */

    double radiusSums = 0;

    //Collect all data from user
    for(int i = 0; i < NUM; i++)
    {
        //Store value in structure, we have NUM structures so we must
        //repeat this NUM times --> O(N)
        cout << "What is radius of circle " << i + 1 << "?\n";
        temp[i].radius = userInDouble();

        //Take advantage of for loop and calculate the squared radius sum
        radiusSums += (temp[i].radius * temp[i].radius);
    }

    //M_PI defined in math.h
    return (radiusSums * M_PI);
}

//A function to check for correct input of double
double userInDouble()
{
    double variable;

    cin  >> variable;
    while(!cin)
    {
    cout << "That was no double! Please enter an double: \n";
    cin.clear();
    cin.ignore();
    cin >> variable;
    }

    return variable;
}

//A function to check for correct input of int
int userInInt()
{
    int variable;

    cin  >> variable;
    while(!cin)
    {
    cout << "That was no int! Please enter an int: \n";
    cin.clear();
    cin.ignore();
    cin >> variable;
    }

    return variable;
}
