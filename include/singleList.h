#ifndef UNTITLED_SINGLELIST_H
#define UNTITLED_SINGLELIST_H

#include "dataStructure.h"

// --------------------------------- 单链表 ------------------------------------

typedef struct singleNode       // 单链表定义
{
    int data;
    struct singleNode* next;
}singleNode;

singleNode* Crt_singleList_head();      // 创建单链表(前插法)
singleNode* Crt_singleList_tail();      // 创建单链表(后插法)
void Dis_singleList(singleNode* l);     // 显示单链表内容
void Inverted_singleList(singleNode* l);    // 逆置单链表
void Delete_duplicateNodes(singleNode* l);  // 删除单链表重复结点
void Delete_Node(singleNode* l);            // 删除单链表当前结点


#endif //UNTITLED_SINGLELIST_H
