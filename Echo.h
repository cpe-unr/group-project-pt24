#ifndef ECHO_H
#define ECHO_H
#include "Processor.h"

class Echo : public Processor {
	unsigned char delay;
public:

	Echo(unsigned char delay);

	unsigned char &getDelay();
	void setDelay(unsigned char &delay);

	void processBuffer(unsigned char* buffer, int bufferSize);

};
#endif
