#include "Echo.h"

Echo::Echo(unsigned char delay) : delay(delay) {
}

unsigned char &Echo::getDelay() {
	return delay;
}

void Echo::setDelay(unsigned char &delay) {
	Echo::delay = delay;
}
void Echo::processBuffer(unsigned char* buffer, int bufferSize){
	for(unsigned i = 0; i < bufferSize; i++) {
		if(delay <= i) {
			if(buffer[i] <= (255 - buffer[i-delay])) {
				buffer[i] = buffer[i] + buffer[i-delay];
			}
			else {
				buffer[i] = buffer[i];
			}
		}
		else {
			buffer[i] = buffer[i];
		}
	}
}
