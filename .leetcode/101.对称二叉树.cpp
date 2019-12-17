/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        while(!q.empty()){
            auto tmp1 = q.front(); q.pop();
            auto tmp2 = q.front(); q.pop();
            if(tmp1 == NULL && tmp2 == NULL) continue;
            if(tmp1 == NULL || tmp2 == NULL) return false;
            if(tmp1->val != tmp2->val) return false;
            q.push(tmp1->left);
            q.push(tmp2->right);
            q.push(tmp1->right);
            q.push(tmp2->left);
        }
        return true;
    }
/*
    bool isSymmetric(TreeNode* root) {
        bool tmp;
        if(root == NULL) return true;
        tmp = isSymmetricTree(root->left,root->right);
        return tmp;
    }
    bool isSymmetricTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        if((p == NULL && q != NULL) || (p != NULL && q == NULL)) return false;
        if(p->val != q->val) return false;
        else {
            bool tmp1 = isSymmetricTree(p->left,q->right);
            bool tmp2 = isSymmetricTree(p->right,q->left);
            if(!tmp1 || !tmp2) return false;
        }
        return true;
    }*/
};
// @lc code=end

