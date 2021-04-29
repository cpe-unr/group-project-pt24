//Authors: Samuel DeLange, Jamie Lee, Nikhil Sharma
//Group Project
//4/28/2021

#ifndef MODIFYMD_H
#define MODIFYMD_H

#include <iostream>
#include <string>
#include "Wav.h"

class ModifyMD{
	Wav wav;
	wav_header waveHeader;
	std::string title;
	std::string artist;
	std::string comments;
public:
	ModifyMD();
	ModifyMD(std::filename, std::string newTitle, std::string newArtist, std::string newComments){
		wav.readFile(filename);	
		setTitle(newTitle);
		setArtist(newArtist);
		setComments(newComments);
	}
	
	std::string getTitle();
	void setTitle(std::string);
	
	std::string getArtist();
	void setArtist(std::string);
	
	std::string getComments();
	void setComments(std::string);
};

#endif
