//------------------------------------------------------------------------
// DO_1: Insert your name and section
// Name:    Zack Neefe
//
// Course:  CS 1430, Section 2,  Fall 2016
//
// Purpose: For each positive integer N that is inputted,
//          this program computes and prints:
//               Sum of first N integers
//               Average of first N integers
//               Product of first N integers (Factorial)
//
// Input:   List of integers, terminated by end-of-file
//
// Output:  If is not positive, a message indicating it is not positive. 
//          Otherwise:
//               Sum of first N integers
//               Average of first N integers
//               Product of first N integers (Factorial)
//------------------------------------------------------------------------

#include <iostream>
using namespace std;

// The biggest factorial that can be represented in an int is 12!
const int MAX_FOR_FACTORIAL = 12;

int main()
{
   int num;           // Number read in
   int sum;           // Sum of the integers from 1 to Num
   int factorial;     // Product of the integers from 1 to Num
   float average;     // Average of the integers from 1 to Num
   int loopCount;     // Loop counter: loop counts from 1 to Num

   cout << "Enter an integer: ";
   cin >> num;
   cout << endl;  // Start a new line. Looks better for batch processing.

   // DO_2: Fill in the condition that the end of file was not reached
   while (cin) 
   {
      // DO_3: Fill in IF condition for a non-positive integer 
      if (num <= 0)
         cout << "Number is not a positive integer." << endl << endl;

      // DO_4: Fill in condition for num bigger than MAX_FOR_FACTORIAL
      else if (num > 12)
         cout << "Number too big to calculate factorial." << endl << endl;

      else
      {
         // DO_5: Initialize sum, factorial, and loopCount
		 sum = 0;
		 factorial = 1; // factorial is initialized at 1 because a product
		                // of 0 will always be 0
		 loopCount = 0;

         // DO_6: Fill in the condition for the counting loop, that is,
         //       the condition meaning the loop is not completed yet.
         while (loopCount < num)
         {
            // DO_7: One step to compute the sum
			sum = sum + (num - loopCount);

            // DO_8: One step to compute the product
			factorial = factorial * (num - loopCount);

            // DO_9: Update loopCount
			loopCount++;

         }

         // DO_10:  Calculate the average
		 average = float(sum) / num;

         // DO_11: Output the results. Finish for Average and Factorial
         cout << "Sum is: " << sum << endl;
		 cout << "Average is: " << average << endl;
		 cout << "Factorial is: " << factorial << endl;

         cout << endl;  // Another blank line to make the output pretty

      }

      // DO12: Prompt & read for the next integer, also add a new line
	  cout << "Enter an integer: ";
	  cin >> num;
	  cout << endl;

   }

   return 0;
}
