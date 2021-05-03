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

	void processBuffer(T *buffer, int bufferSize, int bitType, short num_channels) {
		const T ZERO = (pow(2, bitType)/2);

		if(num_channels == 2) {
			for(int i = 1; i < bufferSize; i = i + 1) {
				if(buffer[i] > (ZERO - threshold) && buffer[i] < (ZERO + threshold)) {
					buffer[i] = ZERO;
				}
			}
			for(int i = 0; i < bufferSize; i = i + 1) {
				if(buffer[i] > (ZERO - threshold) && buffer[i] < (ZERO + threshold)) {
					buffer[i] = ZERO;
				}
			}
		}
		if(num_channels == 1) {
			for(int i = 0; i < bufferSize; i++) {
				if(buffer[i] > (ZERO - threshold) && buffer[i] < (ZERO + threshold)) {
					buffer[i] = ZERO;
				}
			}
		}	
	}

};
#endif
