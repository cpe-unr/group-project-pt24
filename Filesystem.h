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

class Filesystem{
public:
	bool noneOfTheCurrentFiles(string newFile);
	string chosenFile();
};


#endif
