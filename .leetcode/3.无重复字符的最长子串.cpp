/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (37.24%)
 * Likes:    5555
 * Dislikes: 0
 * Total Accepted:    1M
 * Total Submissions: 2.7M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: s = "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 * 示例 4:
 * 
 * 
 * 输入: s = ""
 * 输出: 0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * s 由英文字母、数字、符号和空格组成
 * 
 * 
 */

// @lc code=start
//滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        unordered_set<char> set;
        set.insert(s[0]);
        int ret = 1, p = 0; //p左指针
        for(int i=1; i<s.size(); ++i){
            if(set.find(s[i]) == set.end()){
                set.insert(s[i]);
                if(ret < set.size())
                    ret  = set.size();
            } else {
                // 这里找到s[i]处对应的字符，并把路径上遇到的所有字符删除
                while(++p != i && s[p-1] != s[i]){
                    set.erase(s[p-1]);
                }
                /*
                while(left != i){
                    ++left;
                    if(s[left-1] != s[i])
                        set.erase(s[left-1]);
                    else
                        break;
                }
                */
            }
        }
        return ret;
    }
};
// @lc code=end

