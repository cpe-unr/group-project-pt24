#ifndef LIMITER_H
#define LIMITER_H
#include "Processor.h"
#include <stdio.h>
#include <math.h>

template<class T>
class Limiter : public Processor<T> {
public:
	void processBuffer(T *buffer, int bufferSize, int bitType) {
		const T ZERO = (T) (pow(2, bitType)/2);
		const T LIMIT = (T) (((pow(2, bitType)/2)-1) * (0.8));
		const T UPPER_LIMIT = ZERO + LIMIT;
		const T LOWER_LIMIT = ZERO - LIMIT;
		for(int i = 0; i < bufferSize; i++) {
			buffer[i] = buffer[i] > UPPER_LIMIT ? UPPER_LIMIT : buffer[i];
			buffer[i] = buffer[i] < LOWER_LIMIT ? LOWER_LIMIT : buffer[i];
		}
	}
};


#endif
