//------------------------------------------------------------------------
//
// Name:    Zack Neefe
//
// Course:  CS 1430, Section 2
//
// Purpose: This program plays a craps game with a random number
//          generator based on the time on a clock.
//
// Input:   -the time, an integer
//          -the bet, an integer
//
// Output:  -whether the player wins or loses the crapshoot
//          -the roll of the dice
//          -the amount of money remaining in the player's pocketbook
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
#include <cstdlib>

using namespace std;

const int SIDES_PER_DIE = 6;
const int INITIAL_MONEY = 1000;
const int LOWEST_CLOCK = 1000;
const int HIGHEST_CLOCK = 2359;
const int NUM_DICE = 2;
const int SNAKE_EYES = 2;      // a roll of 2
const int TREY = 3;            // a roll of 3
const int SEVENS = 7;          // a roll of 7
const int LUCKY11 = 11;        // a roll of 11
const int BOXCARS = 12;        // a roll of 12

int RollDice(int numDice);
bool ShooterWins();
void RollFirstRoll(int& point, bool& shooterWins, bool& shooterLoses);
void RollsUntilPointOr7(int point, bool& shooterWins);
void OutputResult(bool shooterWins, bool shooterLoses, 
	              int& pocketbook, int& bet);
void Initialize(int& time, int& bet, int pocketbook);

int main()
{
   int time, pocketbook, bet;
   bool shooterWins, shooterLoses;  
   pocketbook = INITIAL_MONEY;

   Initialize(time, bet, pocketbook);

   while (cin && pocketbook != 0)       // runs while the player wants to
   {                                    // bet and still has money
	  shooterWins = false;  // set the bool variables to false
	  shooterLoses = false; // so as to not cause false positives
	   
	  cout << "Your bet is " << bet << endl;

	  if (ShooterWins())
		 shooterWins = true;
	  else
		 shooterLoses = true;

	  OutputResult(shooterWins, shooterLoses, pocketbook, bet);
   }

   cout << endl << endl << "Good night.  You have " << pocketbook;
   cout << " dollars now." << endl;  // final message to player

   return 0;
}

//-----------------------------------------------------------------------
// This function sets up the initial variables and outputs.
// params: (out, out, in)
//-----------------------------------------------------------------------
void Initialize(int& time, int& bet, int pocketbook)
{
   cout << "What does the clock say? ";
   cin >> time;
   srand(time);  // intitializing the random number generator
   cout << "You have " << pocketbook << " dollars." << endl;
   cout << "How much will you bet? ";
   cin >> bet;
   bet = abs(bet);  // making a negative bet positive if necessary
   if (bet > pocketbook)
	  bet = pocketbook;  // condition for a bet greater than what the 
                         // player owns
   return;
}

//-----------------------------------------------------------------------
// This function rolls two dice and returns the sum of the rolls.
// params: (in)
//-----------------------------------------------------------------------
int RollDice(int numDice)
{
   int roll = 0;
   
   for (int i = 0; i < numDice; i++)
   { 
	  int die;
      die = 1 + rand() % SIDES_PER_DIE; // use RNG to roll the dice twice
	  roll = roll + die;
   }

   return roll;
}

//-----------------------------------------------------------------------
// This function runs most of the program, including the first roll and 
// the subsequent rolls until 7 or the point is reached and returns
// a boolean condition showing whether the player won or lost
// params: ()
//-----------------------------------------------------------------------
bool ShooterWins()
{
   bool result, shooterWins, shooterLoses;
   int point;
   RollFirstRoll(point, shooterWins, shooterLoses);

   if (shooterWins) // condition for shooter winning immediately
      result = true;
   else if (shooterLoses) // condition for shooter losing immediately
	  result = false;
   else // condition to continue rolling
   { 
      RollsUntilPointOr7(point, shooterWins);
	  if (shooterWins)
		  result = true;
	  else
		  result = false;
   }
   return result;
}

//-----------------------------------------------------------------------
// This function rolls the first roll of a set and detects if the roll is
// an automatic win or loss
// params: (out, out, out)
//-----------------------------------------------------------------------
void RollFirstRoll(int& point, bool& shooterWins, bool& shooterLoses)
{
   int numDice = NUM_DICE;
   point = RollDice(numDice); // first roll set as the shooter's point
   cout << "First Roll " << point << endl;

   shooterWins = false;  // set the bool variables to false so as to not 
   shooterLoses = false; // create false positives

   if (point == SEVENS || point == LUCKY11)
	  shooterWins = true;                // condition for immediate win
   else if (point == SNAKE_EYES || point == TREY || point == BOXCARS)
	  shooterLoses = true;               // condition for immediate loss

   return;
}

//-----------------------------------------------------------------------
// This function rolls the dice after the initial roll until the dice
// show the shooter's point or 7
// params: (in, out)
//-----------------------------------------------------------------------
void RollsUntilPointOr7(int point, bool& shooterWins)
{
   cout << "Your point is " << point << endl;
   int numDice = NUM_DICE;
   int roll = 0;

   while (roll != point && roll != SEVENS) // stops rolling when the
   {                                       // player wins or loses
	  roll = RollDice(numDice);         // rolls dice and outputs result
	  cout << "Rolled " << roll << endl;
   }

   if (roll == point)     // checks to output proper result for win/loss
	  shooterWins = true;
   else if (roll == SEVENS)
	  shooterWins = false;

   return;
}

//-----------------------------------------------------------------------
// This function outputs the result of a run, whether the shooter wins or
// loses.
// params: (in, in, inout, inout)
//-----------------------------------------------------------------------
void OutputResult(bool shooterWins, bool shooterLoses,
	              int& pocketbook, int& bet)
{
   if (shooterWins) // output for a shooter win
   {
	  cout << "You WIN!" << endl << endl;
	  pocketbook = pocketbook + bet;
   }
   else if (shooterLoses) // output for a shooter loss
   {
	  cout << "You ****LOSE**** :-(" << endl << endl;
	  pocketbook = pocketbook - bet;
   }

   if (pocketbook > 0) // reads in another bet if the player has money
   {
	  cout << "You have " << pocketbook << " dollars." << endl;
	  cout << "How much will you bet? ";
	  cin >> bet;
	  bet = abs(bet);
	  if (bet > pocketbook)
		 bet = pocketbook;
   }

   return;
}