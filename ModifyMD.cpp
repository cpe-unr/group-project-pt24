//Authors: Jamie Lee, Nikhil Sharma
//Group Project
//4/28/2021

#include "ModifyMD.h"

using namespace std;

void ModifyMD::writeNewMetadata(string filename, char* newTitle, char* newArtist, char* newComments){
	/*ofstream outFile(filename, ios::out | ios::binary);
	wav_header waveHeader;
	outFile.write((char*)&waveHeader,sizeof(wav_header));
	//buffer?
	
	metadata_header Metadata;
	outFile.write((char*)&Metadata,sizeof(metadata_header)); 
	
	INAM_data Title;
	outFile.write((char*)&Title,sizeof(INAM_data));
	outFile.write((char*)newTitle, sizeof(newTitle));
	
	IART_data Artist;	
	outFile.write((char*)&Artist,sizeof(IART_data));
	outFile.write((char*)newArtist, sizeof(newArtist));
	
	ICMT_data Comments;
	outFile.write((char*)&Comments,sizeof(ICMT_data));
	outFile.write((char*)newComments, sizeof(newComments));
	
	outFile.close();*/
}
