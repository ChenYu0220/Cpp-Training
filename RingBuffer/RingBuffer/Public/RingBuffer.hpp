//
//  RingBuffer.hpp
//  RingBuffer
//
//  Created by 陈上雁 on 2023/10/9.
//

#ifndef RingBuffer_hpp
#define RingBuffer_hpp

#include <stdio.h>
#include "iostream"
using namespace std;

class KRingBuffer {
public:
    KRingBuffer(unsigned int lens);
    ~KRingBuffer();
    
    // rLen 读出的长度
    void read(KRingBuffer *rbuf, int rLen); // 读出 rbuf
    // sourceData 写入数据的指针， wLen 写入的长度
    void write(KRingBuffer *rbuf, const char *sourceData, unsigned int wLen); // 写入 rbuf
    
    void expend(); // 扩容
    void lessen(); // 释放内存
    void freeSpace(); // 清空 buffer
    bool isEmpty(); // 判断 rbuf 是否为空
    unsigned int getSize(); // 获得 rbuf 的长度
    
    
private:
    void buffer_put(char data); // 负责添加数据操作
    char buffer_get(char *r); // 负责获取数据操作
    
    unsigned int size = 0; // rbuf 的大小
    unsigned int validLen = 0; // 已使用的数据长度
    unsigned int front; // rbuf 的首地址
    unsigned int rear; // rbuf 的结尾地址
    char *buffer; // rbuf 的数据
    
};


#endif /* RingBuffer_hpp */
