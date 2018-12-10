//-----------------------------------------------------------------------
//
// Name   : >>>> DO_1 Zack Neefe <<<<<<
//             
// Course :  CS 143, >>>DO_2 Section 2 <<<,  Fall 2016
//
// Purpose: This program reads in four characters and then
//          prints them out in a rotated pattern.  When done rotating 
//          the four characters, it will read another four characters 
//          and rotate them.  It repeats this process of reading and 
//          rotating until end-of-file
//
// Input  : Four characters c1, c2, c3, and c4.
// 
// Output : The four character in a rotated pattern.  For example, if
//          the characters are A B C D the output is:
//               ABCD
//               BCDA
//               CDAB
//               DABC  
//
//-----------------------------------------------------------------------

#include <iostream>
using namespace std;

const int NUM_STEPS = 4;   // number of rotation steps to perform

void DisplayRotationPattern(char c1, char c2, char c3, char c4);
void DisplayFourChars(char c1, char c2, char c3, char c4);

// DO_3: Complete the following function prototype.
//     This function "rotates" four characters c1, c2, c3, and c4.
//     That is, it puts c2 in c1, c3 in c2, c4 in c3, and c1 in c4.
void RotateFourChars(char& c1, char& c2, char& c3, char& c4);


int main()
{
   char ch1, ch2, ch3, ch4;   

   cout << "Enter four characters: ";
   cin >> ch1 >> ch2 >> ch3 >> ch4;

   while( cin )
   {
      cout << "The Rotation patterns are:" << endl;

      // DO_4: Call DisplayRotationPattern

	  DisplayRotationPattern(ch1, ch2, ch3, ch4);
        
      cout << "Enter four characters: ";
      cin >> ch1 >> ch2 >> ch3 >> ch4;
   }

   return 0;
}


//-----------------------------------------------------------------------
// This function displays the four characters passed to it
// in a rotated pattern.
// params: (in, in, in, in)
//-----------------------------------------------------------------------
void DisplayRotationPattern(char c1, char c2, char c3, char c4)
{
   int count = 1;
   while (count <= NUM_STEPS)
   {
      // DO_5: Call function to display the characters

	  DisplayFourChars(c1, c2, c3, c4);

      cout << endl;



      // DO_6: Call function to rotate the characters

	  RotateFourChars(c1, c2, c3, c4);

      count ++;
   }

   return;
}

//-----------------------------------------------------------------------
// This function "rotates" four characters c1, c2, c3, and c4.
// That is, it puts c2 in c1, c3 in c2, c4 in c3, and c1 in c4.
// HINT:  you will need a temporary variable to hold the first 
//        letter of each set. 
// params: (inout, inout, inout, inout)
//-----------------------------------------------------------------------
//
// DO_7: Write the function header
void RotateFourChars(char& c1, char& c2, char& c3, char& c4)
{

   // DO_8: Write the function body.

   char temp;

   temp = c1;
   c1 = c2;
   c2 = c3;
   c3 = c4;
   c4 = temp;

   return;
}

//-----------------------------------------------------------------------
// This function has four input parameters, each of them is a character.
// The function displays the four characters at the beginning of a line.
// params: (in, in, in, in)
//-----------------------------------------------------------------------
void DisplayFourChars(char c1, char c2, char c3, char c4)
{

   // DO_9: Write function body

   cout << c1 << c2 << c3 << c4;

   return;
}

