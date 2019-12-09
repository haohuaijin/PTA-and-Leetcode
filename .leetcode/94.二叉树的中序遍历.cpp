/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> q;
        vector<int> record;
        if(root == NULL) return record;
        else{
            q.push(root);
            while(root->left != NULL){
                q.push(root->left);
                root = root->left;
            }
            while(!q.empty()){
                TreeNode *tmp = q.top();
                q.pop();
                record.push_back(tmp->val);
                if(tmp->right){
                    q.push(tmp->right);
                    tmp = tmp->right;
                    while(tmp->left){
                        q.push(tmp->left);
                        tmp = tmp->left;
                    }
                }
            }
        }
        return record;
    }
};
// @lc code=end

