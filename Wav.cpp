//Authors: Jamie Lee, Nikhil Sharma
//Group Project
//4/27/2021

#include "Wav.h"

using namespace std;

void Wav::readFile(const string &fileName) {
	ifstream file(fileName, ios::binary | ios::in);
	if(file.is_open()){
		file.read((char*)&waveHeader, sizeof(wav_header));
		setBitType(waveHeader.bit_depth);
		
		if(bitType == 8){
			buffer = new unsigned char[waveHeader.data_bytes]; //8 bit buffer
			file.read((char*)buffer, waveHeader.data_bytes);
		}
		
		if(bitType == 16){
			bufferShort = new unsigned short[waveHeader.data_bytes]; //16 bit buffer
			file.read(reinterpret_cast<char*>(bufferShort), waveHeader.data_bytes);
		}
		
		file.read((char*)&Metadata, sizeof(metadata_header));
		
		file.read((char*)&Title, sizeof(INAM_data));
		title = new char[Title.INAM_size];
		file.read((char*)title, Title.INAM_size);
		
		file.read((char*)&Artist, sizeof(IART_data));
		artist = new char[Artist.IART_size];
		file.read((char*)artist, Artist.IART_size);
		
		file.read((char*)&Comments, sizeof(ICMT_data));
		comments = new char[Comments.ICMT_size];
		file.read((char*)comments, Comments.ICMT_size);
	
		file.close();
	}
}


unsigned char *Wav::getBuffer(){
	return buffer;
}

unsigned short *Wav::getBufferShort() {
	return bufferShort;
}

void Wav::writeFile(const string &outFileName) {
	ofstream outFile(outFileName, ios::out | ios::binary);
	outFile.write((char*)&waveHeader,sizeof(wav_header));
	setBitType(waveHeader.bit_depth);
	
	if(bitType == 8){
		outFile.write((char*)buffer, waveHeader.data_bytes);
	}
	
	if(bitType == 16){
		outFile.write(reinterpret_cast<char*>(bufferShort), waveHeader.data_bytes);
	}
	
	outFile.close();
}

Wav::~Wav() {
	if(buffer != NULL){
		delete[] buffer;
	}
	if(bufferShort != NULL) {
		delete[] bufferShort;
	}
	
	delete[] title;
	delete[] artist;
	delete[] comments;
}

int Wav::getBufferSize() const {
	return waveHeader.data_bytes;
}

short Wav::getNumChannels() {
	return waveHeader.num_channels;
}

char *Wav::getTitle(){
	return title;
}

void Wav::setTitle(char *newTitle){
	strcpy(title, newTitle);
}

char *Wav::getArtist(){
	return artist;
}

void Wav::setArtist(char *newArtist){
	strcpy(artist, newArtist);
}

char *Wav::getComments(){
	return comments;
}

void Wav::setComments(char *newComments){
	strcpy(comments, newComments);
}
 
short Wav::getBitType(){
	return bitType;
}

void Wav::setBitType(short newBitType){
	bitType = newBitType;
}
