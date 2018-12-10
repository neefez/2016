//---------------------------------------------------------------------
// DO_1: Insert your name and section
// Name: Zack Neefe
//
// Course:  CS 1430, Section 2,  Fall 2016
//
// Purpose: This program computes the last term, the sum and 
//          float average of all the terms in an arithmetic 
//          progression, given the first term, the common 
//          difference and the number of terms.  
//
//
// Input :  This program accepts the following prompted input
//          from the keyboard:
//              firstTerm        -  an integer
//              commonDifference -  an integer
//              numberOfTerms    -  an integer
//
//
// Output:  This program provides the following computed output,
//          appropriately labelled, to the monitor:
//                  lastTerm          - as an integer
//                  averageOfAllTerms - as a float
//                  sumOfAllTerms     - as an integer
//---------------------------------------------------------------------

#include <iostream>
using namespace std;

int main()
{
   // ***** INPUT Variables *****
   //first term in the arithmetic progression 
   int firstTerm; 

   //the common difference between consecutive terms in the sequence
   int commonDifference; 

   // the number of terms in the series
   // DO_2: Declare the remaining Input variable
   //       Hint: see Program Header for Inputs. 
   int numberOfTerms;
   
   // ***** OUTPUT Variables *****
   // DO_3: Declare the three Output variables
   //       Hint: see Program Header for Outputs.
   int lastTerm;
   float averageOfAllTerms;
   int sumOfAllTerms;
   
   // ***** PROMPTED INPUTS *****
   // Prompt "Enter first term: " and Input the first term
   cout << "Enter first term: ";
   cin >> firstTerm;

   // DO_4: Prompt "Enter common difference: " and Input common difference;
   //       then Prompt "Enter number of terms: " and Input number of terms.
   cout << "Enter common difference: ";
   cin >> commonDifference;
   cout << "Enter number of terms: ";
   cin >> numberOfTerms;
      
   // ***** COMPUTATIONS *****
   // DO_5: Compute the values
   //       Hint: see Program Header for Outputs and the lab2.docx for formulas.
   lastTerm = firstTerm + (numberOfTerms - 1) * commonDifference;
   sumOfAllTerms = numberOfTerms * (firstTerm + lastTerm) / 2;
   averageOfAllTerms = float(sumOfAllTerms) / numberOfTerms;

   // Start the output on a new line
   cout << endl;

   // ***** OUTPUTS *****
   // DO_6: Output values with messages
   //       Hint: see the example output in the lab2.docx. 
   cout << "The last term is " << lastTerm << "." << endl;
   cout << "The average of all the terms is " << averageOfAllTerms << "." << endl;
   cout << "The sum of all the terms is " << sumOfAllTerms << "." << endl;

   //---------  Debugger Exercise ---------------------------
   // DO_7: Replace the 99 with the answer to the debugger exercise.
   // Hypotenuse variables for the debugger exercise
   int leg1 = 25;
   int leg2 = 17;
   int intermediatehypotenuse;
   float hypotenuse;

   intermediatehypotenuse = ( leg1 * leg1 ) + ( leg2 * leg2);
   hypotenuse = sqrt (float(intermediatehypotenuse));
   cout << hypotenuse << endl;
   //Replace the following output of 99 with the result from the intermediatehypotenuse value above using the debugger.
   cout << 914 << endl;
   //----------------------  End Debugger Exercise --------------------------

   return 0;
}  // ******* end of main() *******

