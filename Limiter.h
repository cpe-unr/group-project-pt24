#ifndef LIMITER_H
#define LIMITER_H
#include "Processor.h"

class Limiter : public Processor {
public:
	void processBuffer(unsigned char* buffer, int bufferSize);
};


#endif
