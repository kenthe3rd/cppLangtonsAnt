/* ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** **
 *Ken Hall	1/21/2017
 *
 *CS 162 400	Project 1
 *:::LANGTON'S ANT MAIN FUNCTION:::
 ** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** * */
#include <unistd.h>	//included to allow sleeps between moves
#include <cstdlib>	//included to use rand() for random #s
#include <time.h>	//time for seeding random num
#include "menu.hpp"
#include "ant.hpp"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	srand(time(NULL));
	Menu playPrompt("Begin game","Random starting location mode", "Quit");
	int userChoice = 0;

	while(userChoice != 3)
	{
		//set all arguments to defaults
		int rowsArg = 0;
		int columnsArg = 0;
		int stepsArg = 0;
		int startRowArg = -1;
		int startColumnArg = -1;


		//prompt player to begin simulation or quit
		playPrompt.displayMenu();



		//enforce valid input
		userChoice = playPrompt.enforceValidInput();
		
		if(userChoice == 3)
		{	
			//choice indicates user elects to quit
			return 0;
		}



		//user did not elect to quit; gather simulation info
		cout << "Please enter number of rows." << endl;
	
		while(rowsArg < 2)
		{
			cin >> rowsArg;
			if(cin.fail())
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Invalid input. Please try again." 
				<< endl;
			}
			else if(rowsArg < 2)
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Input outside acceptable bounds. "
				<< "Please enter a number greater than or "
				<< "equal to 2." << endl;
			}
		}

		cout << "Please enter number of columns." << endl;
		while(columnsArg < 2)
		{
			cin >> columnsArg;
			if(cin.fail())
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Invalid input. Please try again." 
				<< endl;
			}
			else if(columnsArg < 2)
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Input outside acceptable bounds. "
				<< "Please enter a number greater than or "
				<< "equal to 2." << endl;
			}
		}

		cout << "Please enter number of steps to run." << endl;
		while(stepsArg < 1)
		{
			cin >> stepsArg;
			if(cin.fail())
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Invalid input. Please try again." 
				<< endl;
			}
			else if(stepsArg < 1)
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Input outside acceptable bounds. "
				<< "Please enter a number greater than or "
				<< "equal to 1." << endl;
			}
		}

		if(userChoice != 2)
		{
			//not running in random start; get start from user
			//get starting row
			cout << "Please enter starting row." << endl;
			while(startRowArg < 0 || startRowArg > (rowsArg - 1))
			{
				cin >> startRowArg;
				if(cin.fail())
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << "Invalid input. Try again." 
					<< endl;
				}
				else if(startRowArg < 0 || 
				startRowArg > (rowsArg - 1))
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << "Input outside bounds. "
					<< "Enter a number greater than or "
					<< "equal to 0, and less than or equal "
					<< "to the number of rows minus 1." 
					<< endl;
				}
			}
			//get starting column
			cout << "Please enter starting column." << endl;
			while(startColumnArg < 0 || 
			startColumnArg > (columnsArg - 1))
			{
				cin >> startColumnArg;
				if(cin.fail())
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << "Invalid input. Try again." 
					<< endl;
				}
				else if(startColumnArg < 0 || 
				startColumnArg > (columnsArg - 1))
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << "Input outside bounds. "
					<< "Enter a number greater than or "
					<< "equal to 0, and less than or equal "
					<< "to the number of columns minus 1." 
					<< endl;
				}
			}
		}
		
		if(userChoice == 2)
		{
			//running in random start mode
			//lower bound = 0
			//upper bound = #rows/#columns - 1
			startColumnArg = (rand() % (columnsArg - 1));
			startRowArg = (rand() % (rowsArg - 1));
			
		}

		//run simulation
		Ant mainAnt	(rowsArg, 
				columnsArg,
				stepsArg,
				startRowArg,
				startColumnArg);

		//show initial board state
		mainAnt.printBoard();

		//for each step, pause a bit, then move, then print the board
		//again
		for(int i=0; i < stepsArg; i++)
		{
			usleep(500000);
			mainAnt.makeMove();
			mainAnt.printBoard();
		}
		
	}
	return 0;
}
