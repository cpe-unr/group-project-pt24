//Authors: Jamie Lee, Nikhil Sharma
//Group Project
//4/28/2021

#include "ModifyMD.h"

using namespace std;

void ModifyMD::writeNewMetadata(string filename, char* newTitle, char* newArtist, char* newComments){
	/*ofstream outFile(filename, ios::out | ios::binary);
	outFile.seekp(wav.getBufferSize() + 44, ios::beg);
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
	/*stream.write(subChunk, sizeof(subChunk));
	stream.write((char*)sizeof(data), sizeof(int));
	stream.write(data, sizeof(data));
	*/
}
