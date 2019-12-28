/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
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
    //DFS，认真思考
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        DFS(root, 0, res);
        return res;
    }
    void DFS(TreeNode *root, int level,vector<vector<int>> &res){
        if(root == nullptr) return;
        if(level >= res.size()) res.push_back({});

        if(level%2 == 0) res[level].push_back(root->val);
        else res[level].insert(res[level].begin(), root->val);

        DFS(root->left, level + 1, res);
        DFS(root->right, level + 1, res);
    }
/*
    //BFS
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(root == nullptr) return res;
        TreeNode *last = root;
        vector<int> book;
        bool flag = true;
        q.push(root);
        while(!q.empty()){
            TreeNode *tmp = q.front(); q.pop();
            book.push_back(tmp->val);

            if(tmp->left != nullptr) q.push(tmp->left);
            if(tmp->right != nullptr) q.push(tmp->right);

            if(tmp == last){
                last = q.back();
                if(flag) {res.push_back(book); flag = false;}
                else{
                    reverse(book.begin(), book.end());
                    res.push_back(book);
                    flag = true;
                }
                book.clear();
            }
        }
        return res;
    }

/*
    //最初的想法,记录每一层的结点的数目,实现分层储存
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> record;
        queue<TreeNode*> q;
        vector<int> Oneline;
        int NowCount = 0;
        int NextCount = 0;
        int count = 0; 
        int N = 0;
        if(root != NULL){
            q.push(root);
            NowCount++;
        }
        while(!q.empty()){
            TreeNode *tmp = q.front();
            q.pop();
            count++;
            Oneline.push_back(tmp->val);
            if(tmp->left != NULL){
                q.push(tmp->left);
                NextCount++;
            }
            if(tmp->right != NULL){
                q.push(tmp->right);
                NextCount++;
            }
            if(count == NowCount){
                count = 0; 
                NowCount = NextCount;
                NextCount = 0;
                if(N++%2 != 0) reverse(Oneline.begin(),Oneline.end());
                record.push_back(Oneline);
                Oneline.clear();
            }
        }
        return record;
    }*/
};
// @lc code=end

