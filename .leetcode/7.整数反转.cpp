/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 *
 * https://leetcode-cn.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (33.32%)
 * Likes:    1572
 * Dislikes: 0
 * Total Accepted:    248.9K
 * Total Submissions: 745.5K
 * Testcase Example:  '123'
 *
 * 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 * 
 * 示例 1:
 * 
 * 输入: 123
 * 输出: 321
 * 
 * 
 * 示例 2:
 * 
 * 输入: -123
 * 输出: -321
 * 
 * 
 * 示例 3:
 * 
 * 输入: 120
 * 输出: 21
 * 
 * 
 * 注意:
 * 
 * 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回
 * 0。
 * 
 */

// @lc code=start
class Solution {
public:
    /* myself
    int reverse(int x) {
        if(x <= INT_MIN || x > INT_MAX) return 0;
        bool flag = true;
        if(x < 0) {
            x = -x;
            flag = false;
        }
        long long num = 0;
        while(x > 0){
            num = num * 10 + x%10;
            x = x / 10;
        }
        if(!flag) num = -num;
        if((num <= INT_MIN || num > INT_MAX)) return 0;
        return (int)num;
    }*/
    // 比较优美，不过效率不高
    int reverse(int x) {
        int rev = 0;
        while(x != 0){
            int pop = x % 10;
            x /= 10;
            if(rev > INT_MAX/10 || (rev == INT_MAX && pop > 7)) return 0;
            if(rev < INT_MIN/10 || (rev == INT_MIN && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};
// @lc code=end

