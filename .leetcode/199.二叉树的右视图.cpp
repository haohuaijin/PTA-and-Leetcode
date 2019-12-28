/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 *
 * https://leetcode-cn.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (62.22%)
 * Likes:    118
 * Dislikes: 0
 * Total Accepted:    14.2K
 * Total Submissions: 22.9K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * 给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
 * 
 * 示例:
 * 
 * 输入: [1,2,3,null,5,null,4]
 * 输出: [1, 3, 4]
 * 解释:
 * 
 * ⁠  1            <---
 * ⁠/   \
 * 2     3         <---
 * ⁠\     \
 * ⁠ 5     4       <---
 * 
 * 
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
/*
    //BFS
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) return res;
        queue<TreeNode*> q;
        TreeNode *last = root;
        q.push(root);
        while(!q.empty()){
            TreeNode *tmp = q.front(); q.pop();

            if(tmp->left != nullptr) q.push(tmp->left);
            if(tmp->right != nullptr) q.push(tmp->right);

            if(tmp == last){
                last = q.back();
                res.push_back(tmp->val);
            }
        }
        return res;
    }*/
    //DFS
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        DFS(root, 0, res);
        return res;
    }
    void DFS(TreeNode *root,int level,vector<int> &res){
        if(root == nullptr) return;

        if(level == res.size()) res.push_back(root->val);

        DFS(root->right, level + 1, res);
        DFS(root->left, level + 1, res);
    }
};
// @lc code=end

