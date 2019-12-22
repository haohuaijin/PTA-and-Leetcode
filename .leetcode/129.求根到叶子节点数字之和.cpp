/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根到叶子节点数字之和
 *
 * https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/description/
 *
 * algorithms
 * Medium (60.18%)
 * Likes:    96
 * Dislikes: 0
 * Total Accepted:    14.4K
 * Total Submissions: 24K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。
 * 
 * 例如，从根到叶子节点路径 1->2->3 代表数字 123。
 * 
 * 计算从根到叶子节点生成的所有数字之和。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * 输出: 25
 * 解释:
 * 从根到叶子节点路径 1->2 代表数字 12.
 * 从根到叶子节点路径 1->3 代表数字 13.
 * 因此，数字总和 = 12 + 13 = 25.
 * 
 * 示例 2:
 * 
 * 输入: [4,9,0,5,1]
 * ⁠   4
 * ⁠  / \
 * ⁠ 9   0
 * / \
 * 5   1
 * 输出: 1026
 * 解释:
 * 从根到叶子节点路径 4->9->5 代表数字 495.
 * 从根到叶子节点路径 4->9->1 代表数字 491.
 * 从根到叶子节点路径 4->0 代表数字 40.
 * 因此，数字总和 = 495 + 491 + 40 = 1026.
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
    //迭代版本
    int sumNumbers(TreeNode* root) {
        if(root == nullptr) return 0;
        int re = 0;
        stack<TreeNode*> node; stack<int> path;
        node.push(root); path.push(root->val);
        while(!node.empty()){
            TreeNode *tmp = node.top(); node.pop();
            int num = path.top(); path.pop();

            if(tmp->left == nullptr && tmp->right == nullptr)
                re += num;

            if(tmp->left != nullptr){
                int now = num * 10 + tmp->left->val;
                node.push(tmp->left);
                path.push(now);
            }
            if(tmp->right != nullptr){
                int now = num * 10 + tmp->right->val;
                node.push(tmp->right);
                path.push(now);
            }
        }
        return re;
    }
    /*
    //递归 改良版
    int sumNumbers(TreeNode* root) {
        int re = 0;
        if(root == nullptr) return 0;
        solve(root, re, 0);
        return re;
    }
    void solve(TreeNode *root, int &re, int num){
        int tmp = num * 10 + root->val;
        if(root->left == nullptr && root->right == nullptr) 
            re += tmp;
        if(root->left != nullptr)solve(root->left, re, tmp);
        if(root->right != nullptr) solve(root->right, re, tmp);
    }
/*递归
    int sumNumbers(TreeNode* root) {
        vector<int> re;
        if(root == nullptr) return 0;
        solve(root, re, 0);
        int sum = 0;
        for(auto num : re) sum += num;
        return sum;
    }
    void solve(TreeNode *root, vector<int> &re, int num){
        int tmp = num * 10 + root->val;

        if(root->left == nullptr && root->right == nullptr)
            re.push_back(tmp);

        if(root->left != nullptr)solve(root->left, re, tmp);
        if(root->right != nullptr) solve(root->right, re, tmp);
    }
    */
};
// @lc code=end

