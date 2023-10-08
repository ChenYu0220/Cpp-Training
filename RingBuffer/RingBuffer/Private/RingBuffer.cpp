//
//  RingBuffer.cpp
//  RingBuffer
//
//  Created by 陈上雁 on 2023/10/9.
//

#include "RingBuffer.hpp"
#include "iostream"
using namespace std;

#define min(a,b) ((a<b)?(a):(b))

KRingBuffer::KRingBuffer(unsigned int lens)
{
    buffer = new char[lens];
    size = lens;
    front = 0;
    rear = 0;
}

KRingBuffer::~KRingBuffer(){
    delete buffer;
}

bool KRingBuffer::isEmpty(){
    return ((front == rear) && validLen == 0);
}

