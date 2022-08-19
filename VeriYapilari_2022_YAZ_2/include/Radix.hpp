

/* 
 * File:   Radix.hpp
 * Author: HAKAN KIRIK
 *
 * Created on August 18, 2022, 11:26 PM
 */

#ifndef RADIX_HPP
#define RADIX_HPP

#include "Queue.hpp"
#include <math.h>

class Radix {
private:
    int* numbers;
    int length;
    Queue **queues;
    int maxStep;

    int MaxStepNumber();
    int StepCount(int);
public:
    Radix(Queue*);
    Queue* Sort();
    ~Radix();
};


#endif /* RADIX_HPP */

