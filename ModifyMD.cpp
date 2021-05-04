//Authors: Jamie Lee, Nikhil Sharma
//Group Project
//4/28/2021

#include "ModifyMD.h"

using namespace std;

void ModifyMD::writeNewMetadata(string filename, char* newTitle, char* newArtist, char* newComments){
	/*ofstream outFile(filename, ios::out | ios::binary);
	outFile.seekp(wav.getBufferSize + 44, ios::beg);
	metadata_header Metadata;
	outFile.write((char*)&Metadata, sizeof(metadata_header)); 
	
	INAM_data Title;
	IART_data Artist;
	ICMT_data Comments;
	writeChunk(outFile, Title.INAM_header, newTitle);
	writeChunk(outFile, Artist.IART_header, newArtist);
	writeChunk(outFile, Comments.ICMT_header, newComments);
	
	outFile.close();*/
}

void ModifyMD::writeChunk(ofstream &stream, char* subChunk, char* data){
	/*for(string &x : subChunk){
		int index = 0;
		stream.write(&subChunk[index], sizeof(subChunk[index]));
		stream.write((char*)data[index].size(), sizeof(int));
		stream.write(&data[index], data[index].size());
	}*/
}
