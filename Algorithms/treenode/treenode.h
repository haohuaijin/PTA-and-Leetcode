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