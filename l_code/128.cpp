//给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
//
//请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
//
//
//
//示例 1：
//
//输入：nums = [100,4,200,1,3,2]
//输出：4
//解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
//示例 2：
//
//输入：nums = [0,3,7,2,5,8,4,6,0,1]
//输出：9
//示例 3：
//
//输入：nums = [1,0,1,2]
//输出：3

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    if(nums.size() == 0) return 0;
    unordered_set<int> numSet(nums.begin(), nums.end());
    int result = 0;
    for(int num : numSet){
      if(!numSet.count(num - 1)){
        int currentStreak = 1;

        while(numSet.count(num + 1)){
          currentStreak++;
          num++;
        }

        result = max(result, currentStreak);
      }
    }

    return result;
  }
};

// 测试代码
int main() {
  Solution solution;
  vector<vector<int>> testCases = {
    {100, 4, 200, 1, 3, 2},
    {0, 3, 7, 2, 5, 8, 4, 6, 0, 1},
    {1, 0, 1, 2},
    {},
    {10},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
  };
  vector<int> expectedResults = {4, 9, 3, 0, 1, 10};

  for (size_t i = 0; i < testCases.size(); ++i) {
    int result = solution.longestConsecutive(testCases[i]);
    cout << "Test case " << i + 1 << ": Expected = " << expectedResults[i]
         << ", Got = " << result << (result == expectedResults[i] ? " [PASS]" : " [FAIL]") << endl;
  }

  return 0;
}