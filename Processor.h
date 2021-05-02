//
// Created by Keith Lancaster on 3/13/21.
//

#ifndef PROGRAMMING_ASSIGNMENT_3KL_PROCESSOR_H
#define PROGRAMMING_ASSIGNMENT_3KL_PROCESSOR_H

#include <iostream>
#include <cstdint>
#include <cmath>
template <typename T>
class Processor {
public:
    virtual void processBuffer(T *buffer, int bufferSize, int bitType) = 0;
};


#endif //PROGRAMMING_ASSIGNMENT_3KL_PROCESSOR_H
