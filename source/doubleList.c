#include "../include/doubleList.h"

doubleNode* Crt_doubleList_head()   // 前插法
{
    doubleNode* head = (doubleNode*) malloc(sizeof(doubleNode));
    head->next = NULL;
    head->prior = NULL;
    head->data = 0;
    doubleNode *last_doubleList = (doubleNode*)malloc(sizeof (doubleNode));    // 临时的最后的那个链表
    last_doubleList->next = NULL;
    last_doubleList->prior= NULL;
    last_doubleList->data = 0;
    doubleNode* address_last_doubleList = last_doubleList;
    head->next = last_doubleList;
    last_doubleList->prior = head;
    int temp = 0;   // 中间变量
    printf("请入数据(-1表示结束):\n");
    while(scanf("%d", &temp) && temp != FLAG)
    {
        doubleNode* temp_List = (doubleNode*) malloc(sizeof (doubleNode));
        temp_List->prior = NULL;
        temp_List->next = NULL;
        temp_List->data = temp;
        // 链接链表
        temp_List->next = head->next;
        (head->next)->prior = temp_List;
        head->next = temp_List;
        temp_List->prior = head;
    }
    // 清除最后的那个临时节点
    (address_last_doubleList->prior)->next = NULL;
    address_last_doubleList->prior = NULL;
    free(address_last_doubleList);

    printf("输入完成!\n");
    return head;
}

void Dis_doubleList(doubleNode* l)
{
    doubleNode* l1 = l->next;
    while (1)
    {
        printf("地址:%p, 值:%d\n",l1,l1->data);
        if (l1->next == NULL)
            return;
        else
            l1 = l1->next;
    }
}