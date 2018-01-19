/* ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** **
 *Ken Hall	1/21/2017
 *
 *CS 162 400	Project 1
 *:::MENU IMPLEMENTATION FILE:::
 ** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** * */

#include "menu.hpp"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;

/*****************************************************************************
 *CONSTRUCTORS
 ****************************************************************************/

Menu::Menu(string arg1, string arg2)
{
	item1 = arg1;
	item2 = arg2;
}

Menu::Menu(string arg1, string arg2, string arg3)
{
	item1 = arg1;
	item2 = arg2;
	item3 = arg3;
}

Menu::Menu(string arg1, string arg2, string arg3, string arg4)
{
	item1 = arg1;
	item2 = arg2;
	item3 = arg3;
	item4 = arg4;
}

Menu::Menu(string arg1, string arg2, string arg3, string arg4, string arg5)
{
	item1 = arg1;
	item2 = arg2;
	item3 = arg3;
	item4 = arg4;
	item5 = arg5;
}



/*****************************************************************************
 *ENFORCE_VALID_INPUT: checks to see which of the menu member variables are not
 *empty strings, and adjusts range of acceptable inputs based on number of
 *member variables that are not empty strings
 ****************************************************************************/
int Menu::enforceValidInput()
{
	//reset userSelection to default
	userSelection = 0;
	
	//min menu size is 2, so we start checking with 3
	validInputs = 2;
	if(item3 != "")
	{
		validInputs++;			// =3
		if(item4 != "")
		{
			validInputs++;		// =4
			if(item5 != "")
			{
				validInputs++;	// =5
			}
		}
	}
	
	while(userSelection < 1 || userSelection > validInputs)
	{
		cin >> userSelection;
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Invalid input. Please try again." << endl;
		}
		else if(userSelection < 1 || userSelection > validInputs)
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Input outside of acceptable range. " << 
			"Please try again." << endl;	
		}
	}
	
	return userSelection;
}



/*****************************************************************************
 *DISPLAY_MENU: displays each item of a menu on a separate line, preceded by
 *the item#
 ****************************************************************************/
void Menu::displayMenu()
{
	cout << endl << endl;
	cout << "1: " << item1 << endl;
	cout << "2: " << item2 << endl;
	if(item3 != "")
	{
		cout << "3: " << item3 << endl;
	}
	if(item4 != "")
	{
		cout << "4: " << item4 << endl;
	}
	if(item5 != "")
	{
		cout << "5: " << item5 << endl;
	}
	cout << endl << endl;
}
