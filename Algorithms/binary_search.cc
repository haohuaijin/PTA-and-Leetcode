#include <iostream>
#include <vector>
using namespace std;
// 二分法第一种写法 left <= right, 左闭右闭区间[left, right]
int binary_search_one(vector<int>& nums, int target) {
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

// 二分法第二种写法 left < right, 左开右闭区间[left, right)
int binary_search_two(vector<int>& nums, int target){
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

int main(){
	vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
	cout << "one: " << binary_search_one(arr, 0) << endl;
	cout << "two: " << binary_search_two(arr, 3) << endl;
}