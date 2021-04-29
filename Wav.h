//Authors: Samuel DeLange, Jamie Lee, Nikhil Sharma
//Group Project
//4/27/2021

//for only 8bit mono so far...

#ifndef WAV_H
#define WAV_H

#include "WaveHeader.h"

class Wav{
	unsigned char* buffer = NULL;
	short* shortBuffer = NULL;
	wav_header waveHeader;
	short bitType;
public:
	void readFile(const std::string &fileName);
	void writeFile(const std::string &outFileName);

	unsigned char *getBuffer();
	short *getShortBuffer();
	int getBufferSize() const;

	short getBitType();
	void setBitType(short);

	virtual ~Wav();	
};


#endif //WAV_H
