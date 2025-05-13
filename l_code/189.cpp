//给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
//
//
//
//示例 1:
//
//输入: nums = [1,2,3,4,5,6,7], k = 3
//输出: [5,6,7,1,2,3,4]
//解释:
//向右轮转 1 步: [7,1,2,3,4,5,6]
//向右轮转 2 步: [6,7,1,2,3,4,5]
//向右轮转 3 步: [5,6,7,1,2,3,4]
//示例 2:
//
//输入：nums = [-1,-100,3,99], k = 2
//输出：[3,99,-1,-100]
//解释:
//向右轮转 1 步: [99,-1,-100,3]
//向右轮转 2 步: [3,99,-1,-100]

#include <iostream>
#include <vector>
#include <algorithm>  // for reverse
using namespace std;

class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
  }
};

int main() {
  Solution sol;

  vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
  int k1 = 3;
  sol.rotate(nums1, k1);
  cout << "Test 1 Result: ";
  for (int num : nums1) {
    cout << num << " ";
  }
  cout << endl;

  vector<int> nums2 = {-1, -100, 3, 99};
  int k2 = 2;
  sol.rotate(nums2, k2);
  cout << "Test 2 Result: ";
  for (int num : nums2) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
