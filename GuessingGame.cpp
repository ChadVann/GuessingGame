/******************************************************************************
* Programmer: Chad Thornton
*
* Assigned Project Number: 5A
*
*
* Revision     Date                        Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     02/02/2016  Initial Release
*   X.Y     MM/DD/YYYY  ** Short, 1 line description of changes to program  **
*
*
* Program Inputs
* --------------
*  Device                              Description
* --------  -------------------------------------------------------------------
* Keyboard  Accepts "yes/no" inputs from the user, and also intergers while trying
*			to guess the random number.
*
*
* Program Outputs
* --------
*  Device                            Description
* --------  -------------------------------------------------------------------
* Monitor   Displays text on the screen asking if the user wants to play a game.
*			Will then display that it is thinking of number between 1 and 100
*			as the user guesses the number it will say higher or lower. When
*			guessed correctly it will congratulate the user and ask if they want
*			to play again.
*
*
* File Methods
* ------------
*     Name                             Description
* ------------  ---------------------------------------------------------------
* main          Program entry point method
* **** Add name and description of any other methods defined in this file ****
*
*******************************************************************************
*/
// External Definition files
// The first inclusion file is required by the Visual Studio complier and
// MUST be first in the "include" files list
#include "stdafx.h"  // Defines IDE required "pre-compiled" definition files

#include <iostream>  // Defines objects and classes used for stream I/O

// Namespaces utilized in this program
using namespace std; // Announces to the compiler that members of the namespace
                     // "std" are utilized in this program

// Method Prototypes
// -----------------
void toLower(string&);
char toLower(char);


/******************************************************************************
* Method: main()
* 
* Method Description
* ------------------
* ** Program will ask the user if they want to play a game. The user is
* ** then expected to respond "yes" or "no". If "no" the program will end.
* ** If the user responds with "yes" then it will display on the console
* ** that they are playing a guessing game between the numbers of 1 to 100.
* ** As the user guesses the program will display on the console whether the
* ** number guesses is too high or too low. Once the user can guessed the correct
* ** number the program will congratulate the user, show the number of guesses it
* ** took to get the correct number, and ask if they want to play again. If yes
* ** the program will run again with a new number and reset the count for number of
* ** guesses. If no then the program will end.
*
*
* Preconditions
* -------------
* None
*
*
* Method Arguments
* ----------------
*   Type        Name                        Description
* --------  -------------  ----------------------------------------------------
*                        *** No Arguments supplied ***
*
*
* Return Value
* ------------
*   Type                              Description
* --------  -------------------------------------------------------------------
* int       Program execution status: 0 - No errors
*
*
* Invoked Methods
* ---------------
*     Name                             Description
* ------------  ---------------------------------------------------------------
*                           *** No methods invoked ***
*
*******************************************************************************
*/
int main()          
{
	// Constant "const" Value Declarations
	const int NO_ERRORS = 0;  // Program Execution Status: No errors

	// Initialized Variable Declarations
	int programStatus = NO_ERRORS;  // Assume no program execution errors

	// Uninitialized Variable Declarations
	const int MIN_NUM = 1,
		MAX_NUM = 100;

	string playGame,
		playAgain;
	bool exitProgram = false;
	int randNum,
		userAnswer;
	randNum = time(NULL);
	srand(randNum);

	cout << "Hello! Do you want to play a game?...(Yes/No)" << endl;
	cin >> playGame;
	toLower(playGame);

	while ((playGame != "yes") && (playGame != "no"))
	{
		cout << "Oops, looks like that wasn't a valid option.\nDo you want to play a game?...(Yes/No)" << endl;
		cin >> playGame;
		toLower(playGame);
	}
	if (playGame == "yes")
	{
		cout << "Excellent!\nWe will be playing a guessing game." << endl;
		do
		{
			int userGuesses = 0;
			randNum = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;
			cout << "I'm thinking of a number between 1 and 100." << endl;
			cout << "Can you guess what is it?\n(Input a number followed by Enter)\n(If you wish to exit the program at anytime enter '0'.)" << endl;
			cin >> userAnswer;
			while ((userAnswer != randNum) && (userAnswer != 0))
			{
				if (userAnswer > randNum)
				{
					cout << "Too high. Try again." << endl;
					userGuesses++;
					cin >> userAnswer;
				}
				else if ((userAnswer < randNum) && (userAnswer != 0))
				{
					cout << "Too low. Try again." << endl;
					userGuesses++;
					cin >> userAnswer;
				}
			}
			if (userAnswer == randNum)
			{
				userGuesses++;
				cout << "Congratulations. You figured out my number." << endl;
				cout << "Total guesses: " << userGuesses << endl;
				cout << "Would you like to play again? (Yes/No)" << endl;
				cin >> playAgain;
				toLower(playAgain);
				while ((playAgain != "yes") && (playAgain != "no"))
				{
					cout << "Oops, that wasn't a valid answer.\nWould you like to play again? (Yes/No)" << endl;
					cin >> playAgain;
					toLower(playAgain);
				}
			}
		} while ((playAgain == "yes") && (userAnswer != 0));
	}
	cout << "Thank you! Have a nice day!" << endl;

	// This prevents the Console Window from closing during debug mode using
	// the Visual Studio IDE.
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return programStatus;

}	// End Method: main()

void toLower(string& str)
{
	for (int index = 0; index < str.length(); ++index)
		str[index] = toLower(str[index]);
}

char toLower(char chr)
{
	if (chr >= 'A' && chr <= 'Z')
	{
		unsigned short includeBit = 'a' - 'A';
		chr = chr | includeBit;
	}

	return chr;
}