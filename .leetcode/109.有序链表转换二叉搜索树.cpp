/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 *
 * https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/description/
 *
 * algorithms
 * Medium (69.50%)
 * Likes:    127
 * Dislikes: 0
 * Total Accepted:    15.5K
 * Total Submissions: 22.3K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
 * 
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 * 
 * 示例:
 * 
 * 给定的有序链表： [-10, -3, 0, 5, 9],
 * 
 * 一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    //空间换时间
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> res;
        while(head != nullptr){
            res.push_back(head->val);
            head = head->next;
        }
        TreeNode *q = InsertTree(res, 0, res.size()-1);
        return q;
    }
    TreeNode* InsertTree(vector<int> &res,int start,int end) {
        if(start > end) return nullptr;
        int mid = (start + end) / 2;
        TreeNode *q = new TreeNode(res[mid]);

        q->left = InsertTree(res, start, mid - 1);
        q->right = InsertTree(res, mid + 1, end);
        return q;
    }
};
// @lc code=end

