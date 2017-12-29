 #include "DayOfYear.h"

////////////////////////////////////////////////////////////////////////////////
// "DayOfYear.cpp" functions to make our lives easier

 // Returns the number of days in each month
 int numberOfDays(int monthNumber)
 {
     // Account for unwanted inputs
     monthNumber = monthNumber % 12;

     // Remember these? When you can, use them. They are really fast
     // and easy to understand.
     switch(monthNumber)
     {
         case 1:  return 31;
         case 2:  return 28; // Ignoring leap years
         case 3:  return 31;
         case 4:  return 30;
         case 5:  return 31;
         case 6:  return 30;
         case 7:  return 31;
         case 8:  return 31;
         case 9:  return 30;
         case 10: return 31;
         case 11: return 30;
         case 12: return 31;
         default: return -1;
     }
 }
 // Returns the corresponding number to each month
 int monthToNumber(string insertMonth)
 {
     // Switches don't work with strings :(
         if (insertMonth == "January")   return 1;
         if (insertMonth == "February")  return 2;
         if (insertMonth == "March")     return 3;
         if (insertMonth == "April")     return 4;
         if (insertMonth == "May")       return 5;
         if (insertMonth == "June")      return 6;
         if (insertMonth == "July")      return 7;
         if (insertMonth == "August")    return 8;
         if (insertMonth == "September") return 9;
         if (insertMonth == "October")   return 10;
         if (insertMonth == "November")  return 11;
         if (insertMonth == "December")  return 12;
                                         return -1;
 }

 // Returns the corresponding month to each number from 1 -> 12
 string numberToMonth(int insertMonth)
 {
     switch(insertMonth)
     {
         case 1:  return "January";
         case 2:  return "February";
         case 3:  return "March";
         case 4:  return "April";
         case 5:  return "May";
         case 6:  return "June";
         case 7:  return "July";
         case 8:  return "August";
         case 9:  return "September";
         case 10: return "October";
         case 11: return "November";
         default: return "December";
     }
 }



////////////////////////////////////////////////////////////////////////////////
// Start of Class Functions

 // Do not forget to initialize your static variables!
 string DayOfYear::month = "January";



 DayOfYear::DayOfYear()
 {
     day = 1;
     month = numberToMonth(1);

 }

 DayOfYear::DayOfYear(string insertMonth, int insertDay)
 {
     month = numberToMonth(1);

     // Make sure month is valid
     for(int i = 1; i <= 12; i++)
     {
         if(numberToMonth(i) == insertMonth){month = insertMonth;}
     }

     // Let user know they made a mistake
     if(month != insertMonth){cout << "Month not in calendar!\n";}

     // Make sure day is valid
     if(insertDay > 0 && insertDay < 32){day = insertDay;}

     // Let user know they made a mistake
     else {cout << "Day not in calendar!\n";}

 }

 DayOfYear::DayOfYear(int insertDay)
 {
     month = numberToMonth(1);
     month = currentMonth(insertDay);
     day = currentDay(insertDay);
 }

 void DayOfYear::print() const
 {
     cout << month << " " << day;
 }

 string DayOfYear::currentMonth(int insertDay) const
 {
     // Check for negative numbers
     if(insertDay <= 0){return NULL;}

     // Get rid of any amount bigger than a year.
     // Alternatively! We can do the following at the end:
     // return numberToMonth(i % 12);
     // Same thing.
     insertDay = insertDay % 365;

     int i = 1;

     // If the first month has more days than our number then we subtract it
     // from our total days and move on to the next month
     while(insertDay > numberOfDays(i))
     {
         i++;
         insertDay -= numberOfDays(i);
     }
     return numberToMonth(i);
 }

 int DayOfYear::currentDay(int insertDay) const
 {
     // Same as currentMonth we just return insertDay instead

     if(insertDay <= 0){return -1;}

     insertDay = insertDay % 365;

     int i = 1;

     while(insertDay > numberOfDays(i))
     {
         insertDay -= numberOfDays(i);
         i++;
     }

     return insertDay;
 }

 void DayOfYear::setDay(int insertDay)
 {
     if(insertDay < 0){cout << "Invalid negative number!\n"; return;}
     insertDay = insertDay % 365;

     day = insertDay;
 }

 void DayOfYear::setMonth(string insertMonth)
 {
     for(int i = 1; i <= 12; i++)
     {
         if(insertMonth == numberToMonth(i)){month = insertMonth;}
     }
 }

 DayOfYear operator + (DayOfYear insertObject, int insertDay)
 {
     /*
        OK probably the hardest thing in this assignment and it
        is only one line. We already created all the logic for
        adding days in the earlier functions. Do not recreate
        them! Use your constructors.

        We want to construct a new object with our current month
        and add an integer to the number of days we have. That's
        all we need to do.
     */
     return DayOfYear(insertObject.day + insertDay);
 }

 DayOfYear operator - (DayOfYear insertObject, int insertDay)
 {
     // We need to do a little work because my class only works with positive
     //  numbers
     // First we add all our previous months to get our total number of days
     int temp = insertObject.day, i = 1;
     while(insertObject.month != numberToMonth(i))
     {
         temp += numberOfDays(i);
         i++;
     }

     // Subtract our number
     temp = temp - insertDay;

     // Make sure we are in the calendar
     temp = temp % 365;

     // If we subtract our exact number of days
     if(temp == 0)
     {temp = 365;}

     // Else make the number positive
     else if(temp < 0)
     {temp = temp + 365;}

     return DayOfYear(temp);
 }






