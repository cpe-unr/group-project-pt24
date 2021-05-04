#include "Menu.h"

using namespace std;
namespace fs = experimental::filesystem;

void Menu::subMenuMD() {
	char cwd[PATH_MAX];
	getcwd(cwd, sizeof(cwd));
	std::string sfile = "/test/";
        std::string fileDir = cwd+sfile;
	int userChoiceMD;
	cout << "Please choose from one of the options below" << endl;
	cout << "1. View metaData" << endl;
	cout << "2. Modify metadata" << endl;
	cout << "3. Exit" << endl;
	cin >> userChoiceMD;
	switch(userChoiceMD){
		case 1:{
			DataManager dataManager(fileDir + chosenFile());
			dataManager.viewMetadata();
			}
			break;
		case 2:	{
			//editMetaData(chosenFile());	
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
				normalize->processBuffer(wav.getBufferShort(), wav.getBufferSize(), vOut, wav.getNumChannels());
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
				normalize->processBuffer(wav.getBuffer(), wav.getBufferSize(), wav.getBitType(), wav.getNumChannels());
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
				noise->processBuffer(wav.getBufferShort(), wav.getBufferSize(), vOut, wav.getNumChannels());
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
				noise->processBuffer(wav.getBuffer(), wav.getBufferSize(), wav.getBitType(), wav.getNumChannels());
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
				processor->processBuffer(wav.getBufferShort(), wav.getBufferSize(), vOut, wav.getNumChannels());
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
				processor->processBuffer(wav.getBuffer(), wav.getBufferSize(), wav.getBitType(), wav.getNumChannels());
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
				limit->processBuffer(wav.getBufferShort(), wav.getBufferSize(), vOut, wav.getNumChannels());
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
				limit->processBuffer(wav.getBuffer(), wav.getBufferSize(), wav.getBitType(), wav.getNumChannels());
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

GenerateCSV generateCSV;

void Menu::createCSV() {
	generateCSV.generate();
}
