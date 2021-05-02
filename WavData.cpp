//Authors: Samuel DeLange, Jamie Lee, Nikhil Sharma
//Group Project
//4/30/2021

#include "WavData.h"

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

string WavData::getTitle(){
	return title;
}
	
void WavData::setTitle(string newTitle){
	title = newTitle;
}
	
string WavData::getArtist(){
	return artist;
}
	
void WavData::setArtist(string newArtist){
	artist = newArtist;
}
	
string WavData::getComments(){
	return comments;
}
	
void WavData::setComments(string newComments){
	comments = newComments;
}
MetadataPrinter metaprinter;
void WavData::printMD() {
	metaprinter.printMetadata();
}
