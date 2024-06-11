#include "../include/circulardoublelinkedlist.h"

int CircularDoubleLinkedList_Create(int n, CircularDoubleLinkedList *first_node,
                                                          CircularDoubleLinkedList *last_node) {
    if (n >= 2)
    {
        CircularDoubleLinkedList* tmp = (CircularDoubleLinkedList*) malloc(sizeof (CircularDoubleLinkedList));
        last_node->next = tmp;
        tmp->next = NULL;
        tmp->prior = NULL;
        tmp->prior = last_node;
        tmp->data = tmp->prior->data + 1;     // 后一个节点的数值比前一个大 1
        CircularDoubleLinkedList_Create(n-1, first_node, tmp);
    }
    if (n == 1)
    {
       last_node->next = first_node;
       first_node->prior = last_node;
       return 0;
    }
}

void CircularDoubleLinkedList_Display(int length, CircularDoubleLinkedList* circularDoubleLinkedList)
{
    while ( length > 0)
    {
       printf ("%d \t ", circularDoubleLinkedList->data);
       circularDoubleLinkedList = circularDoubleLinkedList->next;
       length -= 1;
    }
}

void CircularDoubleLinkedNode_Delete
        (int *a,CircularDoubleLinkedList * first_node, CircularDoubleLinkedList* destination_node)
{
    if (first_node == destination_node->next)
    {
        *a = destination_node->data;
        free(destination_node);
    }
    else
    {
        *a = destination_node->data;
        destination_node->prior->next = destination_node->next;
        destination_node->next->prior = destination_node->prior;
        free(destination_node);
    }

}

void Joseph(int n, int m,int *res, CircularDoubleLinkedList* circularDoubleLinkedList)     // n 为人数， m 为间隔数
{
    if (n==1)
    {
        *res = circularDoubleLinkedList->data;
        free(circularDoubleLinkedList);
    }
    if ( n > 1)
    {
        int j = 1;
        while(1)
        {
            circularDoubleLinkedList = circularDoubleLinkedList->next;
            j++;
            if (j == 5)
            {
                CircularDoubleLinkedList *tmp = circularDoubleLinkedList->next;
                //printf("%d\t", circularDoubleLinkedList->data);
                CircularDoubleLinkedNode_Delete(res++,circularDoubleLinkedList,circularDoubleLinkedList);
                return Joseph(n-1, m, res, tmp);
            }
        }

    }
}

void find (int n, int m,int k, int * res, CircularDoubleLinkedList* circularDoubleLinkedList)
{
    Joseph(n, m, res, circularDoubleLinkedList);
    /* for (int i = 0; i < 10; i++)
     {
         printf("%d\t", res[i]);
     }*/

    for (int i = 0; i < n; i++)
    {
        if ( k == res[i])
        {
            printf("编号为%d的人是第%d个。",k, i+1);
            break;
        }
    }
}