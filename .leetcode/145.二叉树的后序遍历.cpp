/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (69.03%)
 * Likes:    195
 * Dislikes: 0
 * Total Accepted:    41.5K
 * Total Submissions: 60.1K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 后序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]  
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3 
 * 
 * 输出: [3,2,1]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> Stack;
        vector<int> visit;
        if(root == nullptr) return visit;
        while(root != nullptr){
            Stack.push(root);
            visit.push_back(root->val);
            root = root->right;
        }
        while(!Stack.empty()){ //leetcode官方 前-右-左 然后逆序👍 思路清奇
            TreeNode *tmp = Stack.top();
            Stack.pop();
            if(tmp->left != nullptr){
                Stack.push(tmp->left);
                tmp = tmp->left;
                visit.push_back(tmp->val);
                while(tmp->right != nullptr){
                    Stack.push(tmp->right);
                    tmp = tmp->right;
                    visit.push_back(tmp->val);
                }
            }
        }
        reverse(visit.begin(),visit.end());
        return visit;
    } 
    /*
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> visit;
        if(root == nullptr) return visit;
        else{
            poster(visit,root);
        }
        return visit;
    } 
    void poster(vector<int> &visit,TreeNode *root){
        if(root->left != nullptr) poster(visit,root->left);
        if(root->right != nullptr) poster(visit,root->right);
        visit.push_back(root->val);
    } */
};
// @lc code=end

