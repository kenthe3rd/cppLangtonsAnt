/* ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** **
 *Ken Hall	1/21/2017
 *
 *CS 162 400	Project 1
 *:::ANT CLASS IMPLEMENTATION FILE:::
 ** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** * */

#include "ant.hpp"
#include <iostream>
using std::cout;
using std::endl;

/*****************************************************************************
 *CONSTRUCTOR
 ****************************************************************************/

Ant::Ant(
	int rowsArg, 
	int columnsArg, 
	int stepsArg, 
	int startRowArg, 
	int startColumnArg
	)
{

	//build the board
	rows = rowsArg;
	columns = columnsArg;
	steps = stepsArg;
	startRow = startRowArg;
	startColumn = startColumnArg;
	currentRow = startRow;
	currentColumn = startColumn;
	arrayOfRows = new char*[rows];
	for(int i=0; i<rows; i++)
	{
		arrayOfRows[i] = new char[columns];
	}


	//make all of the spaces "white" ( )
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<columns; j++)
		{
			(arrayOfRows[i])[j] = ' ';
		}
	}	

	//place ant on the board
	(arrayOfRows[startRow])[startColumn] = '*';

	
	
		
}


/*****************************************************************************
 *MAKE_MOVE:  moves the ant and updates the board appropriately
 ****************************************************************************/
void Ant::makeMove()
{
	movedThisTurn = false;
	//check to see if ant is about to step out of bounds, and turn it
	//around if it is about to step out of bounds
	
	//check if ant is at top and about to step 'up'
	if(antOrientation == '^' && ((currentRow - 1) < 0))
	{
		antOrientation = 'V';
	}

	//check if ant is at bottom and about to step 'down'
	if(antOrientation == 'V' && ((currentRow + 1) == rows))
	{
		antOrientation = '^';
	}

	//check if ant is at rightmost and about to step 'right'
	if(antOrientation == '>' && ((currentColumn + 1) == columns))
	{
		antOrientation = '<';
	}

	//check if ant is at leftmost and about to step 'left'
	if(antOrientation == '<' && ((currentColumn - 1) < 0))
	{
		antOrientation = '>';
	}

	
	//restore the square the ant moves off of from squareUnderAnt
	//update squareUnderAnt to the correct color for square being moved to
	//move ant based on orientation and update orientation
	

	(arrayOfRows[currentRow])[currentColumn] = squareUnderAnt;

	if(antOrientation == '^' && !movedThisTurn)
	{
		if(arrayOfRows[(currentRow - 1)][currentColumn] == ' ')
		{
			squareUnderAnt = '#';
			antOrientation = '>';
			arrayOfRows[(currentRow - 1)][currentColumn] = '*';
			currentRow--;
		}
		else if(arrayOfRows[(currentRow - 1)][currentColumn] == '#')
		{
			squareUnderAnt = ' ';
			antOrientation = '<';
			arrayOfRows[(currentRow - 1)][currentColumn] = '*';
			currentRow--;
		}
		movedThisTurn = true;
	}

	if(antOrientation == 'V' && !movedThisTurn)
	{
		if(arrayOfRows[(currentRow + 1)][currentColumn] == ' ')
		{
			squareUnderAnt = '#';
			antOrientation = '<';
			arrayOfRows[(currentRow + 1)][currentColumn] = '*';
			currentRow++;
		}
		else if(arrayOfRows[(currentRow + 1)][currentColumn] == '#')
		{
			squareUnderAnt = ' ';
			antOrientation = '>';
			arrayOfRows[(currentRow + 1)][currentColumn] = '*';
			currentRow++;
		}
		movedThisTurn = true;
	}

	if(antOrientation == '>' && !movedThisTurn)
	{
		if(arrayOfRows[(currentRow)][(currentColumn + 1)] == ' ')
		{
			squareUnderAnt = '#';
			antOrientation = 'V';
			arrayOfRows[(currentRow)][(currentColumn + 1)] = '*';
			currentColumn++;
		}
		else if(arrayOfRows[(currentRow)][(currentColumn + 1)] == '#')
		{
			squareUnderAnt = ' ';
			antOrientation = '^';
			arrayOfRows[(currentRow)][(currentColumn + 1)] = '*';
			currentColumn++;
		}
		movedThisTurn = true;
	}

	if(antOrientation == '<' && !movedThisTurn)
	{
		if(arrayOfRows[(currentRow)][(currentColumn - 1)] == ' ')
		{
			squareUnderAnt = '#';
			antOrientation = '^';
			arrayOfRows[(currentRow)][currentColumn - 1] = '*';
			currentColumn--;
		}
		else if(arrayOfRows[(currentRow)][(currentColumn - 1)] == '#')
		{
			squareUnderAnt = ' ';
			antOrientation = 'V';
			arrayOfRows[currentRow][currentColumn - 1] = '*';
			currentColumn--;
		}
		movedThisTurn = true;
	}
}

/*****************************************************************************
 *PRINT_BOARD: provids a visual display of the current board state
 ****************************************************************************/

void Ant::printBoard()
{
	cout << " ";
	for(int i=0; i<columns; i++)
	{
		cout << "=";
	}
	cout << endl;

	for(int i=0; i<rows; i++)
	{
		cout << "|";
		for(int j=0; j<columns; j++)
		{
			cout << (arrayOfRows[i])[j];
			//if at end of row, drop to next line
			if(j == (columns-1))
			{
				cout << "|" <<  endl;
			}
		}
	}
	cout << " ";
	for(int i=0; i<columns; i++)
	{
		cout << "=";
	}
	cout << endl;
}


/*****************************************************************************
 *DESTRUCTOR
 ****************************************************************************/

Ant::~Ant()
{
	for(int i=0; i<rows; i++)
	{
		delete[] arrayOfRows[i];
	}
	delete[] arrayOfRows;
}
