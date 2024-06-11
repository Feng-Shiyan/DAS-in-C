#include "../include/hash.h"

// 将关键字 k 插入哈希表中
void HT_Insert(HashTable ha, int p, KeyType k[])
{
    int i,adr;
    int k1 = string_to_int(k);
    adr = k1 % p;        // 计算哈希函数值
    //if ( ha.key[adr] == NULLKEY)
    if ( strcmp_S( ha.key[adr], "" ))
    {
        strcpy_S( ha.key[adr], k);  // 将字符串 k 赋值到 ha.key.[adr]
        ha.count[adr] = 1;
    }else{
        int cnt = 1;        // cnt 记录发生冲突的次数
        do{
            adr = (adr + 1) % ha.m;
            cnt++;
        } while (ha.key[adr] != NULLKEY);
        ha.key[adr] = k;
        ha.count[adr] = cnt;
    }
    ha.n++;
}

// 有关键字序列 keys[0..total-1] 创建哈希表
void HT_Create(HashTable ha, int p, KeyType keys[][MAX_SIZE], int total)
{
    ha.key = (KeyType**) malloc(MAX_SIZE * sizeof (int ));
    ha.n = 0;
    if ( ha.key == NULL)  perror("HashTable 初始化失败");

    for (int i = 0; i < total; i++)
    {
        HT_Insert(ha, p, keys[i]);       // 插入 n 个关键字
    }
}

// 删除哈希表中的关键字 k
bool HT_Delete(HashTable ha[], int p, KeyType k)
{
//    int adr;
//    adr = k % p;
//    while (ha[adr].key != NULLKEY && ha[adr].key != k)
//        adr = (adr + 1) % ha->m;            // 线性探测
//    if (ha[adr].key == k)       // 查找成功
//    {
//        int j = (adr + 1) % ha->m;  // j 为 adr 的循环后继位置
//        while (ha[j].key != NULLKEY && ha[j].key == k % p);  // 查找 adr 后面的同义词
//        {
//            ha[(j-1+ha->m) % ha->m].key = ha[j].key;      // 将同义词向前移动
//            j = (j+1) % ha->m;
//        }
//        ha[(j-1+ ha->m) % ha->m].key = NULLKEY;         // 删除最后一个同义词
//        ha[(j-1 + ha->m) % ha-> m].count = 0;
//        ha->n--;                // 哈希表中元素个数减一
//        return true;            // 查找成功
//    }else
//        return  false;          // 查找失败
}