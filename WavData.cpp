//Authors: Jamie Lee, Nikhil Sharma
//Group Project
//4/30/2021

#include "WavData.h"

WavData::WavData(){}

int WavData::getFileSize(){
	return fileSize;
}

void WavData::setFileSize(int newFileSize){
	fileSize = newFileSize;
}

int WavData::getSampleRate(){
	return sampleRate;
}

void WavData::setSampleRate(int newSampleRate){
	sampleRate = newSampleRate;
}

int WavData::getDataBytes(){
	return dataBytes;
}

void WavData::setDataBytes(int newDataBytes){
	dataBytes = newDataBytes;
}

short int WavData::getAudioFormat(){
	return audioFormat;
}

void WavData::setAudioFormat(short newAudioFormat){
	audioFormat = newAudioFormat;
}

short int WavData::getNumChannels(){
	return numChannels;
}

void WavData::setNumChannels(short newNumChannels){
	numChannels = newNumChannels;
}

short int WavData::getBitsPerSample(){
	return bitsPerSample;
}

void WavData::setBitsPerSample(short newBitsPerSample){
	bitsPerSample = newBitsPerSample;
}

char *WavData::getTitle(){
	return title;
}
	
void WavData::setTitle(char *newTitle){
	title = newTitle;
}
	
char *WavData::getArtist(){
	return artist;
}
	
void WavData::setArtist(char *newArtist){
	artist = newArtist;
}
	
char *WavData::getComments(){
	return comments;
}
	
void WavData::setComments(char *newComments){
	comments = newComments;
}
