//Authors: Samuel DeLange, Jamie Lee, Nikhil Sharma
//Group Project
//4/30/2021

#ifndef WAVDATA_H
#define WAVDATA_H

#include <string>
#include "MetadataPrinter.h"

using namespace std;

class WavData{
	int fileSize, sampleRate, dataBytes;
	short int audioFormat, numChannels, bitsPerSample;
	std::string title, artist, comments;
public:
	WavData(int newFileSize, int newSampleRate, int newDataBytes, short int newAudioFormat, short int newNumChannels, short int newBitsPerSample, std::string newTitle, std::string newArtist, std::string newComments){
		fileSize = newFileSize;
		sampleRate = newSampleRate;
		dataBytes = newDataBytes;
		audioFormat = newAudioFormat;
		numChannels = newNumChannels;
		bitsPerSample = newBitsPerSample;
		title = newTitle;
		artist = newArtist;
		comments = newComments;
	}
	
	int getFileSize();
	void setFileSize(int);
	
	int getSampleRate();
	void setSampleRate(int);
	
	int getDataBytes();
	void setDataBytes(int);
	
	short int getAudioFormat();
	void setAudioFormat(short);
	
	short int getNumChannels();
	void setNumChannels(short);
	
	short int getBitsPerSample();
	void setBitsPerSample(short);
	
	std::string getTitle();
	void setTitle(std::string);
	
	std::string getArtist();
	void setArtist(std::string);
	
	std::string getComments();
	void setComments(std::string);
	
	MetadataPrinter metaprinter;
	void printMD();
};

#endif
