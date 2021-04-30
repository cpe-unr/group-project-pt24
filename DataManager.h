//Authors: Samuel DeLange, Jamie Lee, Nikhil Sharma
//Group Project
//4/30/2021

#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "WaveHeader.h"
#include "WavData.h"

class DataManager{
	wav_header waveHeader;
	std::vector<WavData> dataList;
public:
	DataManager();
	DataManager(std::string);

	void loadWavData(std::string);
	void printMetadata(std::string);
	void editMetaData(std::string);
};

#endif
