#ifndef ENCRYPTABLESTRING_H_INCLUDED
#define ENCRYPTABLESTRING_H_INCLUDED

 #include<iostream>
 using namespace std;

 // Inherit elements of class string into public elements of EncryptableString
 class EncryptableString : public string
 {
 private:
     string noEncryption;
     string encrypted;

 public:

     // Imagine all of string class typed here

     // Custom (CONSTRUCTOR)
	 EncryptableString(string);

	 // Encrypts noEncryption and stores in encrypted (MUTATOR)
	 void encrypt();

	 // Prints either encrypted or noEncryption string (ACCESSOR)
	 void printChoice(int) const;
 };

#endif // ENCRYPTABLESTRING_H_INCLUDED
