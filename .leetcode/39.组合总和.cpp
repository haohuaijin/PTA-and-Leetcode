/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 *
 * https://leetcode-cn.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (72.45%)
 * Likes:    1382
 * Dislikes: 0
 * Total Accepted:    267.7K
 * Total Submissions: 369.5K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的数字可以无限制重复被选取。
 * 
 * 说明：
 * 
 * 
 * 所有数字（包括 target）都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1：
 * 
 * 输入：candidates = [2,3,6,7], target = 7,
 * 所求解集为：
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * 示例 2：
 * 
 * 输入：candidates = [2,3,5], target = 8,
 * 所求解集为：
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= candidates.length <= 30
 * 1 <= candidates[i] <= 200
 * candidate 中的每个元素都是独一无二的。
 * 1 <= target <= 500
 * 
 * 
 */

// @lc code=start
// 一次成功，我自己都没想到。
// 主要的是因为上CS61a的时候，老师讲过类似的题目。
// 将结果划分成两部分，一部分包含candidates[l]的，另一部分不包含candidates[l]的。
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> now;
        helper(ret, now, candidates, 0, target);
        return ret;
    }
    void helper(vector<vector<int>>& ret, vector<int>& now, vector<int>& candidates, int l, int target){
        int sub = target - accumulate(now.begin(), now.end(), 0);

        if(sub == 0){
            ret.push_back(now);
            return;
        } else if (sub < 0){
            return;
        }

        now.push_back(candidates[l]);
        helper(ret, now, candidates, l, target);
        now.pop_back();

        if(l+1 < candidates.size()){
            helper(ret, now, candidates, l+1, target); 
        }
    }
};
// @lc code=end

