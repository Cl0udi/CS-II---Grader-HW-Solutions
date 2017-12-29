 #include "EncryptableString.h"

////////////////////////////////////////////////////////////////////////////////
// Class Functions

 // Not much to say these are pretty straight forward.
 // A constructor, a print function with the option of printing
 // the encrypted and non encrypted string and the encrypt function.


 EncryptableString::EncryptableString(string insertString)
 {
     noEncryption = insertString;
     encrypted = "Not yet encrypted\n";
 }

 void EncryptableString::printChoice(int choice) const
 {
     if(choice == 1){cout << noEncryption;}
     else if(choice == 2){cout << encrypted;}
     else{cout << "Non-valid selection in print()\n";}
 }

 void EncryptableString::encrypt()
 {
     // STL's size() function returns the number of characters in the string.
     const int SIZE = noEncryption.size();
     int i = 0;

     // Make encrypted an array of SIZE elements with blank chars
     encrypted = "";
     for(int j = 0; j < SIZE; j++){encrypted += " ";}

     while(i < SIZE)
     {
         // If we get to Z or z circle back to A or a
         if(noEncryption[i] == 'Z'){encrypted[i] = 'A';}
         else if(noEncryption[i] == 'z'){encrypted[i] = 'a';}
         else
         {
             // Make our character the next character on the ASCII table
             encrypted[i] = noEncryption[i] + 1;
         }
         i++;
     }
 }
