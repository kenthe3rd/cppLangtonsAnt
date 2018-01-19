/* ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** **
 *Ken Hall	1/21/2017
 *
 *CS 162 400	Project 1
 *:::MENU HEADER FILE:::
 ** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** * */

#ifndef MENU_HPP
#define MENU_HPP

#include <string>
using std::string;

class Menu
{
	private:
		string item1 = "";	//
		string item2 = "";	////
		string item3 = "";	////menu items//
		string item4 = "";	////
		string item5 = "";	//

		int validInputs = 0;	//used in input 
		int userSelection = 0;	//validation
	public:
		Menu(string, string);
		Menu(string, string, string);
		Menu(string, string, string, string);
		Menu(string, string, string, string, string);
		int enforceValidInput();
		void displayMenu();
};
#endif
