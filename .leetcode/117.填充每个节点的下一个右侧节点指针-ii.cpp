/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 *
 * https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/description/
 *
 * algorithms
 * Medium (43.09%)
 * Likes:    89
 * Dislikes: 0
 * Total Accepted:    11.5K
 * Total Submissions: 26.6K
 * Testcase Example:  '[1,2,3,4,5,null,7]'
 *
 * 给定一个二叉树
 * 
 * struct Node {
 * ⁠ int val;
 * ⁠ Node *left;
 * ⁠ Node *right;
 * ⁠ Node *next;
 * }
 * 
 * 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
 * 
 * 初始状态下，所有 next 指针都被设置为 NULL。
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 你只能使用常量级额外空间。
 * 使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 
 * 输入：root = [1,2,3,4,5,null,7]
 * 输出：[1,#,2,3,#,4,5,7,#]
 * 解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中的节点数小于 6000
 * -100 <= node.val <= 100
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
/*
    //BFS 迭代
    Node* connect(Node* root) {
        if(root == nullptr) return root;
        queue<Node*> q;
        q.push(root);
        Node *last = root;
        while(!q.empty()){
            Node *tmp = q.front(); q.pop();
            if(tmp->left != nullptr) q.push(tmp->left);
            if(tmp->right != nullptr) q.push(tmp->right);
            if(last == tmp){
                last = q.back();
            } else {
                tmp->next = q.front();
            }
        }
        return root;
    }*/
    //妙，主要是如何记录下一层，和遍历这一层
    Node* connect(Node* root) {
        Node *cur = root;
        while(cur != nullptr){
            Node *Next = new Node();
            Node *tail = Next;
            while(cur != nullptr){
                if(cur->left != nullptr){
                    tail->next = cur->left;
                    tail = tail->next;
                }
                if(cur->right != nullptr){
                    tail->next = cur->right;
                    tail = tail->next;
                }
                cur = cur->next;
            }
            cur = Next->next;
        }
        return root;
    }
};
// @lc code=end

