#ifndef NORMALIZE_H
#define NORMALIZE_H

#include "Processor.h"
#include <limits>
#include <cstddef>
#include <iostream>

template<class T>
class Normalize : public Processor<T>{
public:
	void processBuffer(T *buffer, int bufferSize, int bitType, short num_channels) {
		static const T ZERO = (pow(2, bitType)/2);
		static const float SCALE_FACTOR = std::numeric_limits<T>::max() * 0.8;
		float adj_i, val;

		if(num_channels == 2) {
			for(int i = 1; i < bufferSize; i = i + 1) {
				adj_i = (float)(buffer[i]);
				val = adj_i + SCALE_FACTOR + ZERO;
				buffer[i] = (T)(round(val));
			}
			for(int i = 0; i < bufferSize; i = i + 1) {
				adj_i = (float)(buffer[i]);
				val = adj_i + SCALE_FACTOR + ZERO;
				buffer[i] = (T)(round(val));
			}
		}
		if(num_channels == 1) {
			for(int i = 0; i < bufferSize; i++) {
				adj_i = (float)(buffer[i]);
				val = adj_i + SCALE_FACTOR + ZERO;
				buffer[i] = (T)(round(val));
			}
		}	
	}

};
#endif
