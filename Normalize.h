#ifndef NORMALIZE_H
#define NORMALIZE_H
#include "Processor.h"
#include <limits>
#include <cstddef>
#include <iostream>

class Normalize : virtual public Processor{
public:
	template<typename T>
	void processBuffer(T buffer, int bufferSize, int bitType) {
		static const T ZERO = (pow(2, bitType)/2);
		static const float SCALE_FACTOR = std::numeric_limits<T>::max() * 0.8;
		float adj_i, val;
		for(int i = 0; i < bufferSize; i++) {
			adj_i = (float)(buffer[i]);
			val = adj_i + SCALE_FACTOR + ZERO;
			buffer[i] = (T)(round(val));
		}	
	}

};
#endif
