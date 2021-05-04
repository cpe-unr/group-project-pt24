//Authors: Samuel DeLange, Jamie Lee, Nikhil Sharma
//Group Project
//4/28/2021

#ifndef MODIFYMD_H
#define MODIFYMD_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "WaveHeader.h"
#include "WavData.h"
#include "Wav.h"

class ModifyMD{
	Wav wav;
public:
	void writeNewMetadata(std::string, char*, char*, char*);
	
};

#endif
