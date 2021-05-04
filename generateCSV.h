#ifndef CSV_H
#define CSV_H

#include <iostream>
#include <fstream>
#include <experimental/filesystem>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <vector>

#include "Wav.h"
#include "WaveHeader.h"
/**
 * This is the generate csv class. 
*/
class GenerateCSV{
public:

/**
 * Generates csv file by reading in all the files in the directory, 
 * and then printing it to a csv file.
*/
	void generate();
};


#endif
