#include "../include/Cc_queue.h"

// 初始化队列
void CcQueue_Init(Cc_Queue * queue)
{
    queue = (Cc_Queue*) malloc(sizeof (Cc_Queue));
    queue->front = 0;
    queue->count = 0;
}

// 进队
bool CcQueue_En(Cc_Queue * queue, int x)
{
    int rear;
    if (MAX_SIZE == queue->count)
        return false;
    else
    {
       rear = (queue->front + queue->count) % MAX_SIZE; // 计算队尾位置
       rear = (rear + 1) % MAX_SIZE;        // 队尾指针 + 1
       queue->data[rear] = x;
       queue->count++;
        return true;
    }

}

// 出队
bool CcQueue_De(Cc_Queue * queue, int x)
{
    if ( 0 == queue->count)
        return false;
    else
    {
        queue->front = (queue->front + 1) % MAX_SIZE;   // 队头 + 1
        x = queue->data[queue->front];
        queue->count--;         // 元素个数 - 1
        return true;
    }
}

// 判断队是否为空
bool CcQueue_Empty(Cc_Queue * queue)
{
    return ( 0 == queue->count);
}

