//Authors: Jamie Lee, Nikhil Sharma
//Group Project
//5/01/2021

#include "MetadataPrinter.h"

using namespace std;

void MetadataPrinter::printMetadata(vector<WavData> data){
	//cout << "abcd" << endl;
	cout 	<< "Title: " << data.back().getTitle() << endl
		<< "Artist: " << data.back().getArtist() << endl
		<< "Comments: " << data.back().getComments() << endl;
}


