//
//  KString.cpp
//  KString
//
//  Created by 陈上雁 on 2023/7/10.
//

#include "KString.hpp"

void KString::setKStringDataByOther(char* _other)
{
    delete[] _chars;
    unsigned long charLength = strlen(_other); // 使用 int 可能会精度丢失，编译器会报错
    _chars = new char[charLength+1];
    _chars[charLength] = '\0';
    strcpy(_chars, _other);
}

unsigned long KString::len()
{
    if(_chars == nullptr){
        return 0;
    }
    unsigned long length = strlen(_chars);
    return length;
}
