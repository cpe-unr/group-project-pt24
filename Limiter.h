#ifndef LIMITER_H
#define LIMITER_H

#include "Processor.h"
#include <stdio.h>
#include <math.h>
/**
 * This is the template limiter class which inherits from the processor class. 
*/
template<class T>
class Limiter : public Processor<T> {
public:

/**
 * Processes buffer so that any audio that is higher than the rest is changed to a lower value.
 * \param[in]     buffer       Buffer that has already been read.
 * \param[in]     bufferSize   Size of Buffer.
 * \param[in]     bitType      Bit type of buffer (8 or 16, could be any number).
 * \param[in]     num_channels Number of channels so that proccessor can process multiple stereo wav files.
*/
	void processBuffer(T *buffer, int bufferSize, int bitType, short num_channels) {
		const T ZERO = (T) (pow(2, bitType)/2);
		const T LIMIT = (T) (((pow(2, bitType)/2)-1) * (0.8));
		const T UPPER_LIMIT = ZERO + LIMIT;
		const T LOWER_LIMIT = ZERO - LIMIT;

		if(num_channels == 2) {
			for(int i = 0; i < bufferSize; i = i + 2) {
				buffer[i] = buffer[i] > UPPER_LIMIT ? UPPER_LIMIT : buffer[i];
				buffer[i] = buffer[i] < LOWER_LIMIT ? LOWER_LIMIT : buffer[i];
			}
			for(int i = 1; i < bufferSize; i = i + 2) {
				buffer[i] = buffer[i] > UPPER_LIMIT ? UPPER_LIMIT : buffer[i];
				buffer[i] = buffer[i] < LOWER_LIMIT ? LOWER_LIMIT : buffer[i];
			}
		}
		if(num_channels == 1) {
			for(int i = 0; i < bufferSize; i++) {
				buffer[i] = buffer[i] > UPPER_LIMIT ? UPPER_LIMIT : buffer[i];
				buffer[i] = buffer[i] < LOWER_LIMIT ? LOWER_LIMIT : buffer[i];
			}
		}
	}
};


#endif
