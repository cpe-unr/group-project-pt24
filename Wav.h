//Authors: Samuel DeLange, Jamie Lee, Nikhil Sharma
//Group Project
//4/27/2021

#ifndef WAV_H
#define WAV_H

#include "WaveHeader.h"

class Wav{
	unsigned char* buffer = NULL;
	unsigned short* bufferShort = NULL;

	short bitType;
public:
	wav_header waveHeader;
	void readFile(const std::string &fileName);
	void writeFile(const std::string &outFileName);

	unsigned char *getBuffer();
	unsigned short *getBufferShort();
	int getBufferSize() const;

	short getBitType();
	void setBitType(short);

	virtual ~Wav();	
};

#endif //WAV_H
