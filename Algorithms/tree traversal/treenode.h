#ifndef TREENODE_H
#define TREENODE_H

typedef struct TreeNode{
    int val;
    int flag;
    struct TreeNode *left, *right;
}TreeNode;

TreeNode *CreateNode(int val){
    TreeNode* ret = (TreeNode*)malloc((sizeof(TreeNode)));
    ret->val = val;
    return ret;
}
void DeleteTree(TreeNode* root){
    if(root){
        DeleteTree(root->left);
        DeleteTree(root->right);
        free(root);
    }
}

void visit(TreeNode *root){
    printf("%4d", root->val);
}

#endif