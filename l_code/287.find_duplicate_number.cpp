//给定一个包含 n + 1 个整数的数组 nums ，其数字都在 [1, n] 范围内（包括 1 和 n），可知至少存在一个重复的整数。
//
//假设 nums 只有 一个重复的整数 ，返回 这个重复的数 。
//
//你设计的解决方案必须 不修改 数组 nums 且只用常量级 O(1) 的额外空间。
//
//
//
//示例 1：
//
//输入：nums = [1,3,4,2,2]
//输出：2
//示例 2：
//
//输入：nums = [3,1,3,4,2]
//输出：3
//示例 3 :
//
//输入：nums = [3,3,3,3,3]
//输出：3

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int findDuplicate(vector<int>& nums) {
    int fast = nums[0];
    int slow = nums[0];

    do{
      slow = nums[slow];
      fast = nums[nums[fast]];
    }while(fast != slow);

    slow = nums[0];
    while(fast != slow){
      slow = nums[slow];
      fast = nums[fast];
    };

    return fast;
  }
};


int main() {
  Solution solution;

  vector<int> nums1 = {1, 3, 4, 2, 2};
  cout << "Duplicate in nums1: " << solution.findDuplicate(nums1) << endl;  // Output: 2

  vector<int> nums2 = {3, 1, 3, 4, 2};
  cout << "Duplicate in nums2: " << solution.findDuplicate(nums2) << endl;  // Output: 3

  vector<int> nums3 = {3, 3, 3, 3, 3};
  cout << "Duplicate in nums3: " << solution.findDuplicate(nums3) << endl;  // Output: 3

  return 0;
}
