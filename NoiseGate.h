#ifndef NOISE_GATE_H
#define NOISE_GATE_H
#include "Processor.h"

class NoiseGate : public Processor{
public:
	void processBuffer(unsigned char* buffer, int bufferSize);

};
#endif
