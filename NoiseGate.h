#ifndef NOISE_GATE_H
#define NOISE_GATE_H
#include "Processor.h"
#include <math.h>

template<class T>
class NoiseGate : public Processor<T> {
private:
	uint8_t threshold;
public:
	explicit NoiseGate(uint8_t threshold) : threshold(threshold) {
	}
	void processBuffer(T *buffer, int bufferSize, int bitType) {
		const uint8_t ZERO = (pow(2, bitType)/2);
		for(int i = 1; i < bufferSize; i++) {
			if(buffer[i] > (ZERO - threshold) && buffer[i] < (ZERO + threshold)) {
				buffer[i] = ZERO;
			}
		}	
	}

};
#endif
