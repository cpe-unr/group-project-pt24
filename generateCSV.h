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

class GenerateCSV{
public:
	void generate();
};


#endif
