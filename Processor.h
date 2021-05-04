//
// Created by Keith Lancaster on 3/13/21.
//

#ifndef PROGRAMMING_ASSIGNMENT_3KL_PROCESSOR_H
#define PROGRAMMING_ASSIGNMENT_3KL_PROCESSOR_H

#include <iostream>
#include <cstdint>
#include <cmath>
/**
 * This is the template interface processor class. 
*/
template <typename T>
class Processor {
public:
/**
 * Virtual function to process buffers.
 * \param[in]     buffer       Buffer that has already been read.
 * \param[in]     bufferSize   Size of Buffer.
 * \param[in]     bitType      Bit type of buffer (8 or 16, could be any number).
 * \param[in]     num_channels Number of channels so that proccessor can process multiple stereo wav files.
*/
    virtual void processBuffer(T *buffer, int bufferSize, int bitType, short num_channels) = 0;
};


#endif //PROGRAMMING_ASSIGNMENT_3KL_PROCESSOR_H
