#include <stdio.h>
#include <stdlib.h>
#include "../treenode/treenode.h"

void preorder(TreeNode* root){
    if(root){
        visit(root);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(TreeNode* root){
    if(root){
        inorder(root->left);
        visit(root); 
        inorder(root->right);
    }
}
void postorder(TreeNode* root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        visit(root);
    }
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

    printf("  Inorder traversal:");
    inorder(root);
    printf("\n");

    printf("Postorder traversal:");
    postorder(root);
    printf("\n");

    DeleteTree(root);
    return 0;
}

