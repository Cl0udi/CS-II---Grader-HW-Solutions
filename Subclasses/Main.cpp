/*
 *	Subclasses
 *
 *	Date Posted: 11/08/2017
 *	Language: C++
 *	Files: 3 cpp files, 2 header files
 *	Executable: Main.cpp
 *	Libraries: iostream
 */

 #include "PString.cpp" // Part 1
 #include "EncryptableString.cpp" // Part 2

 int main()
 {
////////////////////////////////////////////////////////////////////////////////
// Part 1 - PString

     string userIn;

     cout << "Please enter a string to test if it is a Palindrome: ";
     getline(cin, userIn);

     // Create Object
     Pstring Object1(userIn);

     cout << "\nYour string reversed is: " << reverseString(userIn)
          << "\n\nYour string is ";
     if(!Object1.isPalindrome()){cout << "not ";}
     cout << "a Palindrome.\n\n";

////////////////////////////////////////////////////////////////////////////////
// Part 2 - EncryptableString

     cout << "Please enter a string so it can be encrypted: ";
     getline(cin, userIn);

     // Create Object
     EncryptableString Object2(userIn);
     Object2.encrypt();

     cout << "\nYour string encrypted is: ";
     Object2.printChoice(2);
     cout << endl << endl;

     cin.get();
     return 0;
 }
