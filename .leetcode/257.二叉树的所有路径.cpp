/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode-cn.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (61.10%)
 * Likes:    176
 * Dislikes: 0
 * Total Accepted:    20.3K
 * Total Submissions: 33.1K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 给定一个二叉树，返回所有从根节点到叶子节点的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 输入:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * 输出: ["1->2->5", "1->3"]
 * 
 * 解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
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
    vector<string> binaryTreePaths(TreeNode* root) { //递归
        
    }
/*
    vector<string> binaryTreePaths(TreeNode* root) { //递归
        vector<string> re,leftPath,rightPath;
        string path;
        if(root == nullptr) return re;
        path = to_string(root->val);
        //边界检测
        if(root->left == nullptr && root->right == nullptr){
            re.push_back(path);
            return re;
        }
        //不是叶节点
        if(root->left != nullptr) leftPath = binaryTreePaths(root->left);
        if(root->right != nullptr) rightPath = binaryTreePaths(root->right);
        for(auto le : leftPath){
            string tmp = path + "->" + le;
            re.push_back(tmp);
        }
        for(auto ri : rightPath){
            string tmp = path + "->" + ri;
            re.(tmp);
        }
        return re;
    }
    */
};  
// @lc code=end

