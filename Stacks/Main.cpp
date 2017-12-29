/*
 *	Stacks
 *
 *	Date Posted: 11/14/2017
 *	Language: C++
 *	Files: 2 cpp files, 1 header file
 *	Executable: Main.cpp
 *	Libraries: iostream
 */

 #include "dynamic_stack.cpp"
 bool testDelimiters(string test);

 int main()
 {
     string test1 = "{eggs}[]()(spam[{}])"; // should return true
     string test2 = "{}[blue]no([{yellow]}])"; // should return false

     cout << " Testing string 1:\n";
     if(!testDelimiters(test1)){
     cout << " It is not ";}
     else{cout << " It is ";}
     cout << "correctly delimited.\n";

     cout << endl;

     cout << " Testing string 2:\n";
     if(!testDelimiters(test2)){
     cout << " It is not ";}
     else{cout << " It is ";}
     cout << "correctly delimited.\n";

     cin.get();
     return 0;
 } // End of main.

 /************************************************************
  * Opening character = '(' , '[' , '{'                      *
  * Closing character = ')' , ']' , '}'                      *
  * We push everything that is not a closing character       *
  * Once we encounter a closing character we pop values      *
  * until we encounter the matching opening character.       *
  * If we encounter another closing character, an unmatching *
  * opening character or the stack becomes empty then the    *
  * test has failed and we return false.                     *
  * At the end we also check for stray opening characters    *
  * left in stack.                                           *
  ************************************************************
  */

 bool testDelimiters(string test)
 {
     DynamicStack tempObject;
     int i = 0;
     char tempChar = '\0';

     while(test[i])
     {
         // Push everything that is not a closing character.
         if(test[i] != ')' && test[i] != ']' && test[i] != '}')
         {tempObject.push(test[i]);}

         else
         {
             switch(test[i])
             {
                 case ')':
                     while(true)
                        {
                            // Is stack empty?
                            if(tempObject.isEmpty()){return false;}

                            tempObject.pop(tempChar);

                            // Did we match our closing character correctly?
                            if(tempChar == '('){break;}

                            // Did we match our closing character incorrectly?
                            else if(tempChar == '[' || tempChar == '{')
                                {return false;}
                        }
                        break;

                case ']':
                    while(true)
                        {
                            if(tempObject.isEmpty()){return false;}

                            tempObject.pop(tempChar);

                            if(tempChar == '['){break;}

                            else if(tempChar == '(' || tempChar == '{')
                                {return false;}
                        }
                    break;

                case '}':
                    while(true)
                        {
                            if(tempObject.isEmpty()){return false;}

                            tempObject.pop(tempChar);

                            if(tempChar == '{'){break;}

                            else if(tempChar == '(' || tempChar == '[')
                                {return false;}
                        }
                    break;

             } // end of switch
         } // end of else

         i++;

     } // end of while

     // Final check for stray opening characters.
     while(!tempObject.isEmpty())
     {
         tempObject.pop(tempChar);
         if(tempChar == '(' || tempChar == '[' || tempChar == '{')
                {return false;}
     }
     return true;
 }
