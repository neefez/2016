//------------------------------------------------------------------------
//
// Name:    Zack Neefe, Seth Standke
//
// Course:  CS 1430, Section 2
//
// Purpose: This program maintains the names and salaries of employees of
//          a company.  The program reads and processes commands and
//          associated parameters.
//
// Input:   -commands, in the form of characters
//          -names, stored as strings
//          -salaries, stored as integers
//
// Output:  -message when an employee has been added
//          -the list of employees
//          -message when a raise is given
//          -the average salary
//          -message when an employee is removed
//          -message when the list is sorted
//          -message for a bad command
//
// Share of work:
//          Zack Neefe: Z Neefe - 50%, S Standke - 50%
//          Seth Standke: Z Neefe - 50%, S Standke - 50%
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

const int MAX_EMPLOYEES = 5;
const int NAME_SPACING = 20;

int Find(const string names[], int num, string name);
void Add(string names[], int salaries[], int& num);
void Delete(string names[], int salaries[], int& num);
void Print(const string names[], const int salaries[], int num);
void Sort(string names[], int salaries[], int num);
void Raise(int salaries[], int num);
void Average(const int salaries[], int num);
void SalarySort(string names[], int salaries[], int num);

int main()
{
   string names[MAX_EMPLOYEES];
   int salaries[MAX_EMPLOYEES];
   int num = 0;
   char command;

   cin >> command;
   while (cin)  // loop detects command type and executes proper function
   {
      if (command == 'A')
         Add(names, salaries, num);
      else if (command == 'D')
         Delete(names, salaries, num);
      else if (command == 'P')
         Print(names, salaries, num);
      else if (command == 'S')
         Sort(names, salaries, num);
      else if (command == 'R')
         Raise(salaries, num);
      else if (command == 'V')
         Average(salaries, num);
      else  // condition for improper character
      {
         cout << "Bad Command!" << endl;
         cin.ignore(200, '\n');
      }
      cin >> command;
   }
   cout << "Normal Termination of Program 4.";
   
   return 0;
}

//-----------------------------------------------------------------------
// This function searches for a name in the name array and returns the
// index if it is found or a -1 if it is not.
// params: (in, in, in)
//-----------------------------------------------------------------------
int Find(const string names[], int num, string name)
{
   const int NOT_FOUND = -1;
   int index = NOT_FOUND;

   for (int i = 0; i < num; i++)
   { 
      if (names[i] == name)
         index = i;
   }
   
   return index;
}

//-----------------------------------------------------------------------
// This function adds a name and a salary for a new employee to their
// respective arrays.
// params: (inout, inout, inout)
//-----------------------------------------------------------------------
void Add(string names[], int salaries[], int& num)
{
   string name;
   int salary, index;

   cin >> name >> salary;

   index = Find(names, num, name); // checks to see if name is already in
                                   // the array and changes salary if so
   if (index >= 0)
   {
      salaries[index] = salary;
      cout << "Salary updated for " << name << " to $" << salary << ".";
      cout << endl;
   }
   else if (num < MAX_EMPLOYEES)
   {
      names[num] = name;
      salaries[num] = salary;
      cout << names[num] << " was added to the company with salary $";
      cout << salaries[num] << "." << endl;
      num++;
   }
   else  // condition for full array
      cout << name << " wasn't added. No more room." << endl;

   return;
}

//-----------------------------------------------------------------------
// This function deletes a name and salary for some employee from their 
// respective arrays.
// params: (inout, inout, inout)
//-----------------------------------------------------------------------
void Delete(string names[], int salaries[], int& num)
{
   int index;
   string name;
   cin >> name;
   
   index = Find(names, num, name);
   if (index >= 0)
   {
      num--;
      names[index] = names[num];
      salaries[index] = salaries[num];
      cout << name << " removed from the company." << endl;
   }
   else  // condition for a name not in the company
   { 
      cout << name << " not removed.  Doesn't exist in the company.";
      cout << endl;
   }

   return;
}

//-----------------------------------------------------------------------
// This function prints the names of the employees of the company and
// their salaries.
// params: (in, in, in)
//-----------------------------------------------------------------------
void Print(const string names[], const int salaries[], int num)
{
   cout << "The list of Employees is:" << endl;
   for (int i = 0; i < num; i++)
   { 
      cout << "   " << left << setw(NAME_SPACING) << names[i] << "  $";
      cout << salaries[i] << endl;
   }

   return;
}

//-----------------------------------------------------------------------
// This function sorts the arrays either alphabetically by employee name
// or by the amount of their salaries.
// params: (inout, inout, in)
//-----------------------------------------------------------------------
void Sort(string names[], int salaries[], int num)
{
   int min = 0;
   int minIndex, tempSalary;
   char sort_type;
   string tempName;
   cin >> sort_type;

   if (sort_type == 'N')
   {
      for (int i = 0; i < num - 1; i++)
      { 
         minIndex = i;

         for (int j = i + 1; j < num; j++)
         { 
            if (names[j] < names[minIndex])
               minIndex = j;
         }

         tempName = names[minIndex]; // switches the indexed values
         names[minIndex] = names[i]; // in both arrays
         names[i] = tempName;

         tempSalary = salaries[minIndex];
         salaries[minIndex] = salaries[i];
         salaries[i] = tempSalary;
      }

      cout << "Company List sorted by name." << endl;
   }
   else
      SalarySort(names, salaries, num);

   return;
}

//-----------------------------------------------------------------------
// This function gives a raise of a specified amount to all employees in 
// the company.
// params: (inout, in)
//-----------------------------------------------------------------------
void Raise(int salaries[], int num)
{
   int raise_amount;
   cin >> raise_amount;

   for (int i = 0; i < num; i++)
      salaries[i] = salaries[i] + raise_amount;

   cout << "A raise of " << raise_amount << " was given to all." << endl;

   return;
}

//-----------------------------------------------------------------------
// This function averages the salaries of all of the company's employees
// and outputs it.
// params: (in, in)
//-----------------------------------------------------------------------
void Average(const int salaries[], int num)
{
   int totalSalary = 0;
   float average;
   cout << fixed << showpoint << setprecision(2);
   
   if (num > 0)
   {
      for (int i = 0; i < num; i++)
         totalSalary = totalSalary + salaries[i];

      average = float(totalSalary) / float(num);

      cout << "The average salary is: $" << average << "." << endl;
   }
   else
      cout << "No average.  No employees." << endl;

   return;
}

//-----------------------------------------------------------------------
// This function sorts the salaries[] and names[] array into ascending 
// order by salary.
// params: (inout, in)
//-----------------------------------------------------------------------
void SalarySort(string names[], int salaries[], int num)
{
   int minIndex, tempSalary;
   string tempName;

   for (int i = 0; i < num - 1; i++)
   {
      minIndex = i;

      for (int j = i + 1; j < num; j++)
      {
         if (salaries[j] < salaries[minIndex])
            minIndex = j;
      }

      tempSalary = salaries[minIndex];
      salaries[minIndex] = salaries[i];
      salaries[i] = tempSalary;

      tempName = names[minIndex];
      names[minIndex] = names[i];
      names[i] = tempName;
   }

   cout << "Company List sorted by salary." << endl;

   return;
}