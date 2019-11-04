/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isValidBST(struct TreeNode* root){
    bool Left = true,Right = true;
    if(!root) return true;
    if(root->left){
        if(root->left->val < root->val){
            Left = isValidBST(root->left);
        }
        else Left = false;
    }
    if(root->right){
        if(root->right->val > root->val){
            Right = isValidBST(root->right);
        }
        else Right = false;
    }
    if(Left && Right) return true;
    else return false;
}