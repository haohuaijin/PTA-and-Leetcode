/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层次遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (59.90%)
 * Likes:    327
 * Dislikes: 0
 * Total Accepted:    62.3K
 * Total Submissions: 103.9K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
 * 
 * 例如:
 * 给定二叉树: [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其层次遍历结果：
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        int Layers = 0; 
        int countNum = 0; //this Layers Num
        int NextNum = 0; //Next Layers NUm
        int count = 0; //Now count Num if pop() record
        vector<vector<int> > record;
        vector<int> oneLine; //use the one dimension vector to initialize the two dimension vector
        queue<TreeNode*> q;
        if(root != NULL){
            q.push(root);
            countNum++;
        }
        while(!q.empty()){
            TreeNode *tmp = q.front();
            q.pop();
            count++;
            oneLine.push_back(tmp->val);

            if(tmp->left != NULL){
                q.push(tmp->left);
                NextNum++;
            }
            if(tmp->right != NULL){
                q.push(tmp->right);
                NextNum++;
            }
            
            if(count == countNum){ //统计下一层
                Layers++;
                countNum = NextNum;
                NextNum = 0;
                count = 0;
                record.push_back(oneLine);
                oneLine.clear();
            }
        }
        return record;
    }
};
// @lc code=end

