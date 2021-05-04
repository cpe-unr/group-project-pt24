//Authors: Jamie Lee, Nikhil Sharma
//Group Project
//4/30/2021

#include "DataManager.h"

using namespace std;

DataManager::DataManager(){}

DataManager::DataManager(string filename){
	loadWavData(filename);
}

void DataManager::loadWavData(string filename){
	ifstream file(filename, ios::binary | ios::in);
	if(file.is_open()){
		file.read((char*)&waveHeader, sizeof(wav_header));
		
		WavData wavData;
		
		//technical info
		wavData.setFileSize(waveHeader.wav_size);
		wavData.setSampleRate(waveHeader.sample_rate);
		wavData.setDataBytes(waveHeader.data_bytes);
		wavData.setAudioFormat(waveHeader.audio_format);
		wavData.setNumChannels(waveHeader.num_channels);
		wavData.setBitsPerSample(waveHeader.bit_depth);
		
		//metadata
		wav.readFile(filename);
		
		wavData.setTitle(wav.getTitle());
		wavData.setArtist(wav.getArtist());
		wavData.setComments(wav.getComments());
		
		dataList.push_back(wavData);

		file.close();
	}
}

void DataManager::viewMetadata(){
	MetadataPrinter metadataPrinter;
	metadataPrinter.printMetadata(dataList);
}

void DataManager::editMetadata(string filename, char* title, char* artist, char* comments){	
	loadWavData(filename);	
	ModifyMD modifyMD;
	modifyMD.writeNewMetadata(filename, title, artist, comments);
	loadWavData(filename);
}
