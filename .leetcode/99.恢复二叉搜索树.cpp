/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 *
 * https://leetcode-cn.com/problems/recover-binary-search-tree/description/
 *
 * algorithms
 * Hard (54.20%)
 * Likes:    122
 * Dislikes: 0
 * Total Accepted:    8.9K
 * Total Submissions: 16.4K
 * Testcase Example:  '[1,3,null,null,2]'
 *
 * 二叉搜索树中的两个节点被错误地交换。
 * 
 * 请在不改变其结构的情况下，恢复这棵树。
 * 
 * 示例 1:
 * 
 * 输入: [1,3,null,null,2]
 * 
 * 1
 * /
 * 3
 * \
 * 2
 * 
 * 输出: [3,1,null,null,2]
 * 
 * 3
 * /
 * 1
 * \
 * 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,1,4,null,null,2]
 * 
 * ⁠ 3
 * ⁠/ \
 * 1   4
 * /
 * 2
 * 
 * 输出: [2,1,4,null,null,3]
 * 
 * ⁠ 2
 * ⁠/ \
 * 1   4
 * /
 * ⁠ 3
 * 
 * 进阶:
 * 
 * 
 * 使用 O(n) 空间复杂度的解法很容易实现。
 * 你能想出一个只使用常数空间的解决方案吗？
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
    void recoverTree(TreeNode* root) {
        if(root == nullptr) return;
        vector<TreeNode*> res;
        DFS(root, res);
        //swap,插入排序
        int i,j;
        for(i=1; i<(int)(res.size()); i++){
            int tmp = res[i]->val;
            //注意排序的下标，实现
            for(j=i; j>0 && res[j-1]->val > tmp; j--)
                res[j]->val = res[j-1]->val;
            res[j]->val = tmp;
        }
    }
    void DFS(TreeNode* root,vector<TreeNode*> &res){
        if(root->left != nullptr) DFS(root->left, res);
        res.push_back(root);
        if(root->right != nullptr) DFS(root->right, res);
    }
};
// @lc code=end

