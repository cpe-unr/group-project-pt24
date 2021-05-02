//Authors: Samuel DeLange, Jamie Lee, Nikhil Sharma
//Group Project
//4/30/2021

#include "DataManager.h"

using namespace std;

DataManager::DataManager(string filename){
	loadWavData(filename);
}

DataManager::loadWavData(string filename){
	ifstream file(fileName, ios::binary | ios::in);
	if(file.is_open()){
		file.read((char*)&waveHeader, sizeof(wav_header));
		
		WavData wavData;
		wavData.setFileSize(waveHeader.wav_size);
		wavData.setSampleRate(waveHeader.sample_rate);
		wavData.setDataBytes(waveHeader.data_bytes);
		wavData.setAudioFormat(waveHeader.audio_format);
		wavData.setNumChannels(waveHeader.num_channels);
		wavData.setBitsPerSample(waveHeader.bit_depth);
		wavData.setTitle(waveHeader.INAM_data); //...
		wavData.setArtist(waveHeader.IART_data);
		wavData.setComments(waveHeader.ICMT_data);
		dataList.push_back(wavData);
	
		file.close();
	}
}

DataManager::viewMetadata(){
	MetadataPrinter metadataPrinter;
	metadataPrinter.printMetaData(dataList);
}

DataManager::editMetadata(string filename, string title, string artist, string comments){
	ModifyMD modifyMD;
	modifyMD.writeNewMetadata(filename, title, artist, comments);
}
