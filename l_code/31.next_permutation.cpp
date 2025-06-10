//整数数组的一个 排列  就是将其所有成员以序列或线性顺序排列。
//
//例如，arr = [1,2,3] ，以下这些都可以视作 arr 的排列：[1,2,3]、[1,3,2]、[3,1,2]、[2,3,1] 。
//整数数组的 下一个排列 是指其整数的下一个字典序更大的排列。更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，
// 那么数组的 下一个排列 就是在这个有序容器中排在它后面的那个排列。如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列（即，其元素按升序排列）。
//
//例如，arr = [1,2,3] 的下一个排列是 [1,3,2] 。
//类似地，arr = [2,3,1] 的下一个排列是 [3,1,2] 。
//而 arr = [3,2,1] 的下一个排列是 [1,2,3] ，因为 [3,2,1] 不存在一个字典序更大的排列。
//给你一个整数数组 nums ，找出 nums 的下一个排列。
//
//必须 原地 修改，只允许使用额外常数空间。
//
//
//
//示例 1：
//
//输入：nums = [1,2,3]
//输出：[1,3,2]
//示例 2：
//
//输入：nums = [3,2,1]
//输出：[1,2,3]
//示例 3：
//
//输入：nums = [1,1,5]
//输出：[1,5,1]
//
//
//提示：
//
//1 <= nums.length <= 100
//0 <= nums[i] <= 100

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;

    // Step 1: Find the first decreasing element from the end
    while(i >= 0 && nums[i] >= nums[i+1]){
      i--;
    }
    // Step 2: Find the next bigger element to swap
    if(i >= 0){
      int j = n - 1;
      while(j >= 0 && nums[i] >= nums[j]){
        j--;
      }
      swap(nums[i], nums[j]);
    }
    // Step 3: Reverse the suffix starting at i + 1
    reverse(nums.begin() + i + 1, nums.end());
  }
};

void printVec(const vector<int>& nums) {
  for (int num : nums) cout << num << " ";
  cout << endl;
}

int main() {
  Solution sol;

  vector<vector<int>> tests = {
    {1, 2, 3},
    {3, 2, 1},
    {1, 1, 5},
    {1, 3, 2},
    {2, 3, 1}
  };

  for (auto& nums : tests) {
    cout << "Original: ";
    printVec(nums);
    sol.nextPermutation(nums);
    cout << "Next Permutation: ";
    printVec(nums);
    cout << "-----" << endl;
  }

  return 0;
}

