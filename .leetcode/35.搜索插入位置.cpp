/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 *
 * https://leetcode-cn.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (47.03%)
 * Likes:    930
 * Dislikes: 0
 * Total Accepted:    390.5K
 * Total Submissions: 830.4K
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 * 
 * 你可以假设数组中无重复元素。
 * 
 * 示例 1:
 * 
 * 输入: [1,3,5,6], 5
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: [1,3,5,6], 2
 * 输出: 1
 * 
 * 
 * 示例 3:
 * 
 * 输入: [1,3,5,6], 7
 * 输出: 4
 * 
 * 
 * 示例 4:
 * 
 * 输入: [1,3,5,6], 0
 * 输出: 0
 * 
 * 
 */

// @lc code=start
/*
// 二分法第一种写法 left <= right, 左闭右闭区间[left, right]
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1; //注意左闭右闭
        while(l <= r){
            int mid = l + (r - l) / 2; 
            if(nums[mid] == target) return mid;
            if(nums[mid] > target){
                r = mid-1;
            } else {
                l = mid+1;
            }
        } 
        return l;
    }
};
*/
// 二分法第二种写法 left < right, 左开右闭区间[left, right)
class Solution {
public: 
    int searchInsert(vector<int>& nums, int target){
        int l = 0, r = nums.size(); //注意左开右闭
        while(l < r){
            int mid = l + ((r - l) >> 1);
            if(nums[mid] == target) return mid;
            if(nums[mid] > target){
                r = mid;
            } else {
                l = mid+1;
            }
        }
        return l;
    }
};

// @lc code=end

