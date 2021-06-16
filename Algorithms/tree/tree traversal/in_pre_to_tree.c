// Construct Binary Tree from Inorder and Preorder Traversal
#include <stdio.h>
#include <stdlib.h>
#include "../treenode/treenode.h"

// inorder[l1,r1], preorder[l2, r2]
TreeNode* helper(int *inorder, int *preorder, int l1, int r1, int l2, int r2){
    if(l1 > r1) return NULL;
    int index;
    // find the root in inorder
    /**********************************************************
     we can use hash map to fastly to find the index in inorder
     **********************************************************/
    for(index=l1; index<=r1; ++index)
        if(inorder[index] == preorder[l2])
            break;
    TreeNode *t = CreateNode(preorder[l2]);
    // construct the left subtree
	// notice the indexin preorder
    t->left = helper(inorder, preorder, l1, index-1, l2+1, l2+index-l1);
    // construct the right subtree 
	// notice the index in preorder
    t->right = helper(inorder, preorder, index+1, r1, l2+index-l1+1, r2); 
    return t;
}
TreeNode* buildTree(int* inorder, int* preorder, int len) {
    return helper(inorder, preorder, 0, len-1, 0, len-1);
}

int main(){
    /*************************
         1
       /   \
      2     3
       \   / \
        4 5   6
    **************************/
    int inorder[6] = {2,4,1,5,3,6};
    int preorder[6] = {1,2,4,3,5,6};
    TreeNode *root = buildTree(inorder, preorder, 6);

    printf("Preorder traversal: ");
    preorder_traversal(root);
    printf("\n");

    DeleteTree(root);
    return 0;
}