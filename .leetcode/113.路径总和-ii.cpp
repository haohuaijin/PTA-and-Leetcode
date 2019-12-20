/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 *
 * https://leetcode-cn.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (57.90%)
 * Likes:    144
 * Dislikes: 0
 * Total Accepted:    23.6K
 * Total Submissions: 40.7K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 给定如下二叉树，以及目标和 sum = 22，
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \    / \
 * ⁠       7    2  5   1
 * 
 * 
 * 返回:
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
 * ]
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> tmp = treePath(root);
        vector<vector<int>> re;
        for(auto it = tmp.begin(); it != tmp.end(); it++){
            int num = 0;
            for(auto point = (*it).begin(); point != (*it).end(); point++){
                num = num + *point;
                //cout << *point << ' ';
            }
            //cout << endl;
            if(num == sum) re.push_back(*it);
        }
        return re;
    }
     vector<vector<int>> treePath(TreeNode *root){
        vector<vector<int>> re,leftPath,rightPath; 
        if(root == nullptr) return re;
        vector<int> path;
        path.push_back(root->val);

        if(root->left == nullptr && root->right == nullptr){
            re.push_back(path);
            return re;
        }

        if(root->left != nullptr) leftPath = treePath(root->left);
        if(root->right != nullptr) rightPath = treePath(root->right);

        for(auto le : leftPath){
            le.insert(le.begin(),root->val);
            re.push_back(le);
        }
        for(auto ri : rightPath){
            ri.insert(ri.begin(),root->val);
            re.push_back(ri);
        }
        return re;
    }
};
// @lc code=end

