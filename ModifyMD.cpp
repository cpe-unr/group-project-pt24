//Authors: Jamie Lee, Nikhil Sharma
//Group Project
//4/28/2021

#include "ModifyMD.h"

using namespace std;

void ModifyMD::writeNewMetadata(string filename, char* newTitle, char* newArtist, char* newComments){
	fstream updateFile(filename, ios::in | ios::binary | ios::out | ios::ate);
	if(updateFile.is_open()){
		wav.readFile(filename);
		
		
		
		
		/*char *titleToModify = wav.getTitle();
		INAM_data Title;
		updateFile.read((char*)&Title, sizeof(INAM_data));
		updateFile.seekg(-(sizeof(Title)), ios::cur);
		strncpy(titleToModify, newTitle, sizeof(newTitle));
		updateFile.write((char*)&Title, sizeof(INAM_data));
		wav.setTitle(titleToModify);
		
 
		//wav.setTitle(newTitle);
 		//strncpy(titleToModify, newTitle.c_str(), newTitle.size()); 
 		
 			
 		//cout << wav.getTitle() << endl;
 			
 		/*updateFile.read((char*)&Artist, sizeof(IART_data));	
		char *artistToModify = wav.getArtist();
 		strncpy(artistToModify, newArtist.c_str(), sizeof(newArtist)); 
 		updateFile.write((char*)&artistToModify, sizeof(newArtist));
 			
 		updateFile.read((char*)&Comments, sizeof(ICMT_data));
 		char *commentsToModify = wav.getComments();
 		strncpy(commentsToModify, newComments.c_str(), sizeof(newComments));	
		updateFile.write((char*)&commentsToModify, sizeof(newComments));
		//} */
			
		updateFile.close();
	}
}
