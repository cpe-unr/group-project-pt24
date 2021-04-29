//Authors: Samuel DeLange, Jamie Lee, Nikhil Sharma
//Group Project
//4/28/2021

#include "ModifyMD.h"

using namespace std;

ModifyMD::ModifyMD(){
	title = waveHeader.INAM_data; //having trouble with getting data for these strings...might need help
	artist = waveHeader.IART_data;
	comments = waveHeader.ICMT_data;
}

string ModifyMD::getTitle(){
	return title;
}
	
void ModifyMD::setTitle(string newTitle){
	title = newTitle;
}
	
string ModifyMD::getArtist(){
	return artist;
}
	
void ModifyMD::setArtist(string newArtist){
	artist = newArtist;
}
	
string ModifyMD::getComments(){
	return comments;
}
	
void ModifyMD::setComments(string newComments){
	comments = newComments;
}
