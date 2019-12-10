/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> record;
        queue<TreeNode*> q;
        vector<int> Oneline;
        int NowCount = 0;
        int NextCount = 0;
        int count = 0; 
        int N = 0;
        if(root != NULL){
            q.push(root);
            NowCount++;
        }
        while(!q.empty()){
            TreeNode *tmp = q.front();
            q.pop();
            count++;
            Oneline.push_back(tmp->val);
            if(tmp->left != NULL){
                q.push(tmp->left);
                NextCount++;
            }
            if(tmp->right != NULL){
                q.push(tmp->right);
                NextCount++;
            }
            if(count == NowCount){
                count = 0; 
                NowCount = NextCount;
                NextCount = 0;
                if(N++%2 != 0) reverse(Oneline.begin(),Oneline.end());
                record.push_back(Oneline);
                Oneline.clear();
            }
        }
        return record;
    }
};
// @lc code=end

