#ifndef NOISE_GATE_H
#define NOISE_GATE_H

#include "Processor.h"
#include <math.h>
/**
 * This is the template noise gate class which inherits from the processor class. 
*/
template<class T>
class NoiseGate : public Processor<T> {
private:
	T threshold;
public:

/**
 *
 * Constructor for the NoiseGate class. 
 * \param[i] threshold  The threshold to keep audio below
*/
	explicit NoiseGate(T threshold) : threshold(threshold) {
	}

/**
 * Processes buffer so that all audio above or below a range is set to zero (eliminated).
 * \param[in]     buffer       Buffer that has already been read.
 * \param[in]     bufferSize   Size of Buffer.
 * \param[in]     bitType      Bit type of buffer (8 or 16, could be any number).
 * \param[in]     num_channels Number of channels so that proccessor can process multiple stereo wav files.
*/
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
