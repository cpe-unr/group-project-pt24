//Authors: Samuel DeLange, Jamie Lee, Nikhil Sharma
//Group Project
//4/30/2021

#ifndef WAVDATA_H
#define WAVDATA_H

#include <string>

class WavData{
	int fileSize, sampleRate, dataBytes;
	short audioFormat, numChannels, bitsPerSample;
	std::string title, artist, comments;
public:
	WavData();
	WavData(int newFileSize, int newSampleRate, int newDataBytes, short newAudioFormat, short newNumChannels, short newBitsPerSample, std::string newTitle, std::string newArtist, std::string newComments){
		setFileSize(newFileSize);
		setSampleRate(newSampleRate);
		setDataBytes(newDataBytes);
		setAudioFormat(newAudioFormat);
		setNumChannels(newNumChannels);
		setBitsPerSample(newBitsPerSample);
		setTitle(newTitle);
		setArtist(newArtist);
		setComments(newComments);
	}
	
	int getFileSize();
	void setFileSize(int);
	
	int getSampleRate();
	void setSampleRate(int);
	
	int getDataBytes();
	void setDataBytes(int);
	
	short getAudioFormat();
	void setAudioFormat(short);
	
	short getNumChannels();
	void setNumChannels(short);
	
	short getBitsPerSample();
	void setBitsPerSample(short);
	
	std::string getTitle();
	void setTitle(std::string);
	
	std::string getArtist();
	void setArtist(std::string);
	
	std::string getComments();
	void setComments(std::string);
};

#endif
