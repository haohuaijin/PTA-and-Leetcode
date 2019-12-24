/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 *
 * https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (38.39%)
 * Likes:    263
 * Dislikes: 0
 * Total Accepted:    20K
 * Total Submissions: 52.2K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个非空二叉树，返回其最大路径和。
 * 
 * 本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   3
 * 
 * 输出: 6
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-10,9,20,null,null,15,7]
 * 
 * -10
 * / \
 * 9  20
 * /  \
 * 15   7
 * 
 * 输出: 42
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
    //理解好题目的意思:从任意的节点到任意节点，是用线穿起来的
    //思路：
    //1.把每一个节点看作最大路径和，计算根加左加右的值
    //2.每个结点返回的是：根以下最大路径(一条线)
    int maxPathSum(TreeNode* root) {
        int Max = -9999;
        Sum(root, Max);
        return Max;
    }
    int Sum(TreeNode *root,int &Max){
        int LeftMax=0,RightMax=0;
        int NowMax = root->val;
        int tmp = root->val;
        if(root->left != nullptr) LeftMax = Sum(root->left, Max);
        if(root->right != nullptr) RightMax = Sum(root->right, Max);

        if(LeftMax > 0) NowMax += LeftMax;
        if(RightMax > 0) NowMax += RightMax;

        if(NowMax > Max) Max = NowMax;

        int num = (LeftMax > RightMax ? LeftMax : RightMax);
        if(num > 0) tmp += num;

        return tmp;
    }
};
// @lc code=end

