#include "../include/stack.h"

SqStack* stackInit()        // ????????
{
    SqStack *s = (SqStack*) malloc(sizeof (SqStack));
    if (s != NULL)
        s->top = -1;
    return s;
}

void stackDestroy(SqStack *s)       // 销毁栈
{
    free(s);
}

int stackEmpty(SqStack *s)      // 判断栈是否为空
{
    if(-1 == s->top)
        return 1;
    else
        return 0;
}

void stackPush(SqStack *s, char e)      // 压栈
{
    (s->top)++;
    s->data[s->top] = e;
}

void stackPop(SqStack *s, char* e)      // 出栈
{
    *e = s->data[s->top];
    (s->top)--;
}

char stackGetTop(SqStack *s)        // 获取栈顶元素返回
{
    return s->data[s->top];
}


