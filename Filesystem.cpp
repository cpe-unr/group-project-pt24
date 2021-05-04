#include "Filesystem.h"

using namespace std;
namespace fs = experimental::filesystem;

bool Filesystem::noneOfTheCurrentFiles(string newFile) {
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
string Filesystem::chosenFile() {
	int fileIndex;
	vector<string> filenames;
	string chosenFile = " ";
	do {
	int counter = 1;
	cout << "Please choose from the files below." << endl;
        for(auto& p: fs::directory_iterator("test")) {
        std::cout << counter << ". " << p.path().filename() << '\n';
	filenames.push_back(p.path().filename());
	counter++;
	}
	cin >> fileIndex;
	}
	while (fileIndex > filenames.size() || fileIndex < 1); //Trying to adhere this to SOLID principles. Tho, vector.size doesn't work properly.
	chosenFile = filenames[fileIndex - 1];
	return chosenFile;
}
