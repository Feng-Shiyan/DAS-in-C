#ifndef DSA_IN_C_GRAPH_H
#define DSA_IN_C_GRAPH_H
#include "dataStructure.h"

// --------------------------------- 邻接矩阵定义 adjacency matrix ------------------------------------
typedef struct
{
    int num;        // 顶点编号
    int info;       // 顶点的类型
}VertexType;
typedef struct
{
    int edges[MAX_SIZE][MAX_SIZE];    // 邻接矩阵数组
    int n,e;            // 顶点数，边数
    //VertexType vertex_info[MAX_SIZE];      // 存放顶点信息
}matrix_adjacency;

// --------------------------------- 定义 邻接图 adjacency list ------------------------------------
typedef struct ANode
{
    int vex_adj;             // 该边的邻接节点编号
    struct ANode * next_arc; //指向下一条边的指针
    int weight;             // 权值
}ArcNode;

typedef struct Vnode
{
    int info;           // 顶点编号
    ArcNode * first_arc;  // 指向第一个边节点
}VNode;

typedef struct
{
    VNode adj_list[MAX_SIZE];        // 邻接表的头节点数组
    int n,e;         // 图中的顶点数 n 和边数 e
}AdjGraph;

// 创建图的算法
AdjGraph * CreateAdj(AdjGraph *G,int A[MAX_SIZE][MAX_SIZE],int n, int e);

// 输出图的运算
void DipAdj(AdjGraph * G);

// 销毁邻接表
void DestroyAdj(AdjGraph * G);

// 邻接矩阵 转成 邻接表
void MatToList(matrix_adjacency g, AdjGraph * G);

// 深度优先遍历 depth first search, DFS
void DFS(AdjGraph * G,int visited[], int v);
void DFS1(AdjGraph * G, int visited[]);

// 广度优先遍历 breadth first search, BFS
void BFS(AdjGraph * G, int v);

#endif //DSA_IN_C_GRAPH_H
