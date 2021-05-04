#include "Menu.h"

using namespace std;

void Menu::subMenuMD() {
	char cwd[PATH_MAX];
	getcwd(cwd, sizeof(cwd));
	std::string sfile = "/test/";
        std::string fileDir = cwd+sfile;
	int userChoiceMD;
	char userTitle[50], userArtist[50], userComments[50];
	cout << "Please choose from one of the options below" << endl;
	cout << "1. View metaData" << endl;
	cout << "2. Modify metadata" << endl;
	cout << "3. Exit" << endl;
	cin >> userChoiceMD;
	switch(userChoiceMD){
		case 1:{
			Filesystem filesystem;
			DataManager dataManager(fileDir + filesystem.chosenFile());
			dataManager.viewMetadata();
			}
			break;
		case 2:	{
			/*Filesystem filesystem;
			Wav wav;
			
			cout << "Enter new title: " << endl;
			cin >> userTitle;
			cout << "Enter new artist: " << endl;
			cin >> userArtist;
			cout << "Enter new comments: " << endl;
			cin >> userComments;
			
			
			
			cout << "---Confirm choice---" << endl;
			
			/*DataManager dataManager;
			dataManager.editMetadata(fileDir + filesystem.chosenFile(), userTitle, userArtist, userComments);*/	
			}
			break;
		case 3:	{
			}
			break;
		default:
			cout << "Please enter a valid option!" << endl;
	}
}

void Menu::subMenuAP() {
	int repeatUserChoice;
	do {
	repeatUserChoice = 1;
	int userChoiceAP;
	char cwd[PATH_MAX];
	getcwd(cwd, sizeof(cwd));
	std::string sfile = "/test/";
        std::string fileDir = cwd+sfile;
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
			Filesystem filesystem;
			wav.readFile(fileDir + filesystem.chosenFile());
			if(wav.getBitType() == 16) {
				short int vIn = wav.getBitType();
				int vOut = int(vIn);
				Processor<unsigned short> *normalize = new Normalize<unsigned short>();
				normalize->processBuffer(wav.getBufferShort(), wav.getBufferSize(), vOut, wav.getNumChannels());
				do {
				cout << "Please enter new file name with a .wav extension at the end" << endl;
				cin >> newFile;
				}
				while(filesystem.noneOfTheCurrentFiles(newFile) == false);
				wav.writeFile(fileDir + newFile);
				delete normalize;
			}
			else {
				Processor<unsigned char> *normalize = new Normalize<unsigned char>();
				normalize->processBuffer(wav.getBuffer(), wav.getBufferSize(), wav.getBitType(), wav.getNumChannels());
				do {
					cout << "Please enter new file name with a .wav extension at the end" << endl;
					cin >> newFile;
				}
				while(filesystem.noneOfTheCurrentFiles(newFile) == false);
				wav.writeFile(fileDir + newFile);
				delete normalize;
			}
			}
			break;
		case 2:	{
			Wav wav;
			Filesystem filesystem;
			wav.readFile(fileDir + filesystem.chosenFile());
			if(wav.getBitType() == 16) {
				short int vIn = wav.getBitType();
				int vOut = int(vIn);
				Processor<unsigned short> *noise = new NoiseGate<unsigned short>(6400);
				noise->processBuffer(wav.getBufferShort(), wav.getBufferSize(), vOut, wav.getNumChannels());
				do {
				cout << "Please enter new file name with a .wav extension at the end" << endl;
				cin >> newFile;
				}
				while(filesystem.noneOfTheCurrentFiles(newFile) == false);
				wav.writeFile(fileDir + newFile);
				delete noise;
			}
			else {
				Processor<unsigned char> *noise = new NoiseGate<unsigned char>(25);
				noise->processBuffer(wav.getBuffer(), wav.getBufferSize(), wav.getBitType(), wav.getNumChannels());
				do {
					cout << "Please enter new file name with a .wav extension at the end" << endl;
					cin >> newFile;
				}
				while(filesystem.noneOfTheCurrentFiles(newFile) == false);
				wav.writeFile(fileDir + newFile);
				delete noise;
			}
			}
			break;
		case 3: {
			Wav wav;
			Filesystem filesystem;
			wav.readFile(fileDir + filesystem.chosenFile());
			if(wav.getBitType() == 16) {
				short int vIn = wav.getBitType();
				int vOut = int(vIn);
				Processor<unsigned short> *processor = new Echo<unsigned short>(256000);
				processor->processBuffer(wav.getBufferShort(), wav.getBufferSize(), vOut, wav.getNumChannels());
				do {
				cout << "Please enter new file name with a .wav extension at the end" << endl;
				cin >> newFile;
				}
				while(filesystem.noneOfTheCurrentFiles(newFile) == false);
				wav.writeFile(fileDir + newFile);
				delete processor;
			}
			else {
				Processor<unsigned char> *processor = new Echo<unsigned char>(32000);
				processor->processBuffer(wav.getBuffer(), wav.getBufferSize(), wav.getBitType(), wav.getNumChannels());
				do {
					cout << "Please enter new file name with a .wav extension at the end" << endl;
					cin >> newFile;
				}
				while(filesystem.noneOfTheCurrentFiles(newFile) == false);
				wav.writeFile(fileDir + newFile);
				delete processor;
			}
			}
			break;
		case 4: {
			Wav wav;
			Filesystem filesystem;
			wav.readFile(fileDir + filesystem.chosenFile());
			if(wav.getBitType() == 16) {
				short int vIn = wav.getBitType();
				int vOut = int(vIn);
				Processor<unsigned short> *limit = new Limiter<unsigned short>();
				limit->processBuffer(wav.getBufferShort(), wav.getBufferSize(), vOut, wav.getNumChannels());
				do {
				cout << "Please enter new file name with a .wav extension at the end" << endl;
				cin >> newFile;
				}
				while(filesystem.noneOfTheCurrentFiles(newFile) == false);
				wav.writeFile(fileDir + newFile);
				delete limit;
			}
			else {
				Processor<unsigned char> *limit = new Limiter<unsigned char>();
				limit->processBuffer(wav.getBuffer(), wav.getBufferSize(), wav.getBitType(), wav.getNumChannels());
				do {
					cout << "Please enter new file name with a .wav extension at the end" << endl;
					cin >> newFile;
				}
				while(filesystem.noneOfTheCurrentFiles(newFile) == false);
				wav.writeFile(fileDir + newFile);
				delete limit;
			}
			}
			break;
		default:
			cout << "Please enter a valid option!" << endl;
	}
	cout << "Would you like to process again" << endl;
	cout << "1. Yes" << endl << "2. No" << endl;
	cin >> repeatUserChoice;
	}
	while(repeatUserChoice == 1);
	
}

GenerateCSV generateCSV;

void Menu::createCSV() {
	generateCSV.generate();
}
