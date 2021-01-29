/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 *
 * https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/description/
 *
 * algorithms
 * Hard (41.92%)
 * Likes:    522
 * Dislikes: 0
 * Total Accepted:    40.3K
 * Total Submissions: 95.7K
 * Testcase Example:  '[5,2,6,1]'
 *
 * 给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于
 * nums[i] 的元素的数量。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：nums = [5,2,6,1]
 * 输出：[2,1,1,0] 
 * 解释：
 * 5 的右侧有 2 个更小的元素 (2 和 1)
 * 2 的右侧仅有 1 个更小的元素 (1)
 * 6 的右侧有 1 个更小的元素 (1)
 * 1 的右侧有 0 个更小的元素
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int *index;
    int *temp;
    int *tempIndex;
    vector<int> ans;

    vector<int> countSmaller(vector<int>& nums) {
        int len = nums.size();
        this->index = new int[len];
        this->temp = new int[len];
        this->tempIndex = new int[len];
        this->ans.resize(len);

        for(int i=0; i<len; ++i){
            index[i] = i;
        }
        int l = 0, r = len - 1;
        mergeSort(nums, l, r);

        return ans;
    }
    void mergeSort(vector<int>& a, int l, int r){
        if(l >= r) return;
        int mid = l + (r - l) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid+1, r);
        merge(a, l, mid, r);
    }
    void merge(vector<int>& a, int l, int mid, int r){
        for(int k = l; k <=r; ++k){
            tempIndex[k] = index[k];
            temp[k] = a[k];
        }
        int i = l, j = mid + 1;
        for(int k = l; k <= r; ++k){
            if(i > mid){
                a[k] = temp[j]; index[k] = tempIndex[j];
                ++j;
            } else if(j > r){
                a[k] = temp[i]; index[k] = tempIndex[i];
                ans[tempIndex[i]] += (j - mid - 1);
                ++i;
            } else if(temp[i] <= temp[j]){
                a[k] = temp[i]; index[k] = tempIndex[i];
                ans[tempIndex[i]] += (j - mid - 1);
                ++i;
            } else {
                a[k] = temp[j]; index[k] = tempIndex[j];
                ++j;
            }
        }
    }
};
// @lc code=end
