#include <stdio.h>
#include <stdlib.h>
#include "../treenode/treenode.h"

/*********************************************************************************
                           创建后续线索二叉树
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
void PostThread(TreeNode *root){
    if(root != NULL){
        PostThread(root->left);
        PostThread(root->right);
        thread_visit(root);
    }
}
void CreatePostThread(TreeNode *root){
    pre = NULL;
    if(root != NULL){
        PostThread(root);
        if(pre->right == NULL)
            pre->rtag = 1;
    }
}

/*********************************************************************************
                               后序线索二叉树查找后序前驱
**********************************************************************************/
// 查找后序前驱
TreeNode *prenode(TreeNode *root){
    if(root->ltag == 1){
        return root->left;
    } else {
        if(root->rtag == 0)
            return root->right;
        else 
            return root->left;
    }
}
// 使用后序线索二叉树实现逆序后序遍历
void reversePostorder(TreeNode *root){
    for(TreeNode *p = root; p != NULL; p = prenode(p))
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
    CreatePostThread(root);

    printf("Postorder traversal:");
    reversePostorder(root);
    printf("\n");

    DeleteTree(root);
    return 0;
}
