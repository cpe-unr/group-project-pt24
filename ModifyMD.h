//Authors: Jamie Lee, Nikhil Sharma
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

/**
* This is the ModifyMD class that will modify existing metadata of a wave file or create new metadata if wave file doesn't contain metadata
*/
class ModifyMD{
	Wav wav;
public:
	/**
	* Writes to specified wav file overwriting current metadata/creating new metadata using user inputted metadata
	* @param filename - name of wave file
	* @param userTitle - new title inputted by user
	* @param userArtist - new artist inputted by user
	* @param userComments - new comments inputted by user
	*/
	void writeNewMetadata(std::string filename, char* userTitle, char* userArtist, char* userComments);
	
};

#endif //MODIFYMD_H
