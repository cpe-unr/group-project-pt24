#include "Limiter.h"

void Limiter::processBuffer(unsigned char* buffer, int bufferSize){
	for(unsigned i = 0; i < bufferSize; i++) {
		if(buffer[i] >= 228.6) {
			buffer[i] = 228.6;
		}
		else if(buffer[i] <= 25.4) {
			buffer[i] = 25.4;
		}
	}
}
