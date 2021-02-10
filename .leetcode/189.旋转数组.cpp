/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 *
 * https://leetcode-cn.com/problems/rotate-array/description/
 *
 * algorithms
 * Medium (45.58%)
 * Likes:    875
 * Dislikes: 0
 * Total Accepted:    226.1K
 * Total Submissions: 496K
 * Testcase Example:  '[1,2,3,4,5,6,7]\n3'
 *
 * 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
 * 你可以使用空间复杂度为 O(1) 的 原地 算法解决这个问题吗？
 * 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [1,2,3,4,5,6,7], k = 3
 * 输出: [5,6,7,1,2,3,4]
 * 解释:
 * 向右旋转 1 步: [7,1,2,3,4,5,6]
 * 向右旋转 2 步: [6,7,1,2,3,4,5]
 * 向右旋转 3 步: [5,6,7,1,2,3,4]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入：nums = [-1,-100,3,99], k = 2
 * 输出：[3,99,-1,-100]
 * 解释: 
 * 向右旋转 1 步: [99,-1,-100,3]
 * 向右旋转 2 步: [3,99,-1,-100]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -2^31 
 * 0 
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
// my solutions
class Solution {
public:
    /*
    //first method
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        for(int i=0; i < k; i++){
            int t = nums.back();
            nums.pop_back();
            nums.insert(nums.begin(), t);
        }
    }
    */
    // second method
    void rotate(vector<int>& nums, int k){
        int len = nums.size();
        k = k % len;
        vector<int> a(nums.begin(), nums.end());
        for(int i=0; i<len-k; i++)
            nums[i+k] = a[i];
        for(int i = len-k, m = -1; i < len; i++)
            nums[++m] = a[i];
    }
};
// @lc code=end

