//------------------------------------------------------------------------
// Lab3, Simple if/else statement.  
//
// DO_1: Enter your name and section.
//
// Name:  Zack Neefe  
//
// Course:  CS 1430, Section 2, Fall 2016
//
// Purpose: This program is a simple currency calculator that converts  
//          between US dollars and Japanese Yen. The exchange rate is
//          $1 = 102.4 Japanese Yen.
//
// Input:   1. Enter 0 to convert dollars to Japanese Yen, and any other   
//             number to covert Japanese Yen to dollars. 
//          2. Enter the dollars amount or Japanese Yen amount.
//
// Output:  1. The converted dollars amount or Japanese Yen. 
//          2. The output for the Debugger Exercise.
//           
//------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
using namespace std;
 
const float EXCHANGE_RATE = 102.4f;  

int main()
{
   float convertType;
   //DO_2: declare two variables for the converting amount and converted 
   //      amount.
   float amount;
   float finalAmount;
	
   cout << fixed << showpoint << setprecision(2);
   
   cout << "Enter 0 to convert dollars to Japanese Yen,"
        << " and other number vice versa: ";
   //DO_3: use cin to input the convert type
   cin >> convertType;
   
   
   //start the output on a new line
   cout << endl;
   //prompt the first part of the message
   cout << "Enter the "; 
   //DO_4: write a logical expression to prompt the second part of
   //      the message
   if (convertType == 0)
      cout << "dollars ";
   else
      cout << "Japanese Yen ";

   cout << "amount: ";
   cin >> amount;
   
   //start the output on a new line
   cout << endl;
   //DO_5: write a logical expression to check the convertType, 
   //      if it is an 0, convert the dollars to Japanese Yen 
   //      and output the result
   if (convertType == 0)
   {
	   finalAmount = amount * EXCHANGE_RATE;
	   cout << "$" << amount << " is " << finalAmount;
	   cout << " Japanese Yen." << endl;
   }
   //DO_6: otherwise, convert the Japanese Yen to the dollars
   //      and output the result 
   else
   {     
	   finalAmount = amount / EXCHANGE_RATE;
	   cout << amount << " Japanese Yen is $" << finalAmount << endl;
   }
   
//Debugger Exercise
//DO_7: Set a break point right after the first cin statement 
//      where you read in the convert type.
//      Start Debugging run 1: enter -5 as the convertType
//      Start Debugging run 2: enter 12.34 as the convertType
// write down the value of convertType in the Debug window "local"
// and complete the following cout statements.   
   cout << endl << "Start Debugging run 1, the value of convertType: "
        << "-5" << endl;
   cout << "Start Debugging run 2, the value of convertType: " 
        << "12" << endl;         
   
   return 0;
}