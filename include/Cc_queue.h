#ifndef DSA_IN_C_CC_QUEUE_H
#define DSA_IN_C_CC_QUEUE_H
#include "dataStructure.h"

// --------------------------------- 环形队 ------------------------------------
typedef struct
{
    int data[MAX_SIZE];
    int front;              // 队头指针
    int count;              // 队列中元素的个数
}Cc_Queue;

// 初始化队列
void CcQueue_Init(Cc_Queue * queue);

// 进队
bool CcQueue_En(Cc_Queue * queue, int x);

// 出队
bool CcQueue_De(Cc_Queue * queue, int x);

// 判断队是否为空
bool CcQueue_Empty(Cc_Queue * queue);

#endif //DSA_IN_C_CC_QUEUE_H
