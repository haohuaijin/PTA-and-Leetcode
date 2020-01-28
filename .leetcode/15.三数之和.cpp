/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (24.77%)
 * Likes:    1732
 * Dislikes: 0
 * Total Accepted:    146.6K
 * Total Submissions: 582.1K
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 示例：
 * 
 * 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //leetcode 解法 自己思考
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int len = nums.size();
        if(len < 3) return res;
        sort(nums.begin(), nums.end());
        for(int i=0; i<len; i++){
            if(nums[i]>0) break;
            if(i>0 && nums[i] == nums[i-1]) continue; //避免重复
            int L = i+1;
            int R = len-1;
            while(L<R){
                int sum = nums[i] + nums[L] + nums[R];
                if(sum == 0){
                    res.push_back({nums[i], nums[L], nums[R]});
                    while(L<R && nums[L] == nums[L+1]) L++; //去重
                    while(L<R && nums[R] == nums[R-1]) R--; //去重
                    L++;
                    R--;
                } else if(sum > 0){
                    R--;
                } else {
                    L++;
                }
            }
        }
        return res;
    }
};
// @lc code=end

