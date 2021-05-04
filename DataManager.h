//Authors: Jamie Lee, Nikhil Sharma
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
#include "ModifyMD.h"

/**
* This is the DataManager class that will manage data of wave files.
* Managing includes loading in wave file info, printing metadata, and editing metadata
*/
class DataManager{
	Wav wav;
	wav_header waveHeader;
	std::vector<WavData> dataList;
public:
	/**
	* Default constructor of DataManager
	*/
	DataManager();
	/**
	* Parameterized constructor to take in filename of wave file.
	* It will load in the data/info from the specified wave file
	* @param filename - name of wave file
	*/
	DataManager(std::string filename);
	
	/**
	* Loads in data from wave file and stores info into WavData object
	* @param filename - name of wave file
	*/
	void loadWavData(std::string filename);

	/**
	* Prints metadata of file using a vector with elements of type WavData
	*/
	void viewMetadata();

	/**
	* Edits existing metadata or creates new metadata if no current metadata exist
	* @param filename - name of wave file
	* @param title - user inputted title
	* @param artist - user inputted artist
	* @param comments - user inputted comments
	*/
	void editMetadata(std::string filename, char* title, char* artist, char* comments);
};

#endif //DATAMANAGER_H
