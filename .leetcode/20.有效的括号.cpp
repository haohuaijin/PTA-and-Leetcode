/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (44.10%)
 * Likes:    2415
 * Dislikes: 0
 * Total Accepted:    640.8K
 * Total Submissions: 1.5M
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "()"
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "()[]{}"
 * 输出：true
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "(]"
 * 输出：false
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：s = "([)]"
 * 输出：false
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：s = "{[]}"
 * 输出：true
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 仅由括号 '()[]{}' 组成
 * 
 * 
 */

// @lc code=start
/*
// 使用栈
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for(int i=0; i<s.size(); ++i){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                stack.push(s[i]);
            } else {
                if(stack.empty()) 
                    return false;
                char tmp = stack.top(); stack.pop();
                if(tmp == '(' && s[i] != ')') 
                    return false;
                else if (tmp == '[' && s[i] != ']') 
                    return false;
                else if (tmp == '{' && s[i] != '}') 
                    return false;
            }
        }
        if(!stack.empty()) return false;
        return true;
    }
};
*/
// 使用ASCII可以做进一步的优化
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        stack.push(s[0]);
        for(int i=1; i<s.size(); i++){
            if(stack.empty() == true){
                stack.push(s[i]);
            }else if(s[i] - stack.top() == 1 || s[i] - stack.top() == 2){
                stack.pop();
            } else {
                stack.push(s[i]);
            }
        }
        return stack.empty();
    }
};
// @lc code=end

