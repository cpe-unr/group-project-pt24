/** @file */

//Authors: Samuel DeLange, Jamie Lee, Nikhil Sharma
//Group Project
//4/22/2021

#include <iostream>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <boost/filesystem.hpp>

using namespace boost::filesystem;
using namespace std;

void subMenuMD();
void subMenuAP();
bool noneOfTheCurrentFiles(string newFile);
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
			subMenuAP()	
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
			viewMetadata(chosenFile());
			break;
		case 2:	
			editMetaData(chosenFile());	
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
	Wav wav;
	switch(userChoiceAP){
		case 1:
			//wav.readFile(fileDir + chosenFile());
			//Processor *normalize = new Normalize();
			//normalize->processBuffer(wav.getBuffer(), wav.getBufferSize());
			//while(noneOfTheCurrentFiles(newFile)) {
				//cout << "Please enter new file name" << endl;
				//cin >> newFile;
			//}}
			//wav.writeFile(newFile);
			//delete normalize;
			break;
		case 2:	
			//wav.readFile(fileDir + chosenFile());
			//Processor *noise = new NoiseGate();
			//noise->processBuffer(wav.getBuffer(), wav.getBufferSize());
			//while(noneOfTheCurrentFiles(newFile)) {
				//cout << "Please enter new file name" << endl;
				//cin >> newFile;
			//}}
			//wav.writeFile(newFile);
			//delete noise;	
			break;
		case 3:
			//wav.readFile(fileDir + chosenFile());
			//Processor *processor = new Echo(10);
			//processor->processBuffer(wav.getBuffer(), wav.getBufferSize());
			//while(noneOfTheCurrentFiles(newFile)) {
				//cout << "Please enter new file name" << endl;
				//cin >> newFile;
			//}}
			//wav.writeFile(newFile);
			//delete processor;
			break;
		case 4:
			//wav.readFile(fileDir + chosenFile());
			//Processor *limit = new Limiter();
			//limit->processBuffer(wav.getBuffer(), wav.getBufferSize());
			//while(noneOfTheCurrentFiles(newFile)) {
				//cout << "Please enter new file name" << endl;
				//cin >> newFile;
			//}}
			//wav.writeFile(newFile);
			//delete limit;
			break;
		case 5:
			break;
		default:
			cout << "Please enter a valid option!" << endl;
	}
}
bool noneOfTheCurrentFiles(string newFile) {
	char cwd[PATH_MAX];
	getcwd(cwd, sizeof(cwd));
	std::string sfile = "/test/";
        std::string fileDir = cwd+sfile;
    path p(fileDir);
    for (auto i = directory_iterator(p); i != directory_iterator(); i++) {
        if (!is_directory(i->path())) {
            if(newFile == i->path().filename().string()) {
	    	return true;
            }
	    else {
		return false;
	    }
	}
        else
            continue;
    }
}
string chosenFile() {
	char cwd[PATH_MAX];
	getcwd(cwd, sizeof(cwd));
	std::string sfile = "/test/";
        std::string fileDir = cwd+sfile;
	int chosenFileNum;
	string chosenFile;
	cout << "Please choose from the files below." << endl;
    path p(fileDir);
    for (auto i = directory_iterator(p); i != directory_iterator(); i++) {
        if (!is_directory(i->path())) {
            cout << i << ". " << i->path().filename().string() << endl;
	}
        else
            continue;
    }	
	cin >> chosenFileNum;
    for (auto i = directory_iterator(p); i != directory_iterator(); i++) {
        if (!is_directory(i->path())) {
            if(i == chosenFileNum) [
		chosenFile = i->path().filename().string();
	}
        else
            continue;
    }
	return chosenFile;
}
