#ifndef UNTITLED_DOUBLELIST_H
#define UNTITLED_DOUBLELIST_H

#include "dataStructure.h"

// --------------------------------- 双链表 ------------------------------------

typedef struct double_Node              // 双链表定义
{
    int data;
    struct double_Node* prior;
    struct double_Node* next;
}doubleNode;

doubleNode* Crt_doubleList_head();      // 创建双链表(前插法)
void Dis_doubleList(doubleNode* l);     // 显示双链表

#endif //UNTITLED_DOUBLELIST_H
