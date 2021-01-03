/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 *
 * https://leetcode-cn.com/problems/find-the-duplicate-number/description/
 *
 * algorithms
 * Medium (66.11%)
 * Likes:    1020
 * Dislikes: 0
 * Total Accepted:    112.3K
 * Total Submissions: 169.9K
 * Testcase Example:  '[1,3,4,2,2]'
 *
 * 给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和
 * n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。
 * 
 * 示例 1:
 * 
 * 输入: [1,3,4,2,2]
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,1,3,4,2]
 * 输出: 3
 * 
 * 
 * 说明：
 * 
 * 
 * 不能更改原数组（假设数组是只读的）。
 * 只能使用额外的 O(1) 的空间。
 * 时间复杂度小于 O(n^2) 。
 * 数组中只有一个重复的数字，但它可能不止重复出现一次。
 * 
 * 
 */

// @lc code=start
/*
空间复杂度O(N)，时间复杂度O(N)，没有改变数组
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> collect;
        for(int i : nums){
            if(collect.count(i)) return i;
            else collect.insert(i);
        }
        return 0;
    }
};
*/
/*
空间复杂度O(1)，时间复杂度O(NlogN)，改变了数组
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        for(int i=0; i<N-1; i++)
            if(nums[i] == nums[i+1])
                return nums[i];
        return 0;
    }
};
*/
// leetcode 快慢指针 Floyd 判圈算法
class Solution {
public:
    int findDuplicate(vector<int>& nums){
        int slow = nums[0];
        int fast = nums[nums[0]];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
// @lc code=end

