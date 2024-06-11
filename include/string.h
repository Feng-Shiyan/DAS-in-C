#ifndef UNTITLED_STRING_H
#define UNTITLED_STRING_H

#include "dataStructure.h"

// --------------------------------- 串 ------------------------------------

typedef struct
{
    char* data;
    int length;
}SqString;

char* stringInit(SqString * sqstring);
void stringAssignment(char* s1, SqString* s);    // 字符串赋值
void stringDisplay(SqString* s);                // 显示字符串
int BF (SqString* pattern, SqString* target);   // 暴力搜索，返回匹配的第一个下标
int KMP(SqString* pattern, SqString* target);   // pattern 为模式串，target 为主串

#endif //UNTITLED_STRING_H
