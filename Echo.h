#ifndef ECHO_H
#define ECHO_H

#include "Processor.h"
#include <math.h>
#include <utility>
/**
 * This is the template echo class which inherits from the processor class. 
*/
template<class T>
class Echo : public Processor<T> {
private:
	int delay;
public:

/**
 *
 * Constructor for the Echo class. 
 * \param[i] delay  the delay of the sample
*/
	explicit Echo(int delay) : delay(delay) {
	}

/**
 * Processes buffer so that an Echo is present.
 * \param[in]     buffer       Buffer that has already been read.
 * \param[in]     bufferSize   Size of Buffer.
 * \param[in]     bitType      Bit type of buffer (8 or 16, could be any number).
 * \param[in]     num_channels Number of channels so that proccessor can process multiple stereo wav files.
*/
	void processBuffer(T *buffer, int bufferSize, int bitType, short num_channels) {
		static const T ZERO = (pow(2, bitType)/2);
		static const float SCALE_FACTOR = 0.5f;
		float adj_i, val, adj_delayed_i;
		float echoLevel = 0.5f;

		if(num_channels == 2) {
			for(int i = 0; i < bufferSize - delay; i = i+2) {
				adj_i = (float)(buffer[i + delay] - ZERO);
				adj_delayed_i = (float)(buffer[i+delay] - ZERO);
				val = adj_i * echoLevel + adj_delayed_i * SCALE_FACTOR + ZERO;
				buffer[i + delay] = (T)(round(val));
			}
			for(int i = 1; i < bufferSize - delay; i = i+2) {
				adj_i = (float)(buffer[i + delay] - ZERO);
				adj_delayed_i = (float)(buffer[i+delay] - ZERO);
				val = adj_i * echoLevel + adj_delayed_i * SCALE_FACTOR + ZERO;
				buffer[i + delay] = (T)(round(val));
			}
		}
		if(num_channels == 1) {
			for(int i = 0; i < bufferSize - delay; i = i++) {
				adj_i = (float)(buffer[i + delay] - ZERO);
				adj_delayed_i = (float)(buffer[i+delay] - ZERO);
				val = adj_i * echoLevel + adj_delayed_i * SCALE_FACTOR + ZERO;
				buffer[i + delay] = (T)(round(val));
			}
		}
	}

};
#endif
