#ifndef LIMITER_H
#define LIMITER_H
#include "Processor.h"

template<class T>
class Limiter : public Processor<T> {
public:
	void processBuffer(T *buffer, int bufferSize, int bitType) {
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
