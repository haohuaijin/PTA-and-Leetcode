// Construct Binary Tree from Inorder and Postorder Traversal
#include <stdio.h>
#include <stdlib.h>
#include "../treenode/treenode.h"

TreeNode* helper(int *inorder, int *postorder, int l1, int r1, int l2, int r2){
    if(l1 > r1) return NULL;
    int i;
    // find the root in inorder
    for(i=l1; i<=r1; ++i)
        if(inorder[i] == postorder[r2])
            break;
    TreeNode *t = CreateNode(postorder[r2]);
    // construct the left subtree
    t->left = helper(inorder, postorder, l1, i-1, l2, l2+i-l1-1);
    // construct the right subtree
    t->right = helper(inorder, postorder, i+1, r1, l2+i-l1, r2-1);
    return t;
}
TreeNode* buildTree(int* inorder, int* postorder, int len) {
    return helper(inorder, postorder, 0, len-1, 0, len-1);
}
void preorder(TreeNode* root){
    if(root){
        visit(root);
        preorder(root->left);
        preorder(root->right);
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
    int inorder[6] = {2,4,1,5,3,6};
    int postorder[6] = {4,2,5,6,3,1};
    TreeNode *root = buildTree(inorder, postorder, 6);

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    DeleteTree(root);
    return 0;
}

