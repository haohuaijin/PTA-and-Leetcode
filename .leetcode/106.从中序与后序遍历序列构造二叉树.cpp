/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (65.68%)
 * Likes:    137
 * Dislikes: 0
 * Total Accepted:    20.2K
 * Total Submissions: 30.6K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 根据一棵树的中序遍历与后序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 中序遍历 inorder = [9,3,15,20,7]
 * 后序遍历 postorder = [9,15,7,20,3]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode *res;
        res = DFS(inorder, postorder, 0, postorder.size()-1, 0);
        return res;
    }
    TreeNode *DFS(vector<int> &in, vector<int> &po, int p_start, int p_end, int i_start){
        if(p_start > p_end) return nullptr;

        TreeNode *root = new TreeNode(po[p_end]);
        int index = Find(in, po[p_end]); //找到根结点在后序遍历里面的下标
        int Size = index - i_start; //左子树的大小

        root->left = DFS(in, po, p_start, p_start+Size-1, i_start);
        root->right = DFS(in, po, p_start+Size, p_end-1, index+1);

        return root;
    }
    int Find(vector<int> &in, int num){
        int count = 0;
        auto it = find(in.begin(), in.end(), num);
        auto point = in.begin();
        while(point != it){
            count++;
            point++;
        }
        return count;
    }*/
    //利用map来储存inorder里面值与下标的关系，加速(代替Find)
    //题目的关键：找好下标的对应关系
    unordered_map<int, int> Map;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0; i<(int)(postorder.size()); i++)
            Map[inorder[i]] = i;
        TreeNode *res;
        res = DFS(inorder, postorder, 0, postorder.size()-1, 0);
        return res;
    }
    TreeNode *DFS(vector<int> &in, vector<int> &po, int p_start, int p_end, int i_start){
        if(p_start > p_end) return nullptr;

        TreeNode *root = new TreeNode(po[p_end]);
        int index = Map[po[p_end]]; //找到根结点，在中序遍历里面的下标
        int Size = index - i_start; //左子树的大小

        root->left = DFS(in, po, p_start, p_start+Size-1, i_start);
        root->right = DFS(in, po, p_start+Size, p_end-1, index+1);

        return root;
    }
};
// @lc code=end

