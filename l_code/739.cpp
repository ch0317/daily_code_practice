// 给定一个整数数组 temperatures ，表示每天的温度，
// 返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，
// 下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。
//
// 示例 1:
//
//输入: temperatures = [73,74,75,71,69,72,76,73]
//输出: [1,1,4,2,1,1,0,0]
//示例 2:
//
//输入: temperatures = [30,40,50,60]
//输出: [1,1,1,0]
//示例 3:
//
//输入: temperatures = [30,60,90]
//输出: [1,1,0]


#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> answer(n,0);
    stack<int> stk;

    for(int i = 0; i < n; i++){
      while(!stk.empty() && temperatures[i] > temperatures[stk.top()]){
        int index = stk.top();
        answer[index] = i - index;
        stk.pop();
      }

      stk.push(i);
    }

    return answer;
  }
};

// 测试代码
int main() {
  Solution sol;
  vector<vector<int>> testCases = {
    {73, 74, 75, 71, 69, 72, 76, 73},
    {30, 40, 50, 60},
    {30, 60, 90},
    {90, 80, 70, 60}  // 额外测试：气温持续下降，全部输出 0
  };

  for (auto& testCase : testCases) {
    vector<int> result = sol.dailyTemperatures(testCase);
    for (int x : result) {
      cout << x << " ";
    }
    cout << endl;
  }

  return 0;
}
