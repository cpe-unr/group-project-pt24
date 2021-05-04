//Authors: Jamie Lee, Nikhil Sharma
//Group Project
//4/27/2021

#ifndef WAV_H
#define WAV_H

#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
#include "WaveHeader.h"

/** 
* This is the Wav class that will access and create data for wave files
*/
class Wav{
	unsigned char* buffer = NULL;
	unsigned short* bufferShort = NULL;
	
	char *title, *artist, *comments;
	metadata_header Metadata;
	INAM_data Title;
	IART_data Artist;
	ICMT_data Comments;

	short bitType;
public:
	wav_header waveHeader;

	/** 
	* Reads Wave file and its techinical information/data/metadata
	* @param filename - name of wave file to read
	*/
	void readFile(const std::string &fileName);

	/** 
	* Writes new Wave file with new data
	* @param outFilename - name of wave file to write
	*/
	void writeFile(const std::string &outFileName);

	/** 
	* Get buffer for 8-bit files
	*/
	unsigned char *getBuffer();

	/** 
	* Get buffer for 16-bit files
	*/
	unsigned short *getBufferShort();

	/** 
	* Get buffer size of wave file
	*/
	int getBufferSize() const;

	/** 
	* Get number of channels of wave file
	*/
	short getNumChannels();
	
	/** 
	* Get title of wave file
	*/
	char *getTitle();
	/** 
	* Set title of wave file
	*@param newTitle - new title
	*/
	void setTitle(char* newTitle);

	/** 
	* Get artist of wave file
	*/
	char *getArtist();
	/** 
	* Set artist of wave file
	*@param newArtist - new artist
	*/
	void setArtist(char* newArtist);

	/** 
	* Get comments of wave file
	*/
	char *getComments();
	/** 
	* Set comments of wave file
	*@param newComments - new comments
	*/
	void setComments(char* newComments);

	/** 
	* Get bit type of wave file
	*/
	short getBitType();

	/** 
	* Set bit type of wave file
	*@param newBitType - new bit type
	*/
	void setBitType(short newBitType);

	/** 
	* Destructor to delete dynamically allocted memory
	*/
	virtual ~Wav();	
};

#endif //WAV_H
