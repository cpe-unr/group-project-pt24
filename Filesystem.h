#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <iostream>
#include <fstream>
#include <experimental/filesystem>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <vector>

using namespace std;
/**
 * This is the file system class. 
*/
class Filesystem{
public:

/**
 *
 * Checks to see that input filename does not match any files that exist already, 
 * if it does it returns false, if it does not, it returns true.
 * \return 	Boolean condition.
*/
	bool noneOfTheCurrentFiles(string newFile);

/**
 *
 * Prints all the files in the external directory, 
 * lets user choose the file which they would like to process.
 * \return 	Returns the name of file user wants to use.
*/
	string chosenFile();
};


#endif
