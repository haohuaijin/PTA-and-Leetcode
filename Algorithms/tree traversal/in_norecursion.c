#include <stdio.h>
#include <stdlib.h>
#include "../treenode/treenode.h"

void inorder(TreeNode* root){
    TreeNode **st = (TreeNode**)malloc(sizeof(TreeNode*)*20);
    int top = 0;
    TreeNode *cur = root;
    while(cur != NULL || top != 0){
        if(cur != NULL){
            st[top++] = cur;
            cur = cur->left;
        } else {
            cur = st[--top];
            visit(cur);
            cur = cur->right;
        }
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

    printf("  Inorder traversal:");
    inorder(root);
    printf("\n");

    DeleteTree(root);
    return 0;
}
 