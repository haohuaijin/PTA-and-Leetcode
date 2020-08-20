/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 *
 * https://leetcode-cn.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (28.09%)
 * Likes:    361
 * Dislikes: 0
 * Total Accepted:    56.9K
 * Total Submissions: 202.2K
 * Testcase Example:  '[2,1,3]'
 *
 * 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
 * 
 * 假设一个二叉搜索树具有如下特征：
 * 
 * 
 * 节点的左子树只包含小于当前节点的数。
 * 节点的右子树只包含大于当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 * 输出: false
 * 解释: 输入为: [5,1,4,null,null,3,6]。
 * 根节点的值为 5 ，但是其右子节点值为 4 。
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
    /* 暴力，记录左右子树的节点
    bool isValidBST(TreeNode* root) {
        bool flag = true;
        vaild(root, flag);
        return flag;
    }
    vector<int> vaild(TreeNode *root,bool &flag){
        vector<int> res,Left,Right;
        if(root == nullptr || flag == false) return res;
        res.push_back(root->val);
        Left = vaild(root->left, flag);
        Right = vaild(root->right, flag);
        for(auto l : Left){
            if(l >= root->val){
                flag = false;
                return res;
            }
            res.push_back(l);
        }
        for(auto r : Right){
            if(r <= root->val){
                flag = false;
                return res;
            }
            res.push_back(r);
        }
        return res;
    }
    */
    /*
    //递归，理解
    bool isValidBST(TreeNode* root) {
        return helper(root,LONG_MIN,LONG_MAX);
    }
    bool helper(TreeNode *root,long lower,long upper){
        if(root == nullptr) return true;

        if(lower >= root->val || upper <= root->val)
            return false;
        //给结点设置，上下界
        if(!helper(root->left, lower, root->val)) return false;
        if(!helper(root->right, root->val, upper)) return false;
        return true;
    }*/
    /*
    //迭代法,前序遍历
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        stack<TreeNode*> node;
        stack<long> lower,upper;
        node.push(root);
        lower.push(LONG_MIN);
        upper.push(LONG_MAX);
        while(!node.empty()){
            TreeNode *tmp = node.top(); node.pop();
            long low = lower.top(); lower.pop();
            long up = upper.top();  upper.pop();

            if(tmp->val <= low || tmp->val >= up) return false;

            if(tmp->left != nullptr){
                node.push(tmp->left);
                lower.push(low); upper.push(tmp->val);
            }
            if(tmp->right != nullptr){
                node.push(tmp->right);
                lower.push(tmp->val); upper.push(up);
            }
        }
        return true;
    }/*
    //中序遍历,迭代,stack
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        long num = LONG_MIN;
        stack<TreeNode*> q;
        //精简版
        while(!q.empty() || root != nullptr){
            while(root != nullptr){
                q.push(root);
                root = root->left;
            }
            root = q.top(); q.pop();
            if(num >= root->val) return false;
            num = root->val;
            root = root->right;
        }
        return true;
    }*/
    //递归，中序遍历，升序不重复
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        long num = LONG_MIN;
        bool flag = true;
        DFS(root, num, flag);
        return flag;
    }
    void DFS(TreeNode *root,long &num,bool &flag){
        if(root->left != nullptr) DFS(root->left, num, flag);
        if(num >= root->val) flag = false;
        num = root->val;
        if(root->right != nullptr) DFS(root->right, num, flag);
    }
};
// @lc code=end

