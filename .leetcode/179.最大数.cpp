/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res;
        sort(nums.begin(), nums.end(), compare);
        if(to_string(nums[0]) == "0") return "0";
        for(auto i : nums)
            res += to_string(i);
        return res;
    }
    static bool compare(const int &s1, const int &s2)
    {
        string t1 = to_string(s1);
        string t2 = to_string(s2);
        string a = t1 + t2;
        string b = t2 + t1;
        return a > b;
    }
};
// @lc code=end

