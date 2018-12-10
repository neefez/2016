//-----------------------------------------------------------------------
// DO_01 fill in your name
// Name   :  Zack Neefe <<<<<<
//             
// Course :  CS 143, Section 2 >>>DO_2  Fill in your section number and 
//                                      the data      
//
// Purpose: This program reads in MAX_CHARS characters, reverses  
//          their order, and then prints the characters in reverse 
//          and pre-reverse order (original order).  When done with
//          one set of characters it will read another set of characters
//          and reverse them.
//          It repeats this process of reading and reversing until 
//          end-of-file is detected.
//
// Input  : MAX_CHARS characters
// 
// Output : The MAX_CHARS character in reverse order and then in the 
//          pre-reverse order.  For example, if
//          the characters are ABCDEFG are input the 
//          output is:
//               GFEDCBA <---> ABCDEFG
//
//-----------------------------------------------------------------------

#include <iostream>
using namespace std;


//Constants
const int MAX_CHARS = 7;   // Size of the array of chars



//Prototypes of functions
void DisplayChars(const char c1[]);
void CopyArray(const char in[], char out[]);

// DO_10 : Complete the following function prototype.
//         This function "reverses" the order of the characters 
//         in the array.  

void ReverseChars(char c5[]);


// DO_04  : write the following function prototype.
//     This function reads the characters into array c1.

bool ReadChars(char arrayOfChars[]);


//Function
int main()
{
   char c[MAX_CHARS], c2[MAX_CHARS];

   while (ReadChars(c))
   {
      // DO_06 :  call the function CopyArray to copy the data from
      //         array c to array c2. 

	  CopyArray(c, c2);


      // DO_11 : call function ReverseChars to reverse the order of the 
      //        characters stored in array c2.

	  ReverseChars(c2);


      // DO_13  : call the function DisplayChars to output the characters
      //        stored in array c2.

	  DisplayChars(c2);



      cout << "<--->";


      // DO_ 14 : call the function DisplayChars to output the characters
      //        stored in array c1.

	  DisplayChars(c);


   }

   cout << "\nCompleted processing characters.";

   return 0;
}  // END OF main()------------------------------------------------------


   //-----------------------------------------------------------------------
   // This function reads MAX_CHARS characters into an array.  It returns 
   // true if this was successful and a false if this was unsuccessful
   // due to reading EOF or other cin problem.
   // params: (  OUT   )
   //-----------------------------------------------------------------------
bool ReadChars(char arrayOfChars[])
{
   int lcv = 0;

   cout << "\n\nEnter " << MAX_CHARS
      << " characters or CNTL-Z to quit: ";
   

   // DO_3  :  complete a while loop with two stopping conditions. 
   //          Reads MAX_CHARS characters and store in an array
   //          OR until an EOF is detected
   char val;
   cin >> val; // Priming read for EOF loop

   while (lcv < MAX_CHARS && cin)
   {
  
      arrayOfChars[lcv] = val;
      lcv = lcv + 1;
      if (lcv < MAX_CHARS)
         cin >> val;

   }
   cout << endl;

   // IF    EOF detected return false
   // ELSE  return true  	
   if (cin)
      return true;

   return false;
}  // END OF ReadChars()-------------------------------------------------


   //-----------------------------------------------------------------------
   // This function copies the first array into the second array.
   //
   // params( in, out )
   //-----------------------------------------------------------------------
   // DO_05 : Complete the function heading
void CopyArray(const char in[], char out[])
{
   for (int lcv = 0; lcv < MAX_CHARS; lcv++)
      out[lcv] = in[lcv];

   return;
}  // END OF CopyArray()-------------------------------------------------



   //-----------------------------------------------------------------------
   // This function reverses MAX_CHARS characters in the array c4 
   //
   // The Reverse Algorithm:
   // 1.  It takes the value of the head position of the character array 
   //     and temporarily stores the value in a variable called temp. 
   // 2.  It takes the value of the tail position of the character array 
   //     and stores the value in the head position.
   // 3.  The head position index is increased by 1 and the tail position 
   //     index is decreased by 1.
   // 4.  the algorithm halts when the head and tail position are equal
   //
   // params: ( inout )
   //-----------------------------------------------------------------------
   //
   // DO_09 : Complete the function definition
void ReverseChars(char c5[])
{
   char temp;
   int tail, stopLoop = MAX_CHARS / 2;

   // DO_07: complete the for loop to reverse the order 
   //        of the character array   
   for (int lcv = 0; lcv < stopLoop; lcv++)
   {
      tail = MAX_CHARS - lcv - 1;

      // DO_08  : write the code that will swap the character in
      //        head position (lcv) with the character at the tail
      // HINT:  see the algorithm in the function header comment.    
      temp = c5[lcv];
      c5[lcv] = c5[tail];
      c5[tail] = temp;

   }

   return;
}  // END OF DisplayReverseChars()---------------------------------------


   //-----------------------------------------------------------------------
   // This function displays MAX_CHARS characters from array c42
   // 
   // params: ( in )
   //-----------------------------------------------------------------------
void DisplayChars(const char c42[])
{
   // DO_12 :  complete the for loop to output each character in the array
   for (int lcv = 0; lcv < MAX_CHARS; lcv++)
      cout << c42[lcv];

   return;
}  // END OF DisplayChars()----------------------------------------------



