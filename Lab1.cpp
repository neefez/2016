//------------------------------------------------------------------------
//
// Name:    Zack Neefe
//
// Course:  CS 1430, Section 2, Fall 2016
//
// Purpose: This program reads in an integer temperature in Celsius 
//          and converts it to Fahrenheit.
//
// Input:   An integer representing temperature in Celsius.
//
// Output:  An integer representing the inputted temperature 
//          converted to Fahrenheit.
//------------------------------------------------------------------------

#include <iostream>
using namespace std;

const int C_TO_F_CONV_NUMERATOR = 9;
const int C_TO_F_CONV_DENOMINATOR = 5;
const int C_TO_F_CONV_ADDITION = 32;

int main()
{
   int tempCelsius;
   int tempFahrenheit;
   int intermedCalc;

   cout << "Enter an integer temperature in Celsius: ";   // Prompt
   cin >> tempCelsius;   // Read temperature

   // Do the conversion calculations
   intermedCalc = tempCelsius *
      C_TO_F_CONV_NUMERATOR / C_TO_F_CONV_DENOMINATOR;

   tempFahrenheit = intermedCalc + C_TO_F_CONV_ADDITION;

   // Output the converted result
   cout << endl << "A temperature in Celsius of " << tempCelsius
        << " is " << tempFahrenheit
        << " in Fahrenheit." << endl;

   //---------  Debugger Exercise Answer ---------------------------
   // Replace the 99 with the answer to the debugger exercise.

   cout << 90 << endl;

   return 0;
}
