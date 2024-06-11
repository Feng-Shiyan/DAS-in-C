#include "../include/binary_tree.h"

// 创建新结点
//TreeNode* Node_create(int data){
//    TreeNode *newNode = (TreeNode*) malloc(sizeof (TreeNode));
//    newNode->data = data;
//    newNode->lChild = NULL;
//    newNode->rChild = NULL;
//    return newNode;
//}
TreeNode* Node_create(int data) {
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (!newNode) {
        fprintf(stderr, "Out of memory!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->lChild = newNode->rChild = NULL;
    return newNode;
}

// 使用数组构构建完全二叉树
TreeNode* Tree_build(int arr[], int index, int n) {
    if (index < n) {
        TreeNode *temp = Node_create(arr[index]);
        temp->lChild = Tree_build(arr, 2 * index + 1, n);
        temp->rChild = Tree_build(arr, 2 * index + 2, n);
        return temp;
    }
    return NULL;
}

// 释放二叉树内存
void tree_free(TreeNode* root)
{
    if( NULL == root)
    {
        free(root);
        return;
    }
    tree_free(root->rChild);
    tree_free(root->lChild);
    free(root);
}

// 先序遍历 —— 递归
void pre_order_recursive(TreeNode* root)
{
    if ( NULL == root) return;
    printf("%d ", root->data);
    pre_order_recursive(root->lChild);
    pre_order_recursive(root->rChild);
}

// 递归中序遍历
void inorder_recursive(TreeNode* root)
{
    if( NULL == root) return;
    inorder_recursive(root->lChild);
    printf("%d \t",root->data);
    inorder_recursive(root->rChild);
}

// 非递归中序遍历
void inorder_no_recursive(TreeNode* root)
{
    TreeNode * nodes[MAX_SIZE];  // 最大存储结点为 100 个
    int top = -1;      // 初始化栈顶指针

    while( 1 )
    {
        while ( root )      // 压入所有左子树结点
        {
           nodes[++top] = root;
           root = root->lChild;
        }
        // 栈空时 遍历完成
        if ( -1 == top ) break;

        // 访问左子树结点
        root = nodes[ top--];
        printf("%d \t", root->data);

        // 访问右子树
        root = root->rChild;
    }
}

// 层次遍历
void order_level_1(TreeNode* root)
{
    if ( NULL == root ) return;

    TreeNode * nodes[MAX_SIZE];     // 存放二叉树结点
    int top = -1;

    int i = 0, j = 0, count = 0;
    // i 表示当前遍历二叉树的层数， j 表示当前遍历的元素在数组中的序号

    while ( 1 )
    {
        if ( 0 == j )
        {
            nodes[++top] = root;
            printf("%d \t", nodes[top]->data);
            j++;
            i++;
        }
        while ( j <= (int)pow(2,i) - 1)      // 小于二叉树每一层的最大结点数
        {
            j++;
            if ((int)pow(2,i) <= j && j <= (int)(pow(2,i) + pow(2,i-1) - 1)){
                // 压入左子树结点并输出
                if (  nodes[ j/2 - 1]->lChild == NULL || nodes[ j/2 - 1] == NULL ){
                    nodes[++top] = NULL;
                    printf("* \t");
                    count++;
                }else{
                    nodes[++top] = (nodes[ j/2 - 1]->lChild);
                    printf("%d \t", nodes[top]->data);
                }
            }
            if ((int)(pow(2,i) + pow(2,i-1)) <= j && j <= (int)pow(2,i+1) - 1){
                // 压入右子树结点并输出
                if (  nodes[ j/2 - 1]->rChild == NULL || nodes[ j/2 - 1] == NULL  ){
                    nodes[++top] = NULL;
                    printf("* \t");
                    count++;
                }else{
                    nodes[++top] = (nodes[ j/2 - 1]->rChild);
                    printf("%d \t", nodes[top]->data);
                }
            }

           if (count == (int)pow(2,i) ){        // 退出遍历
               goto label1;
           }else if( (int)(j - pow(2,i-1))  < (int)pow(2,i) ){
                // 当前层数未完全遍历，继续遍历
           }else if ( (int)(j - pow(2,i-1)) == (int)pow(2,i)){         // 继续遍历
                   count = 0;
                   i++;
               }
        }
        label1: break;
    }
}

void order_level(TreeNode* root) {
    if (root == NULL) return;

    TreeNode *queue[1000];  // 可以使用动态结构以适应更大的树
    int front = 0, rear = 0;

    // 入队根节点
    queue[rear++] = root;

    while (front < rear) {
        TreeNode *node = queue[front++];

        // 处理当前节点
        printf("%d \t", node->data);

        // 入队子节点
        if (node->lChild != NULL) {
            queue[rear++] = node->lChild;
        }
        if (node->rChild != NULL) {
            queue[rear++] = node->rChild;
        }
    }
}


// 生成具有 n 个结点的随机二叉树
TreeNode* random_binary_tree(int n)
{
    if ( 0 == n )return NULL;

    // 创建当前结点  —— 结点随机值设为 0-99
    TreeNode *root = Node_create( rand() % 100 );
    int remainingNodes = n - 1;     // 剩余节点数

    if ( 1 == n)
    {
        root->rChild = NULL;
        root->lChild = NULL;
    }

    // 随机分配左右子树的结点数目
    int leftNodes = rand() % (remainingNodes + 1);
    int rightNodes = remainingNodes - leftNodes;

    // 递归创建左右子树
    root->lChild = random_binary_tree(leftNodes);
    root->rChild = random_binary_tree(rightNodes);

    return root;
}