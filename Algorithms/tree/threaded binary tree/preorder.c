#include <stdio.h>
#include <stdlib.h>
#include "../treenode/treenode.h"

/*********************************************************************************
                           创建先序线索二叉树
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
void PreThread(TreeNode *root){
    if(root != NULL){
        thread_visit(root);
        if(root->ltag == 0) //防止出现回路
            PreThread(root->left);
        PreThread(root->right);
    }
}
void CreatePreThread(TreeNode *root){
    pre = NULL;
    if(root != NULL){
        PreThread(root);
        if(pre->right == NULL)
            pre->rtag = 1;
    }
}

/*********************************************************************************
                               先序线索二叉树查找先序后继
**********************************************************************************/
// 查找先序后继
TreeNode *nextnode(TreeNode *root){
    if(root->rtag == 1){
        return root->right;
    } else {
        if(root->ltag == 0)
            return root->left;
        else 
            return root->right;
    }
}
void Preorder(TreeNode *root){
    for(TreeNode *p = root; p != NULL; p = nextnode(p))
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
    CreatePreThread(root);

    printf("Preorder traversal:");
    Preorder(root);
    printf("\n");

    DeleteTree(root);
    return 0;
}
