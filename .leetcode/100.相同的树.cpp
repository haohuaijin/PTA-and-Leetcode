/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if((p == NULL && q != NULL) || (p != NULL && q == NULL)) return false;
        if(q == NULL && q == NULL) return true;
        if(q->val != p->val) return false;
        else {
            bool tmp1 = isSameTree(p->left,q->left);
            bool tmp2 = isSameTree(p->right,q->right);
            if(!tmp1 || !tmp2) return false;
        }
        return true;
    }
};
// @lc code=end

