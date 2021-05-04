#include "generateCSV.h"

using namespace std;
namespace fs = experimental::filesystem;

void GenerateCSV::generate() {
	char cwd[PATH_MAX];
	getcwd(cwd, sizeof(cwd));
	std::string sfile = "/test/";
        std::string fileDir = cwd+sfile;
	vector<string> filenames;
	std::ofstream myfile;
	myfile.open("generatedCSV.csv");
	for(auto& p: fs::directory_iterator("test")) {
	filenames.emplace_back(p.path().filename());
	}
	for(vector<string>::const_iterator i = filenames.begin(); i != filenames.end(); ++i) {
		Wav wav;
		wav.readFile(fileDir + *i);
		myfile << wav.waveHeader.wav_size << "," << wav.waveHeader.sample_rate << "," << wav.waveHeader.data_bytes << "," << wav.waveHeader.audio_format << "," << wav.waveHeader.num_channels << "," << wav.waveHeader.bit_depth <</* "," << wav.waveHeader.list_header[0] << "," << wav.waveHeader.list_header[1] << "," << wav.waveHeader.list_header[2]*/"\n";
	}
	myfile.close();
}
