/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxDepth(TreeNode* root) {
        int Left = 0,Right = 0;
        if(root == nullptr) return 0;
        Left = maxDepth(root->left) + 1;
        Right = maxDepth(root->right) + 1;
        return Left > Right ? Left : Right;
    }
};
// @lc code=end

