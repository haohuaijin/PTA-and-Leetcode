/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (66.01%)
 * Likes:    1713
 * Dislikes: 0
 * Total Accepted:    571.6K
 * Total Submissions: 865.9K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：l1 = [1,2,4], l2 = [1,3,4]
 * 输出：[1,1,2,3,4,4]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：l1 = [], l2 = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：l1 = [], l2 = [0]
 * 输出：[0]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 两个链表的节点数目范围是 [0, 50]
 * -100 
 * l1 和 l2 均按 非递减顺序 排列
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/*
//迭代法
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* r = dummy;
        while(l1 || l2){
            // 小技巧：可以直接在一个while里面全部归并完成。
            // 看了题解，这个题好像不用这样也可以，哈哈
            int n1 = l1 ? l1->val : 101;
            int n2 = l2 ? l2->val : 101;
            if(n1 > n2){
                r->next = l2;
                l2 = l2->next;
            } else {
                r->next = l1;
                l1 = l1->next;
            }
            r = r->next;
        }
        ListNode* ans = dummy->next;
        delete dummy; 
        return ans; 
    }
};
*/
//递归法
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr){
            return l2;
        } else if (l2 == nullptr){
            return l1;
        } else if (l1->val > l2->val){
            ListNode* ret = l2;
            ret->next = mergeTwoLists(l1, l2->next);
            return ret;
        } else {
            ListNode* ret = l1;
            ret->next = mergeTwoLists(l1->next, l2);
            return ret;
        }
    }
};
// @lc code=end

