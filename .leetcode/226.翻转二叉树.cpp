/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 *
 * https://leetcode-cn.com/problems/invert-binary-tree/description/
 *
 * algorithms
 * Easy (72.85%)
 * Likes:    324
 * Dislikes: 0
 * Total Accepted:    42.4K
 * Total Submissions: 58.2K
 * Testcase Example:  '[4,2,7,1,3,6,9]'
 *
 * 翻转一棵二叉树。
 * 
 * 示例：
 * 
 * 输入：
 * 
 * ⁠    4
 * ⁠  /   \
 * ⁠ 2     7
 * ⁠/ \   / \
 * 1   3 6   9
 * 
 * 输出：
 * 
 * ⁠    4
 * ⁠  /   \
 * ⁠ 7     2
 * ⁠/ \   / \
 * 9   6 3   1
 * 
 * 备注:
 * 这个问题是受到 Max Howell 的 原问题 启发的 ：
 * 
 * 谷歌：我们90％的工程师使用您编写的软件(Homebrew)，但是您却无法在面试时在白板上写出翻转二叉树这道题，这太糟糕了。
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
    TreeNode* invertTree(TreeNode* root) { //迭代方法
        if(root == nullptr) return root;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* tmp = q.front(); q.pop();
            TreeNode* change = tmp->left; //注意三变量交换设置中间变量
            tmp->left = tmp->right;
            tmp->right = change;
            if(tmp->left != nullptr) q.push(tmp->left);
            if(tmp->right != nullptr) q.push(tmp->right);
        }
        return root;
    }
/*
    // 递归
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        TreeNode* tmp = root->left; //注意三变量交换设置中间变量
        root->left = invertTree(root->right);
        root->right = invertTree(tmp);
        return root;
    }
*/
};
// @lc code=end

