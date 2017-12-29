 #include "PString.h"

////////////////////////////////////////////////////////////////////////////////
// "PString.cpp" functions

 // Reverses the order of a string. E.G. spam becomes maps.
 string reverseString(string insertString)
 {
     const int SIZE = insertString.size();
     int i = 0, j = SIZE - 1;
     char temp;

     while(i < j)
     {
         temp = insertString[i];
         insertString[i] = insertString[j];
         insertString[j] = temp;
         i++;
         j--;
     }

     return insertString;

 }

////////////////////////////////////////////////////////////////////////////////
// Class Functions

 Pstring::Pstring(string insertString)
 {
     ourPString = insertString;
 }

 bool Pstring::isPalindrome() const
 {
     return(ourPString == reverseString(ourPString));
 }
