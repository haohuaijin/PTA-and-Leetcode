/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (63.11%)
 * Likes:    297
 * Dislikes: 0
 * Total Accepted:    36K
 * Total Submissions: 56.9K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 前序遍历 preorder = [3,9,20,15,7]
 * 中序遍历 inorder = [9,3,15,20,7]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    //前序，中序建树
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *res = DFS(preorder, inorder, 0, preorder.size()-1, 0);
        return res;
    }
    TreeNode* DFS(vector<int>& pre,vector<int>& in,int p_start,int p_end,int i_start){
        if(p_start > p_end) return nullptr;

        //找到根结点，在中序遍历里面的下标
        int index = Find(in, pre[p_start]); 
        //cout << index << endl;
        int Size = index - i_start;

        TreeNode *root = new TreeNode(pre[p_start]);
        
        root->left = DFS(pre, in, p_start+1, p_start+Size, i_start);
        root->right = DFS(pre, in, p_start+Size+1, p_end, i_start+1+Size);//注意i_start的更新
        
        return root;
    }
    int Find(vector<int> &in, int num){
        auto it = find(in.begin(), in.end(), num);
        int count = 0;
        auto l = in.begin();
        while(it != l){
            count++;
            l++;
        }
        return count;
    }
};
// @lc code=end

