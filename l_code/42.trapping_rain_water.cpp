//给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
//
//
//
//示例 1：
//
//
//
//输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
//输出：6
//解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
//示例 2：
//
//输入：height = [4,2,0,3,2,5]
//输出：9

#include <iostream>
#include <vector>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int trap(vector<int>& height) {
    int n = height.size();
    vector<int> left_max(n);
    vector<int> right_max(n);
    int result = 0;

    left_max[0] = height[0];
    for(int i = 1; i < n; i++){
      left_max[i] = max(left_max[i - 1], height[i]);

    }

    right_max[n - 1] = height[n - 1];
    for(int i = n - 2; i >= 0; i--){
      right_max[i] = max(right_max[i + 1], height[i]);
    }

    for(int i = 0; i < n; i++){
      result += min(left_max[i], right_max[i]) - height[i];
    }

    return result;
  }
};

int main() {
  Solution solution;
  vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << solution.trap(height) << endl;  // 输出 6
  return 0;
}



