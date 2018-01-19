/* ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** **
 *Ken Hall	1/21/2017
 *
 *CS 162 400	Project 1
 *:::ANT CLASS HEADER FILE:::
 ** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** * */

#ifndef ANT_HPP
#define ANT_HPP

class Ant
{
	private:
		char antOrientation = '^'; // '^'=up 'V'=down '<'=left '>'=right 
		char** arrayOfRows = nullptr;
		char squareUnderAnt = ' ';
		bool movedThisTurn = false;//flag to enforce one move/turn
		int stepsToRun = 0;	//
		int rows = 0;		//
		int columns = 0;	////
		int steps = 0;		//////
		int startRow = 0;	///////////Board info//////
		int startColumn = 0;	//////
		int currentRow = 0;	////
		int currentColumn = 0;	//

	public:
		Ant(int numRows,
		int numColumns,
		int numStepts,
		int startingRow,
		int startingColumn);	//constructor

		void makeMove();
		void printBoard();
		
		~Ant();			//free memory here
};
#endif
