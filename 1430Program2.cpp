//------------------------------------------------------------------------
//
// Name:    Zack Neefe
//
// Course:  CS 1430, Section 2
//
// Purpose: This program reads data from a GPS unit and displays the
//          highest and lowest speed for sprints recorded in a time 
//          period as well as the average speed for each sprint and the
//          average speed while not sprinting.
//
// Input:   Lines of data from the GPS unit
//
// Output:  A message if no sprints are recorded
//          Average speed of each sprint
//          Highest average speed of sprints
//          Lowest average speed of sprints
//          Number of sprints recorded
//          Average speed while not sprinting
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

const double KNOTS_TO_MPH = 1.15077945;
const double SPEED_OF_LIGHT = 670616629.4;

// Function Prototypes
void VariableAssignment(double&, double&, double&, double&, int&);
void StartSprint(double&, double&, string&);
void WhileSprinting(string, string&, double&, double&, double&, string&);
void SpeedCalculations(double&, double&, double&);
double InputSpeed(double&);
void JunkLines(string);
void AverageSprint(double, double, int&, double&, double&);
void DataTypeReset(string&, string&, string);
void OutputSprints(int, double, double);
void AverageNotSprint(double, double);
//------------------------------------------------------------------------
int main()
{
   string markCheck, endCheck, dataType, junkData;
   double speed, totalSpeed, sprintSpeed, totalSprintSpeed, sprintLines;
   double speedLines, maxSprint, minSprint;
   int sprintCount;

   // Gives variables that need to start with values their values
   VariableAssignment(maxSprint, minSprint, speedLines, totalSpeed, 
	                  sprintCount);

   // Sets up the output so it looks correct
   cout << fixed << showpoint << setprecision(2);
   // Check for a sprint
   cin >> markCheck;

   // Loop so the program keeps running while the GPS sends data
   while (cin)
   {
	  // Condition for when a sprint is started
	  if (markCheck == "MARK")
	  {
		 // Setting up variables and input for a sprint
		 StartSprint(totalSprintSpeed, sprintLines, endCheck);

		 // Loop that reads the speed data for the sprint
		 WhileSprinting(endCheck, dataType, sprintSpeed, totalSprintSpeed, 
			            sprintLines, junkData);

		 // Calculations that average the sprint speed
		 AverageSprint(totalSprintSpeed, sprintLines, sprintCount, 
			           minSprint, maxSprint);

		 // Resets the dataType variable in order for the input to stay 
		 // aligned with the proper variables
		 DataTypeReset(markCheck, dataType, junkData);
	  }
	  // Condition that sets the data type ($GPRMC or $GPGLL) to its 
	  // appropriate variable
	  else
		 dataType = markCheck;

	  // Condition for the $GPRMC data type for calculating the speed 
	  // that is inputted
	  if (dataType == "$GPRMC")
	     SpeedCalculations(speed, totalSpeed, speedLines);

	  // Condition for the $GPGLL data type that junks the useless data
	  if (dataType == "$GPGLL")
		 JunkLines(junkData);

	  // Check for the mark of a sprint start
	  if (markCheck != "MARK")
	     cin >> markCheck;
   }
   
   // Outputs the number of sprints and the fastest and slowest sprint
   OutputSprints(sprintCount, maxSprint, minSprint);

   // Outputs the average speed while not sprinting
   AverageNotSprint(totalSpeed, speedLines);

   return 0;
}

//------------------------------------------------------------------------
// This function sets values to variables used throughout the program.
// params: (out, out, out, out, out)
//------------------------------------------------------------------------
void VariableAssignment(double& max, double& min, double& lines, 
	                    double& total, int& count)
{
   max = 0;
   min = SPEED_OF_LIGHT;
   lines = 0;
   total = 0;
   count = 0;

   return;
}

//------------------------------------------------------------------------
// This function resets sprints variables to zero and checks for the end 
// of a sprint.
// params: (out, out, out)
//------------------------------------------------------------------------
void StartSprint(double& total, double& lines, string& endCheck)
{
   total = 0;
   lines = 0;

   cin >> endCheck;

   return;
}

//------------------------------------------------------------------------
// This function is comprised of the sprinting while loop, which is used
// to get the speed lines of a sprint.
// params: (in, out, out, inout, inout, inout)
//------------------------------------------------------------------------
void WhileSprinting(string endCheck, string& dataType, 
	                double& sprintSpeed, double& totalSprintSpeed, 
	                double& sprintLines, string& junkData)
{
   while (endCheck != "END")
   {
	  dataType = endCheck;

	  if (dataType == "$GPRMC")
		 SpeedCalculations(sprintSpeed, totalSprintSpeed,
			sprintLines);

	  if (dataType == "$GPGLL")
		 JunkLines(junkData);

	  cin >> endCheck;
   }

   return;
}

//------------------------------------------------------------------------
// This function converts the speed to mph and adds the speed to the total
// speed as well as adding one to the lines of speed.
// params: (out, inout, inout)
//------------------------------------------------------------------------
void SpeedCalculations(double& speed, double& totalSpeed, double& lines)
{
   speed = InputSpeed(speed);

   speed = speed * KNOTS_TO_MPH;

   totalSpeed = totalSpeed + speed;
   lines++;

   return;
}

//------------------------------------------------------------------------
// This function sorts through the junk data from the GPS in order to 
// assign the speed to a variable.
// params: (out)
//------------------------------------------------------------------------
double InputSpeed(double& speed)
{
   string junkData;

   cin >> junkData >> junkData >> junkData >> junkData >> junkData;
   cin >> junkData >> speed >> junkData >> junkData >> junkData;
   cin >> junkData;

   return speed;
}

//------------------------------------------------------------------------
// This function throws away the data from a $GPGLL line.
// params: (in)
//------------------------------------------------------------------------
void JunkLines(string junkData)
{
   cin >> junkData >> junkData >> junkData >> junkData;
   cin >> junkData >> junkData;

   return;
}

//------------------------------------------------------------------------
// This function outputs the average speed from a sprint and assigns a 
// new fastest or slowest sprint, if applicable.
// params: (in, in, inout, inout, inout)
//------------------------------------------------------------------------
void AverageSprint(double total, double lines, int& count, double& min, 
	               double& max)
{
   if (total != 0 && lines != 0)
   {
	  count++;

	  cout << "Average for sprint " << count << ": ";
	  cout << total / lines << " mph" << endl;

	  if ((total / lines) < min)
		 min = total / lines;

	  if ((total / lines) > max)
		 max = total / lines;
   }

   return;
}

//------------------------------------------------------------------------
// This function checks for a mark, and if the input isn't a data type,
// resets the data type so as to not trigger a false positive.
// params: (out, out, in)
//------------------------------------------------------------------------
void DataTypeReset(string& markCheck, string& dataType, string junkData)
{
   cin >> markCheck;

   if (markCheck == "$GPRMC" || markCheck == "$GPGLL")
	  dataType = markCheck;
   else
	  dataType = junkData;

   return;
}

//------------------------------------------------------------------------
// This function outputs the number of sprints recorded as well as the 
// fastest and slowest sprint speeds, or, if there are no sprints, a 
// message indicating that.
// params: (in, in, in)
//------------------------------------------------------------------------
void OutputSprints(int count, double max, double min)
{
   if (count > 0)
   {
      cout << "You recorded " << count << " sprints." << endl;

      cout << "Highest average speed during sprints: " << max;
      cout << " mph." << endl;

      cout << "Lowest average speed during sprints:  " << min;
      cout << " mph." << endl;
   }
   else
	  cout << "No sprints recorded." << endl;

   return;
}

//------------------------------------------------------------------------
// This function outputs the average speed while not sprinting.
// params: (in, in)
//------------------------------------------------------------------------
void AverageNotSprint(double total, double lines)
{
   if (lines > 0)
   {
	  cout << "Average speed while not sprinting: ";
	  cout << total / lines << " mph." << endl;
   }
   else
	  cout << "No speeds recorded for non-sprinting times." << endl;

   return;
}