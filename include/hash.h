#ifndef DSA_IN_C_HASH_H
#define DSA_IN_C_HASH_H
#include "dataStructure.h"

typedef struct
{
    KeyType **key;        // 关键字域
    int count[MAX_SIZE];          // 探测次数域
    int n;              // 哈希表元素个数
    int m;              // 哈希表空间大小
}HashTable;
// 将关键字 k 插入哈希表中
void HT_Insert(HashTable ha,int p, KeyType k[]);

// 有关键字序列 keys[0..total-1] 创建哈希表
void HT_Create(HashTable ha, int p, KeyType keys[][MAX_SIZE], int total);

// 删除哈希表中的关键字 k
bool HT_Delete(HashTable ha[],int p, KeyType k);

#endif //DSA_IN_C_HASH_H
