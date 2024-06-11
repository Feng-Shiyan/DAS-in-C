#ifndef UNTITLED_QUEUE_H
#define UNTITLED_QUEUE_H
#include "dataStructure.h"

// --------------------------------- 顺序队 ------------------------------------
typedef struct
{
    char data [MAX_SIZE];
    int front, rear;
}SqQueue;

void SqQueue_Init(SqQueue *queue);        // 初始化队列
void SqQueue_Destroy(SqQueue *queue);       // 销毁队列
bool SqQueue_Empty(SqQueue *queue);      // 判断队是否为空
bool SqQueue_en(SqQueue *queue, char e);     // 进队，插入元素 e
bool SqQueue_de(SqQueue *queue, char *e);    // 出队，将出队元素存入 e 中


#endif //UNTITLED_QUEUE_H
