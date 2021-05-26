/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 *
 * https://leetcode-cn.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (40.65%)
 * Likes:    914
 * Dislikes: 0
 * Total Accepted:    391.4K
 * Total Submissions: 962.7K
 * Testcase Example:  '"hello"\n"ll"'
 *
 * 实现 strStr() 函数。
 * 
 * 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0
 * 开始）。如果不存在，则返回  -1 。
 * 
 * 
 * 
 * 说明：
 * 
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 * 
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与 C 语言的 strstr() 以及 Java 的 indexOf()
 * 定义相符。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：haystack = "hello", needle = "ll"
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：haystack = "aaaaa", needle = "bba"
 * 输出：-1
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：haystack = "", needle = ""
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * haystack 和 needle 仅由小写英文字符组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void getNext(const string& str, vector<int>& next){
        next[0] = -1;
        int i = 0, j = -1;
        int len = str.size();
        while(i < len){
            if(j == -1 || str[i] == str[j]){
                ++i; ++j;
                next[i] = j;
            } else {
                j = next[j];
            }
        }
    }

    int strStr(string haystack, string needle) {
        int i = 0, j = 0;
        int len1 = haystack.size(), len2 = needle.size();
        if(len2 == 0) return 0;
        vector<int> next(len2+1);
        getNext(needle, next);

        while(i < len1 && j < len2){
            if(j == -1 || haystack[i] == needle[j]){
                ++i; ++j;
            } else {
                j = next[j];
            }
        }
    
        if(j == len2) 
            return i - j;
        else    
            return -1;
    }
};
// @lc code=end

