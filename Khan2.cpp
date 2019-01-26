/**************************************************************************
*                                                                         *
*     Program Filename:  Khan2.cpp                                        *
*     Author          :  Sarim Khan                                       *
*     Date Written    :  September 28, 2017                               *
*     Purpose         :  To simulate a knight on a chessboard             *
*     Input from      :  Keyboard                                         *
*     Output to       :  Screen                                           *
*                                                                         *
**************************************************************************/
#include <iostream>
using namespace std;
#include <conio.h>
#include <iomanip>

typedef int chessBoard[12][12];
typedef int checkPad[12][12];

void setBorders(chessBoard);
void setCheckPad(checkPad);
void printBoard(checkPad);
void simulateMove(chessBoard, checkPad);
void endProgram();

int main()
{
	chessBoard x;
	setBorders(x);
	//initialize bord with borders

	checkPad y;
	setCheckPad(y);
	//create checkpad and set to 0 

	simulateMove(x, y);
	//simulate knights move 
	printBoard(y);
	//print board 
	endProgram();
}
//end main

void simulateMove(chessBoard x, checkPad y)
{
	int row, column;
	bool abletoMove = true;
	int counter = 1;
	//initialize variabls 

	cout << endl << "Please enter the starting point for the row: ";
	cin >> row;
	cout << endl << "Please enter the starting point for the column: ";
	cin >> column;
	//prompt user for initial move 

	row += 1;
	column += 1;

	x[row][column] = 1;
	y[row][column] = counter;
	counter++;

	while (abletoMove)
	{
		if (x[row - 2][column + 1] == 0)
		{
			row += -2;
			column += 1;
			x[row][column] = 1;
			y[row][column] = counter;
			counter++;
		}
		//move 1 
		else if (x[row - 1][column + 2] == 0)
		{
			row += -1;
			column += 2;
			x[row][column] = 1;
			y[row][column] = counter;
			counter++;
		}
		//move 2
		else if (x[row + 1][column + 2] == 0)
		{
			row += 1;
			column += 2;
			x[row][column] = 1;
			y[row][column] = counter;
			counter++;
		}
		//move 3
		else if (x[row + 2][column + 1] == 0)
		{
			row += 2;
			column += 1;
			x[row][column] = 1;
			y[row][column] = counter;
			counter++;
		}
		//move 4
		else if (x[row + 2][column - 1] == 0)
		{
			row += 2;
			column += -1;
			x[row][column] = 1;
			y[row][column] = counter;
			counter++;
		}
		//move 5
		else if (x[row + 1][column - 2] == 0)
		{
			row += 1;
			column += -2;
			x[row][column] = 1;
			y[row][column] = counter;
			counter++;
		}
		//move 6
		else if (x[row - 1][column - 2] == 0)
		{
			row += -1;
			column += -2;
			x[row][column] = 1;
			y[row][column] = counter;
			counter++;
		}
		//move 7
		else if (x[row - 2][column - 1] == 0)
		{
			row += -2;
			column += -1;
			x[row][column] = 1;
			y[row][column] = counter;
			counter++;
		}
		//move 8 
		else
		{
			abletoMove = false;
		}
		//break loop if no move available 

	}
	//end while
}
//end simulateMove


void setBorders(chessBoard x)
{
	int i, j;

	for (i = 0; i <= 1; i++)
	{
		for (j = 0; j <= 11; j++)
		{
			x[i][j] = -1;
		}
	}
	//end for 

	for (i = 2; i <= 9; i++)
	{
		for (j = 2; j <= 9; j++)
		{
			x[i][j] = 0;
		}
	}
	//end for 

	for (i = 10; i <= 11; i++)
	{
		for (j = 0; j <= 11; j++)
		{
			x[i][j] = -1;
		}
	}
	//end for 

	for (i = 0; i <= 11; i++)
	{
		for (j = 0; j <= 1; j++)
		{
			x[i][j] = -1;
		}
	}
	//end for 
	for (i = 0; i <= 11; i++)
	{
		for (j = 10; j <= 11; j++)
		{
			x[i][j] = -1;
		}
	}
	//end for 
	return;
}
//end set borders

void setCheckPad(checkPad x)
{
	int i, j;

	for (i = 0; i <= 11; i++)
	{
		for (j = 0; j <= 11; j++)
		{
			x[i][j] = 0;
		}
	}
	//end for 
}
//end setCheckPad
void printBoard(checkPad x)
{
	int j, k;

	for (j = 2; j <= 9; j++)
	{
		cout << endl;
		for (k = 2; k <= 9; k++)
		{
			if (x[j][k] == 0)
			{
				cout << setfill('0') << setw(3) << "0 ";
			}
			else
			{
				cout << setfill('0') << setw(2) << x[j][k] << " ";
			}
		}
		//end for 
	}
	//end for 
}
//end printBoard

void endProgram()
{
	cout << endl << endl << "Please press enter to continue";
	cin.ignore();
	cin.get();
}
//end endProgram 