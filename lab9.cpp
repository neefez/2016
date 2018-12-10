//------------------------------------------------------------------------
// DO_1: fill in your name and section
// Name:    Zack Neefe,  Fall 2016
//
// Course:  CS 1430, Section 2
//
// Purpose: Maintain list of names by processing commands.   Valid 
//          commands are A (Add), D (Delete), P (Print), and S (Sort,  
//          ascending order). Print an error if the command is invalid  
//          and ignore the rest of the command. Add at the end of the  
//          list.  Delete by replacing the person to be deleted with the  
//          last person in the list. Repeat this process until  
//          end-of-file: Use Ctrl-Z in Visual Studio for end-of-file.
//
// Input:   List of commands, some with arguments, terminated by 
//          end-of-file.
//
// Output:  A message is printed when a name is added to the list, 
//          deleted from the list, and sorted.  If the command is not  
//          valid, a message will be printed. If the P command is typed, 
//          the list is sorted in ascending order using the Selection Sort
//          algorithm from the textbook and then printed.
//------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_NAME = 6;
const int NAME_SPACING = 20;


int Find(const string names[], int num, string name);

//DO_8: Write the prototype for function Add here
void Add(string names[], int& num);
void Delete(string names[], int & num);
void Sort(string names[], int num);
void PrintNames(const string names[], int num);


int main()
{
   //DO_2: declare an arrays of strings named "names"of size MAX_NAME
   string names[MAX_NAME];
   int numNames = 0;
   char command;

   cout << fixed << showpoint << setprecision(2);
      
   cin >> command;
   
   while (cin)
   {
      //DO_3:  write code to call the function to process a command, 
      //       calling the proper function. Valid commands are 
      //       A, D, P, and S.
	  if (command == 'A')
		 Add(names, numNames);
	  else if (command == 'D')
		 Delete(names, numNames);
	  else if (command == 'P')
		 PrintNames(names, numNames);
	  else if (command == 'S')
		 Sort(names, numNames);
      else
      {
         cout << "Bad Command!" << endl;
         cin.ignore(200, '\n');
      }
      cin >> command;
   }

   cout << "Normal Termination of Lab 9." << endl;
   return 0;
}

//------------------------------------------------------------------------
// This function will search for the name in the array names[]. It will
// return a -1 if it is not found, and the index of the array name if it
// is found.
// params: (in, in, in)
//------------------------------------------------------------------------
int Find(const string names[], int num, string name)
{
   // DO_4: write the body of the Find function. Refer to the comments.
   for (int i = 0; i < num; i++)
   {
	  if (name == names[i])
		 return i;
   }
   
   return -1;
}

//------------------------------------------------------------------------
// This function will add a name to the end of the array of names if the 
// name is not already in the list, and if the list is not full.
// params: (inout, inout)
//------------------------------------------------------------------------
//DO_5: Complete the function header for the Add function.
void Add(string names[], int& num)
{
   string name;

   cin >> name;
  
   //DO_6: Call the Find function, saving the result in index.
   int index = Find(names, num, name);

   if (index >= 0)
   {
      cout << name << " is already in the list." << endl;
   }
   else if (num >= MAX_NAME)
   {
      cout << name + " wasn't added. List is full." << endl;
   }
   else
   {
      //DO_7: add the name to the end of the array and increment the 
      //      number of members.
	  names[num] = name;
	  num++;
      cout << name + " was added to the list." << endl;
   }
}

//------------------------------------------------------------------------
// This function will delete a name from the array list if the name is 
// in the array. It will replace the name with the last member in the 
// array.
// params: (inout, inout)
//------------------------------------------------------------------------
void Delete(string names[], int & num)
{
   string name;
   cin >> name;

   //DO_9: Call the Find function, saving the result in index.
   int index = Find(names, num, name);

   if (index < 0)
   {
      cout << name + " was not removed because it is not in the list." 
           << endl;
   }
   else
   {
      //DO_10: remove the name by replacing it with the last member, and 
      //       decrement the number of members.
      names[index] = names[num - 1];
	  num--;
      cout << name + " was removed from the list." << endl;
   }
}

//------------------------------------------------------------------------
// Prints the list of names.
// params: (in, in)
//------------------------------------------------------------------------
void PrintNames(const string names[], int num)
{
   cout << "The list of names is:" << endl;
   for (int i = 0; i < num; i++)
      cout << "   " << left << setw(NAME_SPACING) << names[i] << endl;
}

//------------------------------------------------------------------------
// This function will sort the list of names in ascending order, using 
// the Selection Sort algorithm from the text.
// params: (inout, in)
//------------------------------------------------------------------------
void Sort(string names[], int num)
{
   for (int i = 0; i < num - 1; i++)
   {
      //DO_11: declare mindex and define it 
	  int mindex = i;

      for (int j = i + 1; j < num; j++)
      {
         //DO_12: Check to see if the current slot is smaller than mindex
         //       and take appropriate action.
         if (names[j] < names[mindex])
			mindex = j;
      }
      //DO_13: Swap the array cells at i and mindex.
	  string temp = names[i];
	  names[i] = names[mindex];
	  names[mindex] = temp;
   }
   cout << "List sorted by name." << endl;
}


