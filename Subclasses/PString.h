#ifndef PSTRING_H_INCLUDED
#define PSTRING_H_INCLUDED

 #include<iostream>
 using namespace std;

 // Inherit elements of class string into public elements of PString
 class Pstring : public string
 {
 private:
     string ourPString;

 public:

     // Imagine all of string class typed here

     // Custom (CONSTRUCTOR)
	 Pstring(string);

	 // Tells us if our string is a Palindrome (ACCESSOR)
	 bool isPalindrome() const;
 };

#endif // PSTRING_H_INCLUDED
