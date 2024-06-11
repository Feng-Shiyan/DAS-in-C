#ifndef DSA_IN_C_BINARY_TREE_H
#define DSA_IN_C_BINARY_TREE_H
#include "dataStructure.h"

// 定义二叉树结点结构
typedef struct node{
    int data;
    struct node *lChild;
    struct node *rChild;
}TreeNode,Binary_Tree;

// 创建新结点
TreeNode* Node_create(int data);

// 使用数组构构建完全二叉树
TreeNode * Tree_build(int arr[], int index, int n);

// 释放二叉树内存
void tree_free(TreeNode* root);

// 先序遍历 —— 递归
void pre_order_recursive(TreeNode* root);

// 递归中序遍历
void inorder_recursive(TreeNode* root);

// 非递归中序遍历
void inorder_no_recursive(TreeNode* root);

// 层次遍历
void order_level_1(TreeNode* root);
void order_level(TreeNode* root);

// 生成具有 n 个结点的随机二叉树
TreeNode* random_binary_tree(int n);

#endif //DSA_IN_C_BINARY_TREE_H
