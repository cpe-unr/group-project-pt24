#ifndef NORMALIZE_H
#define NORMALIZE_H
#include "Processor.h"
#include <math.h>
#include <limits>

template<class T, class U>
class Normalize : public Processor{
public:
	void processBuffer(T buffer, int bufferSize, int bitType) override {
		static const U ZERO = (pow(2, bitType)/2);
		static const float SCALE_FACTOR = U numeric_limits<U>::max() * 0.8;
		float adj_i, val;
		for(int i = 0; i < bufferSize; i++) {
			adj_i = (float)(buffer[i]);
			val = adj_i + SCALE_FACTOR + ZERO;
			buffer[i] = (U)(round(val));
		}	
	}

};
#endif
