/*  Program: Tic Tac Toe
Programmer: Jegor Kharlamov
PNumber: P14148686
Date: 26/11/2014 */

#include <string>
#include <iostream>

using namespace std;

void PlayerNames();
void drawBoard();
void PlayerTurn();
void resetBoard();
int WhosTurn();
void Winner();

const int g_kiBoardsize = 3; // used to dictate board size to avoid overflow errors
int g_iPlayer = 1; // Starting player initialised and set to 1
char g_acBoard[g_kiBoardsize][g_kiBoardsize]; // 2D array used to represent gameboard
string g_sPlayer1Name; // Variable which holds player 1 name
string g_sPlayer2Name; // Variable which holds player 2 name
string g_scurrentPlayer; // Variable which stores the current players name

int main() // Plays and Loops games of Tic Tac Toe
{
	PlayerNames();
	g_scurrentPlayer = g_sPlayer1Name;
	resetBoard();
	drawBoard();
	PlayerTurn();
	system("PAUSE");
	return 0;
}

void PlayerNames() // Allows players to assign names
{
	cout << "Player 1 Name:" << endl;
	cin >>  g_sPlayer1Name;
	cout << "Player 2 Name:" << endl;
	cin >> g_sPlayer2Name;
}

void drawBoard() // Draws the game board to the screen
{
	while (true)
	{
		system("CLS"); // Clears screen

		//Builds board

		cout << "It's " << g_scurrentPlayer << "'s turn" << endl << endl;
		cout << "  "; // Inital spacing
		for( int iX=0; iX < g_kiBoardsize; iX++)
		{
			cout << " " << iX + 1 << "  "; // Top Numbers
		}
		cout << endl;
		cout << " "; 
		for(int iX=0; iX < g_kiBoardsize; iX++)
		{
			cout << "+---"; // Top line
		}
		cout << "+" << endl; // Final plus
		for(int iY=0; iY < g_kiBoardsize; iY++)
		{
			cout << iY + 1; // Displays side numbers
			for(int iX=0; iX < g_kiBoardsize; iX++)
			{
				cout << "| " << g_acBoard[iX][iY] << " "; // Places array inside grid
			}
			cout << "|" << endl;
			cout << " ";
			for(int iX=0; iX < g_kiBoardsize; iX++)
			{
				cout << "+---"; // Draws last lines
			}
			cout << "+" << endl; // Final plus
		}
		cout << endl;
		Winner(); // Checks if the player who just played as won
		PlayerTurn(); // Changes player turn
	}
}

void PlayerTurn() // Let the players take their turns
{
	int iXchoice;
	int iYchoice;
	cout << "Select X position: ";
	cin >> iXchoice; // Asks for X postion
	
	if (iXchoice > 3 || iXchoice < 1) // Ensures possition is valid
	{
		cout << endl << "X position must be between between 1 and 3" << endl << endl; // Tells player to enter valid value if invalid value given
		system("PAUSE");
	}
	else
	{
		cout << "Select Y position: "; // If valid asks for Y postion
		cin >> iYchoice;
		if (iYchoice > 3 || iYchoice < 1)  // Checks Y position is also valid
		{
			cout << endl << "Y position must be between between 1 and 3" << endl << endl; 
			system("PAUSE");
		}
		else
		{
			if (g_acBoard[iXchoice-1][iYchoice-1] == ' ') // Checks that the space has not already been taken by other player
			{
				if (g_iPlayer == 1) // Decides to either place and X or a 0 depending on what player it is.
				{
					g_acBoard[iXchoice-1][iYchoice-1] = 'X'; // Places X
				}
				else if (g_iPlayer == 2)
				{
					g_acBoard[iXchoice-1][iYchoice-1] = '0'; // Places 0
				}
			WhosTurn(); // Switches player
			}
			else
			{
				cout << endl << "That space is taken. Please enter an empty space." << endl << endl; // Tells player space is already taken and asks to pick another.
				system("PAUSE");
			}
		}
	}
}

int WhosTurn() // Changes the players turns and associated names when run
{
	if (g_iPlayer == 1)
	{
		g_iPlayer = 2;
		g_scurrentPlayer = g_sPlayer2Name;

	}
	else if (g_iPlayer == 2)
	{
		g_iPlayer = 1;
		g_scurrentPlayer = g_sPlayer1Name;
	}
	return g_iPlayer;
}

void resetBoard() // Resets the board
{
	for(int iY=0; iY < g_kiBoardsize; iY++) // Go though all values...
		{
			for(int iX=0; iX < g_kiBoardsize; iX++)
			{
				g_acBoard[iX][iY] = ' '; // And reset them to empty
			}
		}
}

void Winner() // Checks if a player has won
{
	char cCheck; // Used to check against for player victory 

	for (int i = 0; i < 2; i++) // Runs for both 0s and Xs
	{
		if (i == 0)
		{
			cCheck = 'X'; // Check for line of X
		}
		else
		{
			cCheck = '0'; // Check for line of 0s
		}

		if((g_acBoard[0][0] == cCheck && g_acBoard[0][1] == cCheck && g_acBoard[0][2] == cCheck|| // Line Top Row
			g_acBoard[1][0] == cCheck && g_acBoard[1][1] == cCheck && g_acBoard[2][2] == cCheck|| // Line Middle Row
			g_acBoard[2][0] == cCheck && g_acBoard[2][1] == cCheck && g_acBoard[2][2] == cCheck|| // Line Bottom Row
			g_acBoard[0][0] == cCheck && g_acBoard[1][0] == cCheck && g_acBoard[2][0] == cCheck|| // Line Left Column
			g_acBoard[1][0] == cCheck && g_acBoard[1][1] == cCheck && g_acBoard[1][2] == cCheck|| // Line Middle Column
			g_acBoard[0][2] == cCheck && g_acBoard[1][2] == cCheck && g_acBoard[2][2] == cCheck|| // Line Right Column
			g_acBoard[0][2] == cCheck && g_acBoard[1][1] == cCheck && g_acBoard[2][0] == cCheck|| // Line Diagonally Right
			g_acBoard[0][0] == cCheck && g_acBoard[1][1] == cCheck && g_acBoard[2][2] == cCheck)) // Line Diagonally Left
		{
			WhosTurn(); 
			cout << g_scurrentPlayer << " wins!! " << endl << endl; // Displays winner

			system("PAUSE");
			resetBoard(); // Waits for prompt then restarts board
			drawBoard();
		}

		//Checks to see if board has been filled when game is a tie
		if (g_acBoard[0][0] != ' ' && g_acBoard[0][1] != ' ' && g_acBoard[0][2] != ' ' &&
			g_acBoard[1][0] != ' ' && g_acBoard[1][1] != ' ' && g_acBoard[1][2] != ' ' &&
			g_acBoard[2][0] != ' ' && g_acBoard[2][1] != ' ' && g_acBoard[2][2] != ' ')
		{
			// If game ends as a tie: Reset the board
			cout << endl << "The game is a tie. Press any button to restart" << endl << endl;
			system("PAUSE");
			resetBoard();
			drawBoard();
		}

	}
}
