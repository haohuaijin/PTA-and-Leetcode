#include <stdio.h>
#include <stdlib.h>
#include "../treenode/treenode.h"

/*********************************************************************************
                           创建中序线索二叉树
**********************************************************************************/ 
TreeNode *pre = NULL;
void thread_visit(TreeNode *root){
    if(root->left == NULL){ //左孩子为空，建立前序线索
        root->left = pre;
        root->ltag = 1;
    }
    if(pre != NULL && pre->right == NULL) {
        pre->right = root;
        pre->rtag = 1;
    }
    pre = root;
}

void InThread(TreeNode *root){
    if(root != NULL){
        InThread(root->left);
        thread_visit(root);
        InThread(root->right);
    }
}

void CreateInThread(TreeNode *root){
    pre = NULL;
    if(root != NULL){
        InThread(root);
        if(pre->right == NULL)
            pre->rtag = 1;
    }
}

/*********************************************************************************
                           中序线索二叉树找中序后继
**********************************************************************************/ 
//找到以root为根的子树中，中序遍历第一个结点
TreeNode *firstnode(TreeNode *root){
    while(root->ltag == 0) 
        root = root->left;
    return root;
}
//中序线索二叉树中，找到root的后继结点
TreeNode *nextnode(TreeNode *root){
    if(root->rtag == 0)
        return firstnode(root->right);
    else 
        return root->right;
}
//使用线索二叉树实现中序遍历
void Inorder(TreeNode *root){
    for(TreeNode *p = firstnode(root); p != NULL; p = nextnode(p))
        visit(p);
}

/*********************************************************************************
                              中序二叉树查找中序前驱
**********************************************************************************/ 
// 中序遍历的最后一个结点
TreeNode *lastnode(TreeNode *root){
    while(root->rtag == 0)
        root = root->right;
    return root;
}
// 中序遍历的root结点的前一个结点
TreeNode *prenode(TreeNode *root){
    if(root->ltag == 0)
        return lastnode(root->left);
    else 
        return root->left;
}
// 利用中序线索二叉树，进行逆序中序遍历
void reverseInorder(TreeNode *root){
    for(TreeNode *p = lastnode(root); p != NULL; p = prenode(p))
        visit(p);
}

/*********************************************************************************
                                Main Function
**********************************************************************************/ 
int main(){
    /*
         1
       /   \
      2     3
       \   / \
        4 5   6
    */
    TreeNode* root =  CreateNode(1);
    root->left = CreateNode(2);
    root->right = CreateNode(3);
    root->left->right = CreateNode(4);
    root->right->left = CreateNode(5);
    root->right->right = CreateNode(6);
    CreateInThread(root);

    printf("Inorder traversal:");
    reverseInorder(root);
    printf("\n");

    DeleteTree(root);
    return 0;
}

