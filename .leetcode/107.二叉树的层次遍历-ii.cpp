/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> record;
        vector<int> OneLine;
        TreeNode *last;
        queue<TreeNode*> q;
        if(root != NULL){
            q.push(root);
            last = root;
        }
        //思想：队列里面最多有两层，用last记录每一层最后入队的元素
        while(!q.empty()){
            TreeNode *tmp = q.front();
            q.pop();
            OneLine.push_back(tmp->val);
            if(tmp->left != NULL) q.push(tmp->left);
            if(tmp->right != NULL) q.push(tmp->right);
            if(tmp == last){
                record.push_back(OneLine);
                OneLine.clear();
                last = q.back();
            }
        }
        reverse(record.begin(),record.end());
        return record;
    }
};
// @lc code=end

