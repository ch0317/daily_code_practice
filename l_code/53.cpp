//给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
//
//子数组是数组中的一个连续部分。
//
//
//
//示例 1：
//
//输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
//输出：6
//解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
//示例 2：
//
//输入：nums = [1]
//输出：1
//示例 3：
//
//输入：nums = [5,4,-1,7,8]
//输出：23

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int max_sum = nums[0];
        int current_max = nums[0];

        for(int i = 1; i < n; i++){
          current_max = max(nums[i], current_max + nums[i]);
          max_sum = max(max_sum, current_max);
        }

        return max_sum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << sol.maxSubArray(nums) << endl; // 输出 6
    vector<int> nums1 = {1};
    cout << sol.maxSubArray(nums1) << endl;
}