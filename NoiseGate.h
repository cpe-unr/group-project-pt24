#ifndef NOISE_GATE_H
#define NOISE_GATE_H
#include "Processor.h"
#include <math.h>

template<class T>
class NoiseGate : public Processor<T> {
private:
	T threshold;
public:
	explicit NoiseGate(T threshold) : threshold(threshold) {
	}
	void processBuffer(T *buffer, int bufferSize, int bitType) {
		const T ZERO = (pow(2, bitType)/2);
		for(int i = 1; i < bufferSize; i++) {
			if(buffer[i] > (ZERO - threshold) && buffer[i] < (ZERO + threshold)) {
				buffer[i] = ZERO;
			}
		}	
	}

};
#endif
