//---------------------------------------------------------------------
// Name   : >>>> Do: 1. Zack Neefe <<<<<<
//             
// Course :  CS 1430, >>>Do: 2. Section 2 <<<,  Fall 2016
//
// Purpose: This program reads three integers and finds and prints
//          the minimum, the square and cube of the minimum.
//  
// Input  : Three integers num1, num2 and num3.
// 
// Output : Minimum of the three numbers, square and cube of the 
//          minimum.  
//---------------------------------------------------------------------

#include <iostream>
using namespace std;

int Minimum(int first, int second, int third);// prototype of function 

//Do: 3. Complete the prototype for PrintResults; see function 
//       definition below.

void PrintResults(int first, int second, int third, int min,
	              int squareval, int cubeval);

// prototype of function PrintResults

int main()  
{
   int num1, num2, num3, minimum, sqrnum, cubenum;     
                                      
   cout << "Input three integer values: ";
   cin  >> num1 >> num2 >> num3;
   cout << endl;
  
              
   //  Do: 4. Complete the next line by adding a call to the function, 
   //         which find the minimum of the three numbers. 

   minimum = Minimum(num1, num2, num3);
 
   sqrnum = minimum * minimum;
   cubenum = sqrnum * minimum;

//  Do: 5. Complete the next line by adding a call to  function, 
//         PrintResults, which displays all the output. There are six parameters.
     
   PrintResults(num1, num2, num3, minimum, sqrnum, cubenum);
      
   return 0;
} 

    
//-----------------------------------------------------------------------
//Do: 6.Write complete function header for Minimum function, that takes  
//three integer values and finds and returns the minimum.
//The function has three formal value parameters.
//Hint: see prototype.
// Params: (in, in, in)
//-----------------------------------------------------------------------

int Minimum(int first, int second, int third)
{
   int min;

   // Do: 7. Complete the following function body so it matches its 
   // specification.  That is it finds the smallest of three values.
   
   if (first <= second && first <= third)
	  min = first;
   else if (second <= first && second <= third)
	  min = second;
   else
	  min = third;

   return min;
     
//Post-Condition: Return minimum of three int values.
}

//-----------------------------------------------------------------------
//PrintResults function, that prints all the output,  
// The function has six formal value parameter.
// params: (in, in, in, in, in, in)     
//-----------------------------------------------------------------------    
void PrintResults ( int first, int second, int third, int min, 
                    int squareval, int cubeval )
{
// Do: 8. Complete the following function body so it matches its 
// specification.  Look at the lab description and match the output.
   
   cout << "The minimum of " << first << ", " << second << ", and "
        << third << " is " << min << "." << endl;
   cout << "The square of " << min << " is " << squareval << "." << endl;
   cout << "The cube of " << min << " is " << cubeval << "." << endl;

   return;
}
  
