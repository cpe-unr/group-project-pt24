//Authors: Samuel DeLange, Jamie Lee, Nikhil Sharma
//Group Project
//4/28/2021

#include "ModifyMD.h"

using namespace std;

void ModifyMD::writeNewMetadata(string filename, string newTitle, string newArtist, string newComments){
	const int MAX_LENGTH = 50;
	
	fstream updateFile(fileName, ios::in | ios::ate | ios::binary);
	
	if(updateFile.is_open()){
 		updateFile.read((char*)&waveHeader, sizeof(wav_header));
 			
 		//if(waveHeader.info_header.find("INFO") != string::npos){
 			char *titleToModify = waveHeader.INAM_data;
 			strncpy(titleToModify, newTitle.c_str(), MAX_LENGTH); 
 				
			char *artistToModify = waveHeader.IART_data;
 			strncpy(artistToModify, newArtist.c_str(), MAX_LENGTH); 
 			
 			char *commentsToModify = waveHeader.ICMT_data;
 			strncpy(commentsToModify, newComments.c_str(), MAX_LENGTH);	
			
			updateFile.write((char*)&waveHeader, sizeof(wav_header));
		//}
		//else{
		
		//}
			
		updateFile.close();
	}
}
