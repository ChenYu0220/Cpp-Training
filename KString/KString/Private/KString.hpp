//
//  KString.hpp
//  KString
//
//  Created by 陈上雁 on 2023/7/10.
//

#ifndef KString_hpp
#define KString_hpp
#include "iostream"
#include <stdio.h>
#include "vector"

using namespace std;

class KString{
public:
    KString(const char* _str = nullptr); // 默认构造函数
    KString(const KString& _other); // 拷贝构造函数
    ~KString(); // 析构函数
    
    unsigned long len(); // 返回值使用 int 可能会导致精度丢失
    // 查找子串的 index
    int find(char* subString);
    int find(char& subString);
    // 重载 == 操作
    bool operator == (const KString& _other);
    // 查找字串
    KString sub(int startIndex, int endIndex);
    // append 操作
    void append(char* _other);
    void append(KString& _other);
    // split 方法对子串进行分割
    vector<KString>* split(char* splitString);
protected:
    void setKStringDataByOther(char* _other); // 通过其他字符串为 _chars 赋值
    
private:
    char* _chars {nullptr}; // 数据存放的位置
};
#endif /* KString_hpp */
