#include "../include/Sq_queue.h"

// --------------------------------- 顺序队 ------------------------------------

void SqQueue_Init(SqQueue *queue)
{
    queue = (SqQueue *)malloc(sizeof (SqQueue));
    queue->front = queue->rear = -1;
}

void SqQueue_Destroy(SqQueue *queue)
{
    free(queue);
}

bool SqQueue_Empty(SqQueue *queue)
{
    return (queue->front == queue->rear ) ? true : false;
}

bool SqQueue_en(SqQueue *queue, char e)
{
    if (queue->rear == MAX_SIZE - 1 )
        return false;
    queue->rear++;
    queue->data[queue->rear] = e;
}

bool SqQueue_de(SqQueue *queue, char* e)
{

}