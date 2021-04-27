#ifndef ECHO_H
#define ECHO_H
#include "Processor.h"
#include <math.h>

template<class T, class U class P>
class Echo : public Processor {
	T delay;
public:

	explicit Echo(T delay) : delay(delay) {
	}

	void processBuffer(U buffer, int bufferSize, int bitType) override {
		static const P ZERO = (pow(2, bitType)/2);
		static const float SCALE_FACTOR = 0.5f;
		float adj_i, adj_delayed_i, val;
		float echoLevel = 0.5f;
		for(int i = 0; i < bufferSize - delay; i++) {
			adj_i = (float)(buffer[i] - ZERO);
			adj_delayed_i = (float)(buffer[i + delay] - ZERO);
			val = adj_i * echoLevel + adj_delayed_i * SCALE_FACTOR + ZERO;
			buffer[i + delay] = (P)(round(val));
		}
	}

};
#endif
