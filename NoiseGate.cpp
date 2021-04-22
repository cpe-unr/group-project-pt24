#include "NoiseGate.h"

void NoiseGate::processBuffer(unsigned char* buffer, int bufferSize){
	for(unsigned i = 0; i < bufferSize; i++) {
		if(buffer[i] <= 138 && buffer[i] >= 118) {
			buffer[i] = 128;
		}
	}
}
