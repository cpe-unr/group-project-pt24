/** @file */

//Authors: Samuel DeLange, Jamie Lee, Nikhil Sharma
//Group Project
//4/22/2021

#include <iostream>
#include <fstream>
#include <experimental/filesystem>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <vector>

#include "Menu.h"

using namespace std;

/**
 * Main application entry point
 * 
 * Prints a basic menu, uses switch statement to get input from user,
 * creates a menu, and then calls methods to sub menus.
 *
 *\return	The success of the the program
 */
int main() {
	int userChoice;
	cout << "Please choose from one of the options below" << endl;
	cout << "1. Metadata" << endl;
	cout << "2. Audio Processors" << endl;
	cout << "3. Generate CSV " << endl;
	cin >> userChoice;
	
	switch(userChoice){
		case 1: {
			Menu menu;
			menu.subMenuMD();
			}
			break;
		case 2:	{
			Menu menu;
			menu.subMenuAP();	
			}
			break;
		case 3: {
			Menu menu;
			menu.createCSV();
			}
			break;
		default:
			cout << "Please enter a valid option!" << endl;
	}
	return 0;
}
