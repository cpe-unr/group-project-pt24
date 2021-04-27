//Authors: Samuel DeLange, Jamie Lee, Nikhil Sharma
//Group Project
//4/27/2021

//only for 8bit mono so far...

#include <string>
#include <fstream>
#include <iostream>
#include "Wav.h"

using namespace std;

void Wav::readFile(const std::string &fileName) {
	ifstream file(fileName, ios::binary | ios::in);
	if(file.is_open()){
		file.read((char*)&waveHeader, sizeof(wav_header));
		buffer = new unsigned char[waveHeader.data_bytes];
		file.read((char*)buffer, waveHeader.data_bytes);
	
		//testing values
		cout << waveHeader.num_channels << endl;
		
		file.close();
	}
	

	//what lancaster showed on video for handling 16 bit buffers
	//short* shortBuffer = reinterpret_Cast<short*>(buffer);
	//short firstValue = shortBuffer[0];
}


unsigned char *Wav::getBuffer(){
	return buffer;
}

void Wav::writeFile(const std::string &outFileName) {
	ofstream outFile(outFileName, ios::out | ios::binary);
	outFile.write((char*)&waveHeader,sizeof(wav_header));
	outFile.write((char*)buffer, waveHeader.data_bytes);
	outFile.close();
}

Wav::~Wav() {
	if(buffer != NULL){
		delete[] buffer;
	}
}

int Wav::getBufferSize() const {
	return waveHeader.data_bytes;
}
