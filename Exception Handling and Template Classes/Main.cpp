/*
 *	Exception Handling and Template Classes
 *	
 *	Date Posted: 11/27/2017
 *	Language: C++
 *	Files: 4 cpp files, 3 header files
 *	Executable: Main.cpp
 *	Libraries: iostream, cstdlib
 */

 #include "sortable_vector.cpp"

 int main()
 {
     const int SIZE = 6;
     int catchVal;
////////////////////////////////////////////////////////////////////////////////
/// Simple Vector

     SimpleVector<int> object1(SIZE);

     for(int i = 0; i < 29; i++)
     {cout << "*";}
     cout << "\n* PART 1: SIMPLE VECTOR     *\n\n";
     for(int i = 0; i < 29; i++)
     {cout << "*";}
     cout << endl;

     object1.push(4); // 1
     object1.push(2); // 2
     object1.push(1); // 3
     object1.push(3); // 4
     object1.push(5); // 5
     object1.push(6); // 6
     object1.print();

     //Copy to SORTABLE VECTOR
     SortableVector<int> object2(object1);

     object1.pop(catchVal); // 1
     object1.pop(catchVal); // 2
     object1.pop(catchVal); // 3
     object1.pop(catchVal); // 4
     object1.pop(catchVal); // 5
     object1.pop(catchVal); // 6
     object1.pop(catchVal); // 7->should signal that array is empty

     cout << endl << endl;

////////////////////////////////////////////////////////////////////////////////
/// Sortable Vector

     for(int i = 0; i < 29; i++)
     {cout << "*";}
     cout << "\n* PART 2: SORTABLE VECTOR   *\n\n";
     for(int i = 0; i < 29; i++)
     {cout << "*";}
     cout << endl;
     // Doing SORTABLE before SEARCHABLE because BINARY SEARCH only works if
     // the array is sorted.

     object2.print();
     cout << " Sorting array...\n";
     object2.useQuickSort();
     cout << " Array sorted.\n";
     object2.print();

     //Copy to SEARCHABLE VECTOR
     SearchableVector<int> object3(object2);

     cout << endl << endl;

////////////////////////////////////////////////////////////////////////////////
/// Searchable Vector

     for(int i = 0; i < 29; i++)
     {cout << "*";}
     cout << "\n* PART 3: SEARCHABLE VECTOR *\n\n";
     for(int i = 0; i < 29; i++)
     {cout << "*";}
     cout << endl;

     cout << "\n Looking for values in array. "
          << "If not found index will be '-1'.\n\n";
     int  search1 = 4;   // In array, should return 3.
     char search2 ='x'; // Should return -1 since array does not have chars

     cout << " Searching for '" <<  search1
          << "' using Linear Search Function...\n";
     catchVal = object3.findItem(search1); // In Array
     cout << " Index: " << catchVal << endl << endl;

     cout << " Searching for '" <<  search2
          << "' using Linear Search Function...\n";
     catchVal = object3.findItem(search2); // Not in Array
     cout << " Index: " << catchVal << endl << endl;

     cout << " Searching for '" <<  search1
          << "' using Binary Search Function...\n";
     catchVal = object3.binarySearch(search1); // Not in Array
     cout << " Index: " << catchVal << endl << endl;

     cout << " Searching for '" <<  search2
          << "' using Binary Search Function...\n";
     catchVal = object3.binarySearch(search2); // Not in Array
     cout << " Index: " << catchVal << endl << endl;

     cout << endl << endl;

     cout << " Good luck on your finals Bobcats!\n\n";

     cout << "            ____              \n"
          << "         .-\"  ' \"-.    __,  ,___,\n"
          << "        /.'.'A_'*`.\\  (--|__| _,,_ ,_ \n"
          << "       |:.*'/\\-\\. ':|   _|  |(_||_)|_)\\/\n"
          << "       |:.'.||\"|.'*:|  (        |  | _/\n"
          << "        \\:~^~^~^~^:/          __,  ,___,\n"
          << "         /`-....-'\\          (--|__| _ |' _| _,   ,\n"
          << "        /          \\           _|  |(_)||(_|(_|\\//_)\n"
          << "        `-.,____,.-'          (               _/\n";

     cin.get();
     return 0;
 } // End of main.
