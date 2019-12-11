/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
/* 优化前
class Solution {
public:
    TreeNode* InsertNode(vector<int> &nums,int start,int end){
        int mid = (start + end)/2;
        if(start > end) return NULL;
         //在有构造函数,且c++里面在新建节点
        TreeNode *root = new struct TreeNode(0);
        root->val = nums[mid];
        root->left = InsertNode(nums, start, mid-1);
        root->right = InsertNode(nums, mid+1, end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int length = nums.size();
        TreeNode *root;
        if(length == 0) return NULL;
        root = InsertNode(nums,0,length-1); //注意下标
        return root;
    }
};
*/
//优化后
class Solution {
public:
    TreeNode* InsertNode(vector<int> &nums,int start,int end){
        int mid = (start + end)/2;
        if(start > end) return nullptr;
         //在有构造函数,且c++里面在新建节点
        TreeNode *root = new struct TreeNode(nums[mid]);

        root->left = InsertNode(nums, start, mid-1);
        root->right = InsertNode(nums, mid+1, end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root;
        if(nums.empty()) return nullptr;
        root = InsertNode(nums,0,nums.size()-1); //注意下标
        return root;
    }
};
// @lc code=end

