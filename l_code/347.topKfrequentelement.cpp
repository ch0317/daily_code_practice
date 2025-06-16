//给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
//
//
//
//示例 1:
//
//输入: nums = [1,1,1,2,2,3], k = 2
//输出: [1,2]
//示例 2:
//
//输入: nums = [1], k = 1
//输出: [1]
//
//
//提示：
//
//1 <= nums.length <= 105
//k 的取值范围是 [1, 数组中不相同的元素的个数]
//题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的
//
//
//进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> freqCount;
    for(auto num : nums){
      freqCount[num]++;
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > min_heap;

    for(auto& [num, freq] : freqCount){
      min_heap.push({freq,num});
      if(min_heap.size() > k){
        min_heap.pop();
      }
    }

    vector<int> result;
    while(!min_heap.empty()){
      result.push_back(min_heap.top().second);
      min_heap.pop();
    }

    return result;

  }
};


void test() {
  Solution sol;

  vector<int> nums1 = {1, 1, 1, 2, 2, 3};
  int k1 = 2;
  vector<int> res1 = sol.topKFrequent(nums1, k1);
  cout << "Test 1 result: ";
  for (int x : res1) cout << x << " ";
  cout << endl;

  vector<int> nums2 = {1};
  int k2 = 1;
  vector<int> res2 = sol.topKFrequent(nums2, k2);
  cout << "Test 2 result: ";
  for (int x : res2) cout << x << " ";
  cout << endl;
}

int main() {
  test();
  return 0;
}
