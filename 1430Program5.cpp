//------------------------------------------------------------------------
//
// Name:    Zack Neefe, Seth Standke
//
// Course:  CS 1430, Section 2
//
// Purpose: This program maintains a small fleet of three cars. The
//          program records when a car goes in for a fill-up, the mileage,
//          gallons to fill it, and cost to fill it.
//
// Input:   Commands in the form of characters A, C, M, P, and T.
//          The ID number of the cars, an integer.
//          Parameters for the commands.
//
// Output:  The reading of the odometer, an integer.
//          The number of gallons used, a float.
//          The cost per gallon, a float.
//          The miles per gallon, a float.
//          The cost per mile, a float.
//
// Percent of work:
//          Zack Neefe - Z Neefe 50%, S Standke 50%
//          Seth Standke - Z Neefe 50%, S Standke 50%
//------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_RECS = 5;
const int CENTS_PER_DOLLAR = 100;
const int OD_WIDTH = 7;
const int COST_WIDTH = 9;
const int GAL_WIDTH = 10;

enum CarID_Type {ID_CAR1 = 2234, ID_CAR2 = 5327, ID_CAR3 = 7741};
enum CommandType {ADD_CMD = 'A', CENTS_PER_MILE_CMD = 'C', MPG_CMD = 'M', 
                  PRICE_PER_GAL_CMD = 'P', TABLE_PRINT_CMD = 'T'};
class FleetCar
{
private:
   int odometer[MAX_RECS];
   float gallons[MAX_RECS];
   float cost[MAX_RECS];
   int numRecs;

public:
   //--------------------------------------------------------------------
   // Defualt constructor, empties the arrays.
   // params: (none)
   //--------------------------------------------------------------------
   FleetCar()
   {
      numRecs = 0;
   }

   //--------------------------------------------------------------------
   // This method adds a record to the end of the table if the table is
   // not full or moves all the records up one slot (index 0 is removed) 
   // if the table is already full.
   // params: (in)
   //--------------------------------------------------------------------
   void AddRecord()
   {
      if (numRecs < MAX_RECS)
      { 
         cin >> odometer[numRecs] >> gallons[numRecs] >> cost[numRecs];
         numRecs++;
      }
      else
      { 
         for (int i = 1; i < MAX_RECS; i++)
         {
            odometer[i - 1] = odometer[i];
            gallons[i - 1] = gallons[i];
            cost[i - 1] = cost[i];
         }
         cin >> odometer[numRecs] >> gallons[numRecs] >> cost[numRecs];
      }

      return;
   }

   //--------------------------------------------------------------------
   // This method sums the cost of the fuel and divides by the number of
   // gallons. If numRecs is 0, prints 0.00.
   // params: (none)
   //--------------------------------------------------------------------
   float PricePerGallon()
   {
      float totalCost = 0;
      float totalGallons = 0;

      if (numRecs <= 0)
         return 0;
      else
      { 
         for (int i = 0; i < numRecs; i++)
            totalCost = totalCost + cost[i];
         for (int i = 0; i < numRecs; i++)
            totalGallons = totalGallons + gallons[i];

         return totalCost / totalGallons;
      }
   }

   //--------------------------------------------------------------------
   // This method divides the total cost of fuel, mulitplied by 100, by
   // the total distance traveled in miles.
   // params: (none)
   //--------------------------------------------------------------------
   float CentsPerMile()
   {
      float totalCost = 0;
      float mileDifference = odometer[numRecs - 1] - odometer[0];
   
      if (numRecs <= 1)
         return 0;
      else
      {
         for (int i = 1; i < numRecs; i++)
            totalCost = totalCost + cost[i];
         return CENTS_PER_DOLLAR * totalCost / mileDifference;
      }
   }

   //--------------------------------------------------------------------
   // This method divides the total distance traveled by a fleet car by
   // amount of fuel it used, in gallons.
   // params: (none)
   //--------------------------------------------------------------------
   float MilesPerGallon()
   {
      float mileDifference = odometer[numRecs - 1] - odometer[0];
      float totalGallons = 0;

      if (numRecs <= 1)
         return 0;
      else
      {
         for (int i = 1; i < numRecs; i++)
            totalGallons = totalGallons + gallons[i];
         return mileDifference / totalGallons;
      }
   }

   //--------------------------------------------------------------------
   // This method prints a formatted table with the odometer reading,
   // gallons filled, and cost of filling for up to five records.
   // params: (none)
   //--------------------------------------------------------------------
   void PrintTable()
   {
      cout << "  Odometer  Gallons  Cost   MPG    Cents/mile" << endl;
      if (numRecs > 0)
      {
         cout << setw(OD_WIDTH) << odometer[0] << setw(GAL_WIDTH) 
              << gallons[0] << setw(COST_WIDTH) << cost[0] << endl;
         for (int i = 1; i < numRecs; i++)
         {
            cout << setw(OD_WIDTH) << odometer[i] << setw(GAL_WIDTH) 
                 << gallons[i] << setw(COST_WIDTH) << cost[i] 
                 << setw(OD_WIDTH) 
                 << ( odometer[i] - odometer[i - 1] ) / gallons[i]
                 << setw (OD_WIDTH) << cost[i] * CENTS_PER_DOLLAR 
                 / (odometer[i] - odometer[i - 1] ) << endl;
         }
      }
   }
};

void ProcessCommandForFleetCar(FleetCar & car, CommandType command, 
                               CarID_Type carID);

int main()
{
   FleetCar car1, car2, car3;
   char cmd;
   int id;
   cout << fixed << showpoint << setprecision(2);

   cin >> cmd >> id;
   
   while (cin)
   { 
      CommandType command = CommandType(cmd);
      CarID_Type carID = CarID_Type(id);
      switch (carID) //identifies the car from the id number
      {
         case ID_CAR1: ProcessCommandForFleetCar(car1, command, carID);
                       break;
         case ID_CAR2: ProcessCommandForFleetCar(car2, command, carID);
                       break;
         case ID_CAR3: ProcessCommandForFleetCar(car3, command, carID);
                       break;
      }

      cin >> cmd >> id;
   }

   cout << "Normal Termination of Program 5.";
   return 0;
}

//-----------------------------------------------------------------------
// This function uses a switch statements to call methods for the 
// FleetCar variable based on what command character was entered.
// params: (inout, in, in)
//-----------------------------------------------------------------------
void ProcessCommandForFleetCar(FleetCar & car, CommandType command, 
                               CarID_Type carID)
{
   switch(command) //calls methods for each command
   { 
      case ADD_CMD: 
         car.AddRecord();
         cout << "Record added for fleet car with ID " << carID << endl;
         break;
      case CENTS_PER_MILE_CMD: 
         cout << "Cents per mile for Car with ID " << carID << " is " 
              << car.CentsPerMile() << endl;
         break;
      case MPG_CMD: 
         cout << "MPG for Car with ID " << carID << " is " 
              << car.MilesPerGallon() << endl;
         break;
      case PRICE_PER_GAL_CMD: 
         cout << "Price per gallon for Car with ID " << carID << " is " 
              << car.PricePerGallon() << endl;
         break;
      case TABLE_PRINT_CMD: 
         cout << "Records for Car with ID " << carID << endl;
         car.PrintTable();
         break;
      default: 
         cout << "Bad command!" << endl;
         break;
   }

   return;
}