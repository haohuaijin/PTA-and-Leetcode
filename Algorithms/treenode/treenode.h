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
    ret->left = NULL;
    ret->right = NULL;
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

int getHeight(TreeNode *root) {
    if(root == NULL) return 0;
	int left = getHeight(root->left);
	int right = getHeight(root->right);
    return (left > right ? left : right) + 1;
}

void visit(TreeNode *root){
    printf("%4d", root->val);
}

void preorder_traversal(TreeNode* root){
    if(root){
        visit(root);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}
void inorder_traversal(TreeNode* root){
    if(root){
        inorder_traversal(root->left);
        visit(root); 
        inorder_traversal(root->right);
    }
}
void postorder_traversal(TreeNode* root){
    if(root){
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        visit(root);
    }
}
#endif