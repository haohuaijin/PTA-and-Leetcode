#include <stdio.h>
#include <stdlib.h>
#include "treenode/treenode.h"

TreeNode *rotateLeft(TreeNode *root) {
    TreeNode *t = root->right;
    root->right = t->left;
    t->left = root;
    return t;
}
TreeNode *rotateRight(TreeNode *root) {
    TreeNode *t = root->left;
    root->left = t->right;
    t->right = root;
    return t;
}
TreeNode *rotateLeftRight(TreeNode *root) {
    root->left = rotateLeft(root->left);
    return rotateRight(root);
}
TreeNode *rotateRightLeft(TreeNode *root) {
    root->right = rotateRight(root->right);
    return rotateLeft(root);
}

TreeNode *insert(TreeNode *root, int val) {
    if(root == NULL) {
        root = CreateNode(val);
        root->left = root->right = NULL;
    } else if(val < root->val) {
        root->left = insert(root->left, val);
        if(getHeight(root->left) - getHeight(root->right) == 2)
            root = val < root->left->val ? rotateRight(root) : rotateLeftRight(root);
    } else {
        root->right = insert(root->right, val);
        if(getHeight(root->left) - getHeight(root->right) == -2)
            root = val > root->right->val ? rotateLeft(root) : rotateRightLeft(root);
    }
    return root;
}
void printfTree(TreeNode* root, int level){
    if(root != NULL){
        for(int i=0; i < level; ++i)
            printf("-");
        printf("%d\n", root->val);
        printfTree(root->left, level+1);
        printfTree(root->right, level+1);
    }
}
int main() {
    TreeNode* root = NULL;
    root = insert(root,120);
    root = insert(root,90);
    root = insert(root,65);
    root = insert(root,88);
    root = insert(root,70);
    root = insert(root,61);
    root = insert(root,96);

    printf("Preorder traversal: ");
    preorder_traversal(root); //前序遍历
    printf("\n");

    printfTree(root, 0);

    DeleteTree(root);
    return 0;
}