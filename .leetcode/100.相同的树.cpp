/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // if(q == NULL && q == NULL) return true;
        // if(q == NULL || q == NULL) return false;
        // if(q->val != p->val) return false;
        queue<TreeNode*> que;
        que.push(p);
        que.push(q);
        while(!que.empty()){ //迭代
            auto tmp1 = que.front(); que.pop();
            auto tmp2 = que.front(); que.pop();
            if(tmp1 == NULL && tmp2 == NULL) continue;
            if(tmp1 == NULL || tmp2 == NULL) return false;
            if(tmp1->val != tmp2->val) return false;
            que.push(tmp1->left);
            que.push(tmp2->left);
            que.push(tmp1->right);
            que.push(tmp2->right);
        }
        return true;
    }

    /*
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if((p == NULL && q != NULL) || (p != NULL && q == NULL)) return false;
        if(q == NULL && q == NULL) return true;
        if(q->val != p->val) return false;
        else {
            bool tmp1 = isSameTree(p->left,q->left);
            bool tmp2 = isSameTree(p->right,q->right);
            if(!tmp1 || !tmp2) return false;
        }
        return true;
    }*/
};
// @lc code=end

