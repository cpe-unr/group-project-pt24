#ifndef LIMITER_H
#define LIMITER_H
#include "Processor.h"
#include <math.h>

class Limiter : public Processor {
public:
	template<typename T, typename U>
	void processBuffer(T buffer, int bufferSize, int bitType) {
		const U ZERO = (U) (pow(2, bitType)/2);
		const U LIMIT = (U) (((pow(2, bitType)/2)-1) * (0.8));
		const U UPPER_LIMIT = ZERO + LIMIT;
		const U LOWER_LIMIT = ZERO - LIMIT;
		for(int i = 0; i < bufferSize; i++) {
			buffer[i] = buffer[i] > UPPER_LIMIT ? UPPER_LIMIT : buffer[i];
			buffer[i] = buffer[i] < LOWER_LIMIT ? LOWER_LIMIT : buffer[i];
		}
	}
};


#endif
