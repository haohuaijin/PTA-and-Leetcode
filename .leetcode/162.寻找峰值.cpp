/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 *
 * https://leetcode-cn.com/problems/find-peak-element/description/
 *
 * algorithms
 * Medium (48.06%)
 * Likes:    342
 * Dislikes: 0
 * Total Accepted:    69.7K
 * Total Submissions: 145K
 * Testcase Example:  '[1,2,3,1]'
 *
 * 峰值元素是指其值大于左右相邻值的元素。
 * 
 * 给定一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，找到峰值元素并返回其索引。
 * 
 * 数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。
 * 
 * 你可以假设 nums[-1] = nums[n] = -∞。
 * 
 * 示例 1:
 * 
 * 输入: nums = [1,2,3,1]
 * 输出: 2
 * 解释: 3 是峰值元素，你的函数应该返回其索引 2。
 * 
 * 示例 2:
 * 
 * 输入: nums = [1,2,1,3,5,6,4]
 * 输出: 1 或 5 
 * 解释: 你的函数可以返回索引 1，其峰值元素为 2；
 * 或者返回索引 5， 其峰值元素为 6。
 * 
 * 
 * 说明:
 * 
 * 你的解法应该是 O(logN) 时间复杂度的。
 * 
 */

// @lc code=start
/*
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int length = nums.size();
        int lo = 0, hi = length - 1;
        if(length == 1) return 0;
        if(nums[0] > nums[1]) 
            return 0;
        else if(nums[length-1] > nums[length-2]) 
            return length-1;
        while(lo < hi){
            int mid = lo + (hi - lo)/2;
            if(nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1]) 
                return mid;
            else if(nums[mid] > nums[mid+1])
                hi = mid;
            else
                lo = mid;
        }
        return 0;
    }
};
    */
class Solution{
public:
    int findPeakElement(vector<int>& nums) {
        return localMinUtil(nums, 0, nums.size()-1, nums.size()-1)
    }

    int localMinUtil(vector<int> arr, int low, int high, int n) {
        int mid = low + (high - low) / 2;
        if((mid == 0 || arr[mid - 1] > arr[mid]) &&
                (mid == n - 1 || arr[mid] < arr[mid + 1]))
            return mid;
        else if(mid > 0 && arr[mid - 1] < arr[mid])
            return localMinUtil(arr, low, mid - 1, n);
        return localMinUtil(arr, mid + 1, high, n);
    }
};
// @lc code=end

