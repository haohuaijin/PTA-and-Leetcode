#include <stdio.h>
#include <stdlib.h>
#include "../treenode/treenode.h"

void preorder(TreeNode* root){
    TreeNode **st = (TreeNode**)malloc(sizeof(TreeNode*)*20); //存放TreeNode指针的数组
    int top = 0;
    st[top++] = root;
    while(top != 0){
        TreeNode* cur = st[--top];
        visit(cur); 
        if(cur->right) st[top++] = cur->right; //注意顺序
        if(cur->left) st[top++] = cur->left;
    }
    free(st);
}

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

    printf(" Preorder traversal:");
    preorder(root);
    printf("\n");

    DeleteTree(root);
    return 0;
}

