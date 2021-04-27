//Authors: Samuel DeLange, Jamie Lee, Nikhil Sharma
//Group Project
//4/27/2021

//for only 8bit mono so far...

#ifndef WAV_H
#define WAV_H

#include "WaveHeader.h"

class Wav{
	unsigned char* buffer = NULL;
	wav_header waveHeader;
public:
	void readFile(const std::string &fileName);
	void writeFile(const std::string &outFileName);

	unsigned char *getBuffer();
	int getBufferSize() const;

	virtual ~Wav();	
};


#endif //WAV_H
