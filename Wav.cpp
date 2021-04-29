//Authors: Samuel DeLange, Jamie Lee, Nikhil Sharma
//Group Project
//4/27/2021

//don't know if we need to accomodate for mono or stereo here
//if so, idk how

#include <string>
#include <fstream>
#include <iostream>
#include "Wav.h"

using namespace std;

void Wav::readFile(const std::string &fileName) {
	ifstream file(fileName, ios::binary | ios::in);
	if(file.is_open()){
		file.read((char*)&waveHeader, sizeof(wav_header));
		setBitType(waveHeader.bit_depth);
		
		if(bitType == 8){
			buffer = new unsigned char[waveHeader.data_bytes]; //8 bit buffer
			file.read((char*)buffer, waveHeader.data_bytes);
		}
		
		if(bitType == 16){
			shortBuffer = new short[waveHeader.data_bytes]; //16 bit buffer
			file.read(reinterpret_cast<char*>(shortBuffer), waveHeader.data_bytes);
		}
		
		//testing values
		//cout << waveHeader.bit_depth << endl;
		
		file.close();
	}

	//16 bit buffer lancaster talked about
	//short* shortBuffer = reinterpret_Cast<short*>(buffer);
	//short firstValue = shortBuffer[0];
}


unsigned char *Wav::getBuffer(){
	return buffer;
}

short *Wav::getShortBuffer(){
	return shortBuffer;
}

void Wav::writeFile(const std::string &outFileName) {
	ofstream outFile(outFileName, ios::out | ios::binary);
	outFile.write((char*)&waveHeader,sizeof(wav_header));
	
	if(bitType == 8){
		outFile.write((char*)buffer, waveHeader.data_bytes);
	}
	
	if(bitType == 16){
		outFile.write(reinterpret_cast<char*>(shortBuffer), waveHeader.data_bytes);
	}
	
	outFile.close();
}

Wav::~Wav() {
	if(buffer != NULL){
		delete[] buffer;
	}
	
	if(shortBuffer != NULL){
		delete[] buffer;
	}
}

int Wav::getBufferSize() const {
	return waveHeader.data_bytes;
}

short Wav::getBitType(){
	return bitType;
}

void Wav::setBitType(short newBitType){
	bitType = newBitType;
}
