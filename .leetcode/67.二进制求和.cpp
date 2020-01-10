/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (51.59%)
 * Likes:    282
 * Dislikes: 0
 * Total Accepted:    56.2K
 * Total Submissions: 108.4K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给定两个二进制字符串，返回他们的和（用二进制表示）。
 * 
 * 输入为非空字符串且只包含数字 1 和 0。
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int carry = 0;
        while(a.size() != 0 || b.size() != 0){
            int first = 0,second = 0;
            if(a.size() != 0){
                first = a[a.size()-1] - '0'; //这样转化char -> int
                a.pop_back();
            }
            if(b.size() != 0){
                second = b[b.size()-1] - '0';
                b.pop_back();
            }

            if((first + second + carry) == 0){
                res += "0";
            } else if((first + second + carry) == 1){
                res += "1";
                carry = 0;
            } else if((first + second + carry) == 2){
                res += "0";
                carry = 1;
            } else {
                res += "1";
                carry = 1;
            }
        }
        if(carry == 1) res += "1";
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

