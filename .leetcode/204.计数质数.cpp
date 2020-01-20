/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 *
 * https://leetcode-cn.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (31.37%)
 * Likes:    260
 * Dislikes: 0
 * Total Accepted:    38.8K
 * Total Submissions: 122.6K
 * Testcase Example:  '10'
 *
 * 统计所有小于非负整数 n 的质数的数量。
 * 
 * 示例:
 * 
 * 输入: 10
 * 输出: 4
 * 解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    /*
    //朴素素数筛法
    int countPrimes(int n) {
        bool isPrime[n + 10];
        int count = 0;
        for(int i=2; i<n; i++) isPrime[i] = true;

        for(int i=2; i<n; i++){
            if(isPrime[i]){
                for(int j=2*i; j<n; j+=i)
                    isPrime[j] = false;
            }
        }

        for(int i=2; i<n; i++){
            if(isPrime[i]) count++;
        }
        return count;
    }*/
    //优化素数筛法
    int countPrimes(int n) {
        bool isPrime[n + 10];
        int count = 0;
        for(int i=2; i<n; i++) isPrime[i] = true;

        for(int i=2; i*i<n; i++){ //这里
            if(isPrime[i]){
                for(int j=i*i; j<n; j+=i) // 这里
                    isPrime[j] = false;
            }
        }

        for(int i=2; i<n; i++){
            if(isPrime[i]) count++;
        }
        return count;
    }
};
// @lc code=end

