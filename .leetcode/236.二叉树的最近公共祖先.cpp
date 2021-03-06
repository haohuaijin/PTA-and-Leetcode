/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 *
 * https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (58.64%)
 * Likes:    319
 * Dislikes: 0
 * Total Accepted:    36.7K
 * Total Submissions: 62.4K
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n1'
 *
 * 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
 * 
 * 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x
 * 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 * 
 * 例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]
 * 
 * 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * 输出: 3
 * 解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * 输出: 5
 * 解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
 * 
 * 
 * 
 * 
 * 说明:
 * 
 * 
 * 所有节点的值都是唯一的。
 * p、q 为不同节点且均存在于给定的二叉树中。
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *res = nullptr;
        lowerCommon(root, p, q, res);
        return res;
    }
    void lowerCommon(TreeNode* root,TreeNode* p,TreeNode* q,TreeNode* &res){
        if(res != nullptr) return;

        if(root->left != nullptr) lowerCommon(root->left, p, q, res);
        if(root->right != nullptr) lowerCommon(root->right, p, q, res);

        if(res != nullptr) return;

        if(Find(root, p) && Find(root, q))
            res = root;
    }
    bool Find(TreeNode *root, TreeNode *p){
        if(root == nullptr) return false;
        if(root == p) return true;
        return Find(root->left, p) || Find(root->right, p);
    }*/
    //父指针法，用map，set效率比较低
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return root;
        unordered_map<TreeNode*,TreeNode*> res;
        stack<TreeNode*> s;
        s.push(root);
        res.insert({root, nullptr});

        while(!s.empty()){
            TreeNode *tmp = s.top(); s.pop();

            if(tmp->left != nullptr){
                res.insert({tmp->left, tmp});
                s.push(tmp->left);
            }
            if(tmp->right != nullptr){
                res.insert({tmp->right, tmp});
                s.push(tmp->right);
            }
        }

        unordered_set<TreeNode*> ancestor;
        while(p != nullptr){
            ancestor.insert(p);
            p = res[p];
        }
        TreeNode *tmp = q;
        while(ancestor.find(tmp) == ancestor.end()){
            tmp = res[tmp];
        }
        return tmp;
    }
};
// @lc code=end

