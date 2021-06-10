#ifndef TREENODE_H
#define TREENODE_H

typedef struct TreeNode{
    int val;
    int flag; // use in post order traversal
    struct TreeNode *left, *right;
    int ltag, rtag; // use in threaded bianry tree
}TreeNode;

TreeNode *CreateNode(int val){
    TreeNode* ret = (TreeNode*)malloc((sizeof(TreeNode)));
    ret->val = val;
    ret->ltag = 0;
    ret->rtag = 0; 
    return ret;
}
void DeleteTree(TreeNode* root){
    if(root){
        if(root->ltag == 0) DeleteTree(root->left);
        if(root->rtag == 0) DeleteTree(root->right);
        free(root);
    }
}

void visit(TreeNode *root){
    printf("%4d", root->val);
}

#endif