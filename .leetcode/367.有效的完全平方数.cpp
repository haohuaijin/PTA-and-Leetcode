/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 *
 * https://leetcode-cn.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (42.73%)
 * Likes:    83
 * Dislikes: 0
 * Total Accepted:    21.2K
 * Total Submissions: 49.5K
 * Testcase Example:  '16'
 *
 * 给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。
 * 
 * 说明：不要使用任何内置的库函数，如  sqrt。
 * 
 * 示例 1：
 * 
 * 输入：16
 * 输出：True
 * 
 * 示例 2：
 * 
 * 输入：14
 * 输出：False
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    /*
    //简单
    bool isPerfectSquare(int num) {
        for(long i=0; i<=num/2+1; i++){
            if(i*i == num) 
                return true;
        }
        return false;
    }*/
    /* //二分查找
    bool isPerfectSquare(int num) {
        if(num < 2) return true;

        long left = 2, right = num/2, square;
        while(left <= right){
            square = left + (right - left) / 2;
            if(square*square == num) return true;

            if(square*square > num){
                right = square - 1;
            } else {
                left = square + 1;
            }
        }
        return false;
    }*/
    // 牛顿迭代
    bool isPerfectSquare(int num) {
        if(num < 2) return true;
        long x = num/2;
        while(x*x > num){
            x = (x + num/x)/2;
        }
        return (x*x == num);
    }
};
// @lc code=end

