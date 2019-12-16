/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> visit;
        if(n == 0) return visit;
        else {
            visit = Trees(1,n);
        }
        return visit;
    }
    //递归：逐步的将问题分割，用递归解决
    vector<TreeNode*> Trees(int start,int end){
        vector<TreeNode*> visit,Left,Right;
        if(start > end){ //boundary check
            visit.push_back(nullptr); //如果超出范围，返回NULL
            return visit;
        }

        for(int i=start; i<=end; i++){
            Left = Trees(start, i-1);
            Right = Trees(i+1, end);

            for(auto le : Left){ //笛卡尔积,序偶
                for(auto ri : Right){
                    TreeNode *tmp = new TreeNode(i);
                    tmp->left = le;
                    tmp->right = ri;
                    visit.push_back(tmp);
                }
            }
        }
        return visit;
    }


    /* 自己实现，太麻烦，
    #思路：用DFS找出n的全排列
    #对每一个排列建树
    #对建的树，进行前序遍历，删除前序遍历相同的树根
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> visit;
        if(n == 0) return visit;
        int count = 0;
        int path[n+2] = {0};
        int book[n+2] = {0};
        vector<vector<int>> index;
        vector<int> q;
        vector<TreeNode*> retu;
        DFS(n,count,book,path,visit);
        while(!visit.empty()){
            int flag = 0;
            TreeNode *tmp = visit.back();
            visit.pop_back();
            pre(tmp,q);
            for(int i=0;i<index.size();i++){
                if(index[i] == q) flag = 1;
            }
            if(!flag){
                retu.push_back(tmp);
                index.push_back(q); 
            } 
            q.clear();
        }
        return retu;
    }
    TreeNode* InsertTree(int num,TreeNode *root){
        if(root == NULL) root = new TreeNode(num);
        if(num > root->val) root->right = InsertTree(num,root->right);
        else if(num < root->val) root->left = InsertTree(num,root->left);
        return root;
    }
    void DFS(int n,int count,int *book,int *path,vector<TreeNode*> &visit){
        if(n == count){
            TreeNode *root = new TreeNode(path[1]);
            for(int i=2;i<=n;i++){
                root = InsertTree(path[i],root);
            }
            visit.push_back(root);
        } else {
            for(int i=1; i<=n; i++){
                if(!book[i]){
                    book[i] = 1;
                    count++;
                    path[count] = i;
                    DFS(n,count,book,path,visit);
                    book[i] = 0;
                    count--;
                }
            }
        }
    }
    void pre(TreeNode *root,vector<int> &q){
        if(root != NULL) q.push_back(root->val);
        if(root->left != NULL) pre(root->left,q);
        if(root->right != NULL) pre(root->right,q);
    }*/
};
// @lc code=end

