/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 *
 * https://leetcode-cn.com/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (49.31%)
 * Likes:    188
 * Dislikes: 0
 * Total Accepted:    41.3K
 * Total Submissions: 83.6K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，判断它是否是高度平衡的二叉树。
 * 
 * 本题中，一棵高度平衡二叉树定义为：
 * 
 * 
 * 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
 * 
 * 
 * 示例 1:
 * 
 * 给定二叉树 [3,9,20,null,null,15,7]
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回 true 。
 * 
 * 示例 2:
 * 
 * 给定二叉树 [1,2,2,3,3,null,null,4,4]
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   2
 * ⁠   / \
 * ⁠  3   3
 * ⁠ / \
 * ⁠4   4
 * 
 * 
 * 返回 false 。
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
    //自底向上,只调用一次求深度的MaxDepth(),更优
    //只要有不平衡的，就一路返回，节省时间
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        bool re = true;
        MaxDepth(root, re);
        return re;
    }
    int MaxDepth(TreeNode *root,bool &re){
        if(root == nullptr || re == false) return 0;
        int Left,Right;
        Left = MaxDepth(root->left, re) + 1;
        Right = MaxDepth(root->right, re) + 1;
        if(abs(Left-Right) > 1) re = false;
        return Left > Right ? Left : Right;
    }
/*
    //自顶向下,多次DFS,暴力求解
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        int Left = 0, Right = 0;
        Left = MaxDepth(root->left);
        Right = MaxDepth(root->right);
        if(abs(Left-Right) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int MaxDepth(TreeNode *root){
        if(root == nullptr) return 0;
        int Left,Right;
        Left = MaxDepth(root->left);
        Right = MaxDepth(root->right);
        //别忘了,树的深度 + 1
        return Left > Right ? (Left+1) : (Right+1);
    }*/
};
// @lc code=end

