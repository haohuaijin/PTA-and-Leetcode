/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 *
 * https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (40.71%)
 * Likes:    185
 * Dislikes: 0
 * Total Accepted:    42.2K
 * Total Submissions: 103.4K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最小深度。
 * 
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回它的最小深度  2.
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
    //迭代,stack
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int re = 99999;
        stack<TreeNode*> node; stack<int> depth;
        node.push(root); depth.push(1);
        while(!node.empty()){
            TreeNode *tmp = node.top(); node.pop();
            int de = depth.top(); depth.pop();

            if(tmp->left == nullptr && tmp->right == nullptr)
                re = min(re, de);

            if(tmp->left != nullptr){
                node.push(tmp->left);
                depth.push(de + 1);
            }
            if(tmp->right != nullptr){
                node.push(tmp->right);
                depth.push(de + 1);
            }
        }
        return re;
    }
/*
    // 递归，DFS
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int re = 99999;
        solve(root, re, 1);
        return re;
    }
    void solve(TreeNode *root, int &re, int depth){
        if(root->left == nullptr && root->right == nullptr)
            re = min(re, depth);

        if(root->left != nullptr) solve(root->left, re, depth+1);
        if(root->right != nullptr) solve(root->right, re, depth+1);
    }
    */
};
// @lc code=end

