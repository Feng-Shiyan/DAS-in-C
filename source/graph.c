#include "../include/graph.h"

// 创建图的算法
AdjGraph * CreateAdj(AdjGraph *G,int A[MAX_SIZE][MAX_SIZE],int n, int e)
{
    int i,j;
    ArcNode * p;
    G = (AdjGraph * ) malloc(sizeof (AdjGraph));
    for ( i = 0; i < n; i++ )
        G->adj_list[i].first_arc = NULL;        // 将所有的头节点指针置空
    for ( i = 0; i < n; i++ )
    {
        for ( j = n-1; j >= 0; j--)
        {
            if ( A[i][j] != 0 && A[i][j] != INF )       // 存在一条边 <i,j>
            {
                p = (ArcNode * ) malloc(sizeof (ArcNode));
                p->vex_adj = j;
                p->weight = A[i][j];
                p->next_arc = G->adj_list[i].first_arc;
                G->adj_list[i].first_arc = p;
            }
        }
    }
    G->n = n;
    G->e = e;
    return G;
}

// 输出邻接表 G
void DipAdj(AdjGraph * G)
{
    int i;
    ArcNode * p;
    for ( i = 0; i < G->n; i++ )
    {
        p = G->adj_list[i].first_arc;
        printf("%3d: ", i);
        while ( p != NULL )
        {
            printf( "%3d[%d]->", p->vex_adj, p->weight);
            p = p->next_arc;
        }
        printf("∧ \n");
    }
}

// 邻接矩阵 转成 邻接表
void MatToList(matrix_adjacency g, AdjGraph * G)
{
    int i,j;
    ArcNode * p;
    G = (AdjGraph *) malloc(sizeof (AdjGraph));
    for ( i = 0; i < g.n; i++ )     // 所有头节点置空
        G->adj_list[i].first_arc = NULL;

    for (i = 0; i < g.n; i++ )              // 检查邻接矩阵中的每个元素
    {
        for ( j = g.n - 1; j >= 0; j-- )
        {
            if ( g.edges[i][j] != 0 &&  g.edges[i][j] != INF )    // 存在这条边 <i,j>
            {
                p = (ArcNode * ) malloc(sizeof (ArcNode));      // 创建一个边节点
                p->vex_adj = j;
                p->weight = g.edges[i][j];
                p->next_arc = G->adj_list[i].first_arc;     // 头插入法插入节点 p
                G->adj_list[i].first_arc = p;
            }
        }
    }
    G->n = g.n;
    G->e = g.e;
}

// 销毁邻接表
void DestroyAdj(AdjGraph * G)
{
    int i;
    ArcNode * pre, * p;
    for ( i = 0; i < G->n; i++ )                // 遍历所有的单链表
    {
        pre = G->adj_list[i].first_arc;
        if ( pre != NULL )
        {
            p = pre->next_arc;
            while ( p != NULL )
            {
                free(pre);
                pre = p;
                p = p->next_arc;
            }
            free(pre);
        }
    }
    free(G);
}

// 深度优先遍历 depth first search, DFS
void DFS(AdjGraph * G, int visited [], int v)
{
    ArcNode * p;
    visited[v] = 1;     // 标记已访问
    printf("%d", v);
    p = G->adj_list[v].first_arc;
    while ( p != NULL )
    {
        if ( visited[p->vex_adj] == 0 )     // 若 p->vex_adj 顶点未访问，递归访问该节点
            DFS (G, visited, p->vex_adj);
        p = p->next_arc;                    // p 节点指向顶点 v 的下一个节点
    }
}

void DFS1(AdjGraph * G, int visited[])
{
    int i;
    for (i = 0; i < G->n; i++)
        if (visited[i] == 0 )
            DFS(G,visited,i);
}

// 广度优先遍历 breadth first search, BFS
void BFS(AdjGraph * G, int v)
{

}
