#ifndef UNTITLED_STACK_H
#define UNTITLED_STACK_H

#include "dataStructure.h"

// --------------------------------- 顺序栈 ------------------------------------

typedef struct                  //  顺序栈
{
    char data[MAX_SIZE];
    int top;
}SqStack;

SqStack* stackInit();         // 初始化栈，构造一个空栈
void stackDestroy(SqStack *s);      // 销毁栈
int stackEmpty(SqStack *s);         // 判断栈是否为空
void stackPush(SqStack *s, char e);     // 压栈
void stackPop(SqStack *s, char *e);     // 出栈
char stackGetTop(SqStack *s);           // 获取栈顶元素

// --------------------------------- 链式栈 ------------------------------------

#endif //UNTITLED_STACK_H
