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

#include "Wav.h"
#include "Processor.h"
#include "Limiter.h"
#include "Echo.h"
#include "NoiseGate.h"
#include "Normalize.h"

using namespace std;
namespace fs = experimental::filesystem;

void subMenuMD();
void subMenuAP();
bool noneOfTheCurrentFiles(string newFile);
string chosenFile();
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
		case 1:
			subMenuMD();
			break;
		case 2:	
			subMenuAP();	
			break;
		case 3:
			break;
		default:
			cout << "Please enter a valid option!" << endl;
	}
	//cout << "Hello, World!" << endl;
	
	return 0;
}
void subMenuMD() {
	int userChoiceMD;
	cout << "Please choose from one of the options below" << endl;
	cout << "1. View metaData" << endl;
	cout << "2. Modify metadata" << endl;
	cout << "3. Exit" << endl;
	cin >> userChoiceMD;
	switch(userChoiceMD){
		case 1:
			//viewMetadata(chosenFile());
			break;
		case 2:	
			//editMetaData(chosenFile());	
			break;
		case 3:		
			break;
		default:
			cout << "Please enter a valid option!" << endl;
	}
}
void subMenuAP() {
	char cwd[PATH_MAX];
	getcwd(cwd, sizeof(cwd));
	std::string sfile = "/test/";
        std::string fileDir = cwd+sfile;
	int userChoiceAP;
	string newFile = " ";
	cout << "Please choose from one of the options below" << endl;
	cout << "1. Normalize" << endl;
	cout << "2. Noise Gate" << endl;
	cout << "3. Echo" << endl;
	cout << "4. Limit" << endl;
	cout << "5. Exit" << endl;
	cin >> userChoiceAP;
	switch(userChoiceAP){
		case 1: {
			Wav wav;
			wav.readFile(fileDir + chosenFile());
			if(wav.getBitType() == 16) {
				short int vIn = wav.getBitType();
				int vOut = int(vIn);
				Processor<unsigned short> *normalize = new Normalize<unsigned short>();
				normalize->processBuffer(wav.getBufferShort(), wav.getBufferSize(), vOut);
				do {
				cout << "Please enter new file name with a .wav extension at the end" << endl;
				cin >> newFile;
				}
				while(noneOfTheCurrentFiles(newFile) == false);
				wav.writeFile(newFile);
				delete normalize;
			}
			else {
				Processor<unsigned char> *normalize = new Normalize<unsigned char>();
				normalize->processBuffer(wav.getBuffer(), wav.getBufferSize(), wav.getBitType());
				do {
					cout << "Please enter new file name with a .wav extension at the end" << endl;
					cin >> newFile;
				}
				while(noneOfTheCurrentFiles(newFile) == false);
				wav.writeFile(newFile);
				delete normalize;
			}
			}
			break;
		case 2:	{
			Wav wav;
			wav.readFile(fileDir + chosenFile());
			if(wav.getBitType() == 16) {
				short int vIn = wav.getBitType();
				int vOut = int(vIn);
				Processor<unsigned short> *noise = new NoiseGate<unsigned short>(6400);
				noise->processBuffer(wav.getBufferShort(), wav.getBufferSize(), vOut);
				do {
				cout << "Please enter new file name with a .wav extension at the end" << endl;
				cin >> newFile;
				}
				while(noneOfTheCurrentFiles(newFile) == false);
				wav.writeFile(newFile);
				delete noise;
			}
			else {
				Processor<unsigned char> *noise = new NoiseGate<unsigned char>(25);
				noise->processBuffer(wav.getBuffer(), wav.getBufferSize(), wav.getBitType());
				do {
					cout << "Please enter new file name with a .wav extension at the end" << endl;
					cin >> newFile;
				}
				while(noneOfTheCurrentFiles(newFile) == false);
				wav.writeFile(newFile);
				delete noise;
			}
			}
			break;
		case 3: {
			Wav wav;
			wav.readFile(fileDir + chosenFile());
			if(wav.getBitType() == 16) {
				short int vIn = wav.getBitType();
				int vOut = int(vIn);
				Processor<unsigned short> *processor = new Echo<unsigned short>(256000);
				processor->processBuffer(wav.getBufferShort(), wav.getBufferSize(), vOut);
				do {
				cout << "Please enter new file name with a .wav extension at the end" << endl;
				cin >> newFile;
				}
				while(noneOfTheCurrentFiles(newFile) == false);
				wav.writeFile(newFile);
				delete processor;
			}
			else {
				Processor<unsigned char> *processor = new Echo<unsigned char>(32000);
				processor->processBuffer(wav.getBuffer(), wav.getBufferSize(), wav.getBitType());
				do {
					cout << "Please enter new file name with a .wav extension at the end" << endl;
					cin >> newFile;
				}
				while(noneOfTheCurrentFiles(newFile) == false);
				wav.writeFile(newFile);
				delete processor;
			}
			}
			break;
		case 4: {
			Wav wav;
			wav.readFile(fileDir + chosenFile());
			if(wav.getBitType() == 16) {
				short int vIn = wav.getBitType();
				int vOut = int(vIn);
				Processor<unsigned short> *limit = new Limiter<unsigned short>();
				limit->processBuffer(wav.getBufferShort(), wav.getBufferSize(), vOut);
				do {
				cout << "Please enter new file name with a .wav extension at the end" << endl;
				cin >> newFile;
				}
				while(noneOfTheCurrentFiles(newFile) == false);
				wav.writeFile(newFile);
				delete limit;
			}
			else {
				Processor<unsigned char> *limit = new Limiter<unsigned char>();
				limit->processBuffer(wav.getBuffer(), wav.getBufferSize(), wav.getBitType());
				do {
					cout << "Please enter new file name with a .wav extension at the end" << endl;
					cin >> newFile;
				}
				while(noneOfTheCurrentFiles(newFile) == false);
				wav.writeFile(newFile);
				delete limit;
			}
			}
			break;
		default:
			cout << "Please enter a valid option!" << endl;
	}
}
bool noneOfTheCurrentFiles(string newFile) {
	int fileIndex;
	vector<string> filenames;
        for(auto& p: fs::directory_iterator("test")) {
	filenames.emplace_back(p.path().filename());
	}
	for(auto item: filenames) {
	if(newFile == item) {
		cout << "Test 1" << endl;
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
