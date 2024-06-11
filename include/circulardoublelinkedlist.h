#ifndef UNTITLED_CIRCULARDOUBLELINKEDLIST_H
#define UNTITLED_CIRCULARDOUBLELINKEDLIST_H

#include "dataStructure.h"

// --------------------------------- 循环双链表 ------------------------------------

typedef struct cir_DoubleLL
{
    int data;
    struct cir_DoubleLL * prior;
    struct cir_DoubleLL * next;
}CircularDoubleLinkedList;

int CircularDoubleLinkedList_Create(int n, CircularDoubleLinkedList *first_node,
                                    CircularDoubleLinkedList *last_node);  // 创建长度为 n 的循环双链表，并给每个节点赋值

void CircularDoubleLinkedList_Display(int length, CircularDoubleLinkedList* circularDoubleLinkedList);
// 输出双链表内容

void CircularDoubleLinkedNode_Delete
        (int *a,CircularDoubleLinkedList * first_node, CircularDoubleLinkedList* destination_node);
// 删除当前节点，同时返回背删除的节点的值

void Joseph(int n, int m,int res[], CircularDoubleLinkedList* circularDoubleLinkedList);
// 约瑟夫环

void find (int n, int m,int k, int * res, CircularDoubleLinkedList* circularDoubleLinkedList);
// 返回编号 k 的人的出队序号

#endif //UNTITLED_CIRCULARDOUBLELINKEDLIST_H
