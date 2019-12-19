/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 *
 * https://leetcode-cn.com/problems/path-sum/description/
 *
 * algorithms
 * Easy (48.33%)
 * Likes:    207
 * Dislikes: 0
 * Total Accepted:    41.8K
 * Total Submissions: 86.5K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22'
 *
 * 给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例: 
 * 给定如下二叉树，以及目标和 sum = 22，
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \      \
 * ⁠       7    2      1
 * 
 * 
 * 返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。
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
    bool hasPathSum(TreeNode* root, int sum) {
        stack<int> path;
        stack<TreeNode*> node;
        if(root == nullptr) return false;
        node.push(root);
        path.push(root->val);
        
        while(!path.empty()){
            int num = path.top(); path.pop();
            TreeNode* tmp = node.top(); node.pop();
            
            if((tmp->left  == nullptr) && (tmp->right == nullptr)){
                if(num == sum) return true;
            }
            if(tmp->left != nullptr){
                node.push(tmp->left);
                path.push(num + tmp->left->val);
            }
            if(tmp->right != nullptr){
                node.push(tmp->right);
                path.push(num + tmp->right->val);
            }
        }
        return false;
    }

/*
    bool hasPathSum(TreeNode* root, int sum) {
        vector<int> re;
        re = subPath(root);
        for(auto it = re.begin(); it != re.end(); it++){
            if(*it == sum) return true;
        }
        return false;
    }
    vector<int> subPath(TreeNode* root){
        vector<int> re,leftPath,rightPath;
        if(root == nullptr) return re;
        int num = root->val;
        //边界检测，不要忘了😒😒
        if(root->left == nullptr && root->right == nullptr){
            re.push_back(num);
            return re;
        }

        if(root->left != nullptr) leftPath = subPath(root->left);
        if(root->right != nullptr) rightPath = subPath(root->right);
        
        for(auto le : leftPath) re.push_back(num + le);
        for(auto ri : rightPath)re.push_back(num + ri);
        
        return re;
    }
    */
};
// @lc code=end

