/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 *
 * https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (41.87%)
 * Likes:    1371
 * Dislikes: 0
 * Total Accepted:    392.4K
 * Total Submissions: 937.3K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 * 
 * 进阶：你能尝试使用一趟扫描实现吗？
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,4,5], n = 2
 * 输出：[1,2,3,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [1], n = 1
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：head = [1,2], n = 1
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中结点的数目为 sz
 * 1 
 * 0 
 * 1 
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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        int count = 0;
        while(p != nullptr){
            p = p->next;
            ++count;
        }
        p = head;
        int k = count-n+1;
        if(k == 1) head = head->next; //头节点单独处理
        else {
            for(int i=1; i<k-1; i++)
                p = p->next;
            p->next = p->next->next;
        }
        return head;
    }
};
*/
/*
// 空间换时间
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* record[35]{nullptr};
        ListNode *p = head;
        int count = 0;
        while(p != nullptr){
            record[count++] = p; 
            p = p->next;
        }
        int k = count-n+1;
        if(k == 1) head = head->next; //头节点单独处理
        else record[k-2]->next = record[k-2]->next->next;
        return head;
    }
};
*/
// 快慢指针
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n){
        // 通过添加一个哑节点（dummy node），它的next指针指向链表的头节点。
        // 这样我们就不需要对头节点进行特殊的判断了。
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = head;
        ListNode* second = dummy;
        for(int i=0; i<n; i++){
            first = first->next;
        }
        while(first){
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        ListNode* ret = dummy->next;
        delete dummy;
        return ret;
    }
};
// @lc code=end

