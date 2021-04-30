#ifndef ECHO_H
#define ECHO_H
#include "Processor.h"
#include <math.h>
#include <utility>

class Echo : public Processor {
private:
	int delay;
public:

	explicit Echo(int delay) : delay(delay) {
	}
	//template<typename U>
	void processBuffer(unsigned char *buffer, int bufferSize, int bitType) {
		static const uint8_t ZERO = (pow(2, bitType)/2);
		static const float SCALE_FACTOR = 2.0f;
		float adj_i, val, adj_delayed_i;
		float echoLevel = 0.5f;
		for(int i = 0; i < bufferSize - delay; i++) {
			adj_i = (float)(buffer[i + delay] - ZERO);
			val = adj_i * echoLevel + adj_delayed_i * SCALE_FACTOR + ZERO;
			buffer[i + delay] = (unsigned char)(round(val));
		}
	}

};
#endif
