#include "../include/singleList.h"

singleNode * Crt_singleList_head()              // 创建单链表(前插法)
{
    singleNode * head = (singleNode*) malloc(sizeof (singleNode));
    head->next = NULL;
    head->data = 0;
    int temp;
    printf("请输入数据(\"-1\"表示结束):\n");
    while (scanf("%d", &temp) && temp != FLAG)
    {
        singleNode* temp_list = (singleNode*) malloc(sizeof (singleNode));
        temp_list->next = NULL;
        temp_list->data = temp;
        temp_list->next = head->next;
        head->next = temp_list;
    }
    printf("输入完成\n");
    return head;
}

singleNode* Crt_singleList_tail()         // 创建双链表(后插法)
{
    singleNode* head = (singleNode*) malloc(sizeof (singleNode));
    head->data = 0;     //
    head->next = NULL;
    singleNode* address_last_singleList = head;      // 记录插入之前，头结点指向的下一个结点的地址
    int temp = 0;
    printf("请输入数据(\"-1\"表示结束):\n");
    while (scanf("%d",&temp) && temp != FLAG)
    {
        singleNode* t_list = (singleNode*) malloc(sizeof (singleNode));
        t_list->next = NULL;
        t_list->data = temp;
        address_last_singleList->next = t_list;
        address_last_singleList = t_list;            //
    }
    printf("输入完成!\n");
    return head;
}

void Dis_singleList(singleNode* l)        // 显示单链表
{
    singleNode* temp = l->next;
    while (1)
    {
        printf ("%x: %d\n",temp, temp->data);
        if (temp->next == NULL)
            return ;
        else
            temp = temp->next;
    }
}

void Inverted_singleList(singleNode* l)             // 逆置单链表
{
    singleNode* t_lList = (singleNode*) malloc(sizeof (singleNode));
    t_lList->data = l->data;
    t_lList = NULL;
    singleNode* temp = l;
    temp->data = (int)l->next;
    while (temp->next != NULL)
    {
        temp->next = t_lList->next;
        t_lList->next = temp;
        temp = (singleNode*)temp->data;
        temp->data = (int)temp->next;
    }
}

void Delete_duplicateNodes(singleNode* l)
{
    if (l == NULL) return; // 如果链表为空，直接返回
    singleNode* l1 = l->next;
    while(l1 != NULL)
    {
        singleNode* l2 = l1;
        while(l2->next != NULL){
            if (l2->next->data == l1->data){
               Delete_Node(l2);
               /*singleNode *tmp = l2->next;
               l2->next = tmp->next;
               free(tmp);*/
            }else {
                l2 = l2->next;
            }
        }
        l1 = l1->next;
    }
}

void Delete_Node(singleNode* node)
{
    singleNode *tmp = node->next;
    node->next = tmp->next;
    free(tmp);
}
