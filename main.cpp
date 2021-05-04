/** @file */

//Authors: Samuel DeLange, Jamie Lee, Nikhil Sharma
//Group Project
//4/22/2021

#include <iostream>
#include <fstream>
#include <experimental/filesystem>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <vector>

#include "Menu.h"
//#include "Wav.h"
//#include "Processor.h"
//#include "Limiter.h"
//#include "Echo.h"
//#include "NoiseGate.h"
//#include "Normalize.h"
//#include "WaveHeader.h"
//#include "WavData.h"
//#include "DataManager.h"

using namespace std;


/**
 * \brief   The function bar.
 *
 * \details This function does something which is doing nothing. So this text
 *          is totally senseless and you really do not need to read this,
 *          because this text is basically saying nothing.
 *
 * \note    This text shall only show you, how such a \"note\" section
 *          is looking. There is nothing which really needs your notice,
 *          so you do not really need to read this section.
 *
 * \param[in]     a    Description of parameter a.
 * \param[out]    b    Description of the parameter b.
 * \param[in,out] c    Description of the parameter c.
 *
 * \return        The error return code of the function.
 *
 * \retval        ERR_SUCCESS    The function is successfully executed
 * \retval        ERR_FAILURE    An error occurred
 */
void fn(){

}

int main() {
    // Uncomment these lines when ready.
	int userChoice;
	cout << "Please choose from one of the options below" << endl;
	cout << "1. Metadata" << endl;
	cout << "2. Audio Processors" << endl;
	cout << "3. Generate CSV " << endl;
	cin >> userChoice;
	
	switch(userChoice){
		case 1: {
			Menu menu;
			menu.subMenuMD();
			}
			break;
		case 2:	{
			Menu menu;
			menu.subMenuAP();	
			}
			break;
		case 3:
			Menu menu;
			menu.createCSV();
			break;
		default:
			cout << "Please enter a valid option!" << endl;
	}
	return 0;
}
bool noneOfTheCurrentFiles(string newFile) {
	vector<string> filenames;
        for(auto& p: fs::directory_iterator("test")) {
	filenames.emplace_back(p.path().filename());
	}
	for(auto item: filenames) {
	if(newFile == item) {
		return false;
	}
	}
	return true;
}
string chosenFile() {
	int fileIndex;
	vector<string> filenames;
	string chosenFile = " ";
	do {
	int counter = 1;
	cout << "Please choose from the files below." << endl;
        for(auto& p: fs::directory_iterator("test")) {
        std::cout << counter << ". " << p.path().filename() << '\n';
	filenames.emplace_back(p.path().filename());
	counter++;
	}
	cin >> fileIndex;
	}
	while (fileIndex > 4 || fileIndex < 1); //Trying to adhere this to SOLID principles. Tho, vector.size doesn't work properly.
	chosenFile = filenames[fileIndex - 1];
	return chosenFile;
}
