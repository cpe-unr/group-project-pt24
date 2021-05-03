//Authors: Samuel DeLange, Jamie Lee, Nikhil Sharma
//Group Project
//4/30/2021

#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Wav.h"
#include "WavData.h"
#include "WaveHeader.h"
#include "MetadataPrinter.h"

class DataManager{
	Wav wav;
	wav_header waveHeader;
	std::vector<WavData> dataList;
public:
	DataManager();
	DataManager(std::string);

	void loadWavData(std::string);
	void viewMetadata();
	void editMetaData(std::string);
};

#endif
