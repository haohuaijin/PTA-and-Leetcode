// link: https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/
#include <stdio.h>
#include <stdlib.h>
#include "treenode/treenode.h"

void morris(TreeNode *root){
	TreeNode *current, *pre;

	if (root == NULL)
		return;

	current = root;
	while (current != NULL) {
		if (current->left == NULL) {
			printf("%4d", current->val);
			current = current->right;
		}
		else {
			/* Find the inorder predecessor of current */
			pre = current->left;
			while (pre->right != NULL && pre->right != current)
				pre = pre->right;
			/* Make current as the right child of its
			inorder predecessor */
			if (pre->right == NULL) {
				pre->right = current;
				current = current->left;
			}
			/* Revert the changes made in the 'if' part to
			restore the original tree i.e., fix the right
			child of predecessor */
			else {
				pre->right = NULL;
				printf("%4d", current->val);
				current = current->right;
			} 
		} 
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

    printf("Postorder traversal:");
    morris(root);
    printf("\n");

    DeleteTree(root);
    return 0;
}