//---------------------------------------------------------------------
//     DO 1 - Fill in your name
// Name:    Zack Neefe
//     DO 2 - Fill in your Section number
// Course:  CS 1430, Section 2 
//
// Purpose: This lab demonstrates the use of getchar, putchar and 
//          printf.  Assume that the user is extracting information
//          from a comma delimited file. Each line of the file looks
//          like this:
//          float,int,junk,junk,first,last'\n'
//          The float number and int are multiplied by each other
//          and the name is loaded into a character array.  
//     
//          getchar is used to skip over the commas and to get the 
//          characters of the first and last name.  Putchar is used
//          to display the name Printf is used to display the output
//          nicely formatted.
//
// Input:   float, int, chars until \n is reached
//
// Output:  first and last name (only 10 characters, 3 formatted floats
//          and an int
//---------------------------------------------------------------------

#include <stdio.h>
using namespace std;

const int MAX_SIZE = 50;  //size of name array
const int NUMCOMMA = 2; // number of comma delimited items to skip
const int OUTSIZE = 10; // number of chars in name to list
void ReadName(char name[], int& size);
void PrintName(const char name[], int size);

int main()
{

   float fnum = 0;
   float answer;
   int inum = 0;
   char letter;
   char name[MAX_SIZE];
   int goodread = 1;

   // Print out labels for the table	
   printf("%s %23s %15s %15s %15s \n", "NAME", "FLOAT", "INTEGER",
      "ANSWER", "SCI ANSWER");
   goodread = scanf("%f", &fnum);  // get the float
   while (goodread == 1)
   {
      //DO 3 Complete the statement to call getchar and assign to 
      //     letter. Do nothing with it, just "eats" the comma
      
      letter = getchar();


         scanf("%d", &inum);  // get the integer

                              //DO 4 Write the complete statement to get the next comma and
                              //     assign it to letter.  Do nothing with it, just
                              //     "eats" the comma
      letter = getchar();


                              // For loop will read for 2 more commas
      for (int j = 0; j < NUMCOMMA; j++)
      {
         letter = getchar();
         while (letter != ',')
            letter = getchar();
      }
      int size;
      ReadName(name, size);
      PrintName(name, size);
      // Compute answer
      answer = inum * fnum;

      // DO 7 Format the numbers to be printed as described in the 
      //      lab11.txt file.

      printf(" %17.6f %15d %15.2f %15.6e \n", fnum, inum, answer, answer);

      goodread = scanf("%f", &fnum);
   }
   return 0;
}
void ReadName(char name[], int& size)
{
   char letter;
   // Now the first name is ready to be processed
   int i = 0;

   //DO 5a Prime the while loop by getting the next letter using 
   //      the getchar function

   letter = getchar();

   // DO 5b Write the test for the loop to keep going as long as
   //       letter is not equal to a comma.
   while (letter != ',')
   {
      name[i] = letter;
      i++;
      letter = getchar();
   }

   // Put a space after the first name in the array
   name[i] = ' ';
   i++;
   // prime the last name loop by getting the first letter
   letter = getchar();
   // REMEMBER that last name is the last field on the line so this
   // ends with '\n'  It will fit in the array no need to test this
   while (letter != '\n')
   {
      name[i] = letter;
      i++;
      letter = getchar();
   }
   size = i;
}
void PrintName(const char name[], int size)
{
   // DO 6  Write a for loop to list out 10 chars of the name using
   //      the putchar function. If there fewer than 10 characters 
   //      in the array then putchar ' ' (space).  HINT:  What 
   //      index variable above will tell you how many chars are in
   //	  the array?
   
   if (size >= OUTSIZE)
   { 
      for (int i = 0; i < OUTSIZE; i++)
         printf ("%c", name[i]);
   }

   else if (size < OUTSIZE)
   {  
      for (int i = 0; i < size; i++)
         printf("%c", name[i]);

      for (int i = 0; i < OUTSIZE - size; i++)
         putchar(' ');
   }

   return;
}