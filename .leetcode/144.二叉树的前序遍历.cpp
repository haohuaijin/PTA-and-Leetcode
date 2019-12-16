/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> visit;
        if(root == nullptr) return visit;
        else{
            pre(visit,root);
        }
        return visit;
    }
    void pre(vector<int> &visit,TreeNode *root){
        visit.push_back(root->val);
        if(root->left != nullptr) pre(visit,root->left);
        if(root->right != nullptr) pre(visit,root->right);
    }
};
// @lc code=end

