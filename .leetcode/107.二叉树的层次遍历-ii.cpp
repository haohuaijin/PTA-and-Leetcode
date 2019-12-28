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
    //DFS，深度优先搜索
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        DFSOrder(root, 0, res);
        reverse(res.begin(), res.end());
        return res;
    }
    void DFSOrder(TreeNode *root,int level,vector<vector<int>> &res){
        if(root == nullptr) return;
        //找好level和res.size()的对应关系
        if(level >= (int)res.size()) res.push_back({});

        res[level].push_back(root->val);

        DFSOrder(root->left, level + 1, res);
        DFSOrder(root->right, level + 1, res);
    }

/*
    //BFS，广度优先搜索
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
    }*/
};
// @lc code=end

