/** @file MetadataPrinter.h
* @brief MetadataPrinter class
*
* This class contains a function used to print metadata of wave files
*
* @author Jamie Lee
* @author Nikhil Sharma
*/

//Authors: Samuel DeLange, Jamie Lee, Nikhil Sharma
//Group Project
//5/01/2021

#ifndef METADATAPRINTER_H
#define METADATAPRINTER_H

#include <iostream>
#include <vector>
#include "WavData.h"

class MetadataPrinter{
public:
	/**
	* Prints metadata of a wave file using a vector containing WavData objects
	* @param vector<WavData> data - vector containing WavData objects storing info from wave files
	*/
	void printMetadata(std::vector<WavData> data);
};

#endif
