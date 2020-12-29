/*
 * @lc app=leetcode.cn id=324 lang=cpp
 *
 * [324] 摆动排序 II
 *
 * https://leetcode-cn.com/problems/wiggle-sort-ii/description/
 *
 * algorithms
 * Medium (36.62%)
 * Likes:    222
 * Dislikes: 0
 * Total Accepted:    17.1K
 * Total Submissions: 46.8K
 * Testcase Example:  '[1,5,1,1,6,4]'
 *
 * 给定一个无序的数组 nums，将它重新排列成 nums[0] < nums[1] > nums[2] < nums[3]... 的顺序。
 * 
 * 示例 1:
 * 
 * 输入: nums = [1, 5, 1, 1, 6, 4]
 * 输出: 一个可能的答案是 [1, 4, 1, 5, 1, 6]
 * 
 * 示例 2:
 * 
 * 输入: nums = [1, 3, 2, 2, 3, 1]
 * 输出: 一个可能的答案是 [2, 3, 1, 3, 1, 2]
 * 
 * 说明:
 * 你可以假设所有输入都会得到有效的结果。
 * 
 * 进阶:
 * 你能用 O(n) 时间复杂度和 / 或原地 O(1) 额外空间来实现吗？
 * 
 */

// @lc code=start
/*
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        for(auto i : nums)
            temp.push_back(i);
        int length = nums.size();
        int end = length - 1;
        int mid = (length%2==0) ? (length/2-1) : (length/2);
        int i = 0;
        while(i < nums.size()){
            nums[i++] = temp[mid--];
            if(i == nums.size()) break;
            nums[i++] = temp[end--];
        }
    }
};
*/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();

        // Find a median.
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;

        //使用虚拟地址
        #define A(i) nums[(1+2*(i)) % (n|1)]

        // 3-way-partition-to-wiggly in O(n) time with O(1) space.
        int i = 0, j = 0, k = n - 1;
        while (j <= k) {
            if (A(j) > mid)
                swap(A(i++), A(j++));
            else if (A(j) < mid)
                swap(A(j), A(k--));
            else
                j++;
        }
    }
};
// @lc code=end
