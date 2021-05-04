/** @file WavData.h
* @brief DataManager class
*
* This class contains prototypes and variables used manage data of wave files
*
* @author Jamie Lee
* @author Nikhil Sharma
*/

//Authors: Samuel DeLange, Jamie Lee, Nikhil Sharma
//Group Project
//4/30/2021

#ifndef DOXYGEN_DATAMANAGER_H
#define DOXYGEN_DATAMANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Wav.h"
#include "WavData.h"
#include "WaveHeader.h"
#include "MetadataPrinter.h"
#include "ModifyMD.h"

class DataManager{
	Wav wav;
	wav_header waveHeader;
	std::vector<WavData> dataList;
public:
	/**
	* Default constructor
	*/
	DataManager();
	/**
	* Parameterized constructor to take in filename of wave file
	* it will load in the data from the specified wave file
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

#endif //DOXYGEN_DATAMANAGER_H
