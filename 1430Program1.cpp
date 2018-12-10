//------------------------------------------------------------------------
//
// Name: Zackary Neefe
//
// Course:  CS 1430, Section 2
//
// Purpose: This program reads the amount from an inputted ATM withdrawal
//          and determines the minimum number of $50, $20, $10, $5, and
//          $1 bills that are needed to pay the amount as well as the
//          total number of bills.
//
// Input: The amount of money that needs to be withdrawn, an integer.
//
// Output: The following integers:
//            -the amount of $50 bills
//            -the amount of $20 bills
//            -the amount of $10 bills
//            -the amount of $5 bills
//            -the amount of $1 bills
//            -the total number of bills
//------------------------------------------------------------------------
// 
// TODO1: Right-click to the right of the last dash above, select 
//   Guidelines, and then select Add Guideline.  This will place a 
//   Guideline at the end of column 74.  Do not go past it!
//   You can also change the color of the Guideline by right-clicking.
// TODO2: To reformat, click Edit -> Advanced -> Format Document.
//   This will clean up the formatting if you have issues.
//   Then recheck to make sure line lengths are inside the Guidelines.
// The above TODO's assume templates were properly installed as per
// Step 4 of the Visual_Studio_2015_Installation document at:
//     K:\Academic\CSSE\Software\VisualStudio2015_Instructions

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int FIFTY_DOLLARS = 50;
const int TWENTY_DOLLARS = 20;
const int TEN_DOLLARS = 10;
const int FIVE_DOLLARS = 5;
const int ONE_DOLLAR = 1;

int main()
{
   int amount;
   int fifties;
   int twenties;
   int tens;
   int fives;
   int ones;
   int totalBills;

   // Prompt for the amount of money wanted to be withdrawn.
   cout << "Enter the amount of withdrawal: ";
   cin >> amount;

   // Condition to account for instances in which a non-positive amount
   // is entered.
   if (amount <= 0)
	   cout << endl << "Total number of bills given out: 0" << endl;
   else
   {
	   // Determine the number of fifty dollar bills.
	   fifties = amount / FIFTY_DOLLARS;
	   // Subtract the dollar amount of the fifties to get the remaining
	   // amount that needs to be used for future calculations.  This
	   // step is the same for all of the bill types.
	   amount = amount - fifties * FIFTY_DOLLARS;

	   // Determine the number of twenty dollar bills.
	   twenties = amount / TWENTY_DOLLARS;
	   amount = amount - twenties * TWENTY_DOLLARS;

	   // Determine the number of ten dollar bills.
	   tens = amount / TEN_DOLLARS;
	   amount = amount - tens * TEN_DOLLARS;

	   // Determine the number of five dollar bills.
	   fives = amount / FIVE_DOLLARS;
	   amount = amount - fives * FIVE_DOLLARS;

	   // Use remaining amount as number of one dollar bills.
	   ones = amount;

	   // Determine the total number of bills given out by adding
	   // together the individual numbers of bills.
	   totalBills = fifties + twenties + tens + fives + ones;

	   // Output the numbers of each bill type, skipping them if there
	   // are zero of that bill.
	   cout << endl;
	   if (fifties > 0)
	      cout << "Number of 50's: " << fifties << endl;
	   if (twenties > 0)
	      cout << "Number of 20's: " << twenties << endl;
	   if (tens > 0)
	      cout << "Number of 10's: " << tens << endl;
	   if (fives > 0)
	      cout << "Number of 5's:  " << fives << endl;
	   if (ones > 0)
	      cout << "Number of 1's:  " << ones << endl;

	   // Output the total number of bills.
	   cout << "Total number of bills given out: " << totalBills << endl;
   }
   
   cout << "Normal Termination of Program 1." << endl;

   return 0;
}