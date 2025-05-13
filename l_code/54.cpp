//给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
//
//
//示例 1：
//输入：matrix = [
// [1,2,3],
// [4,5,6],
// [7,8,9]]
//输出：[1,2,3,6,9,8,7,4,5]
//
//输入：matrix = [
// [1,2,3,4],
// [5,6,7,8],
// [9,10,11,12]]
//输出：[1,2,3,4,8,12,11,10,9,5,6,7]

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    if(matrix.size() == 0 || matrix[0].size() == 0)
      return {};
    int left = 0, right = matrix[0].size() - 1;
    int top = 0, bottom = matrix.size() - 1;

    while(left <= right && top <= bottom){
      for(int i = left; i <= right; i++){
        result.push_back(matrix[top][i]);
      }
      top++;

      for(int i = top; i <= bottom; i++){
        result.push_back(matrix[i][right]);
      }
      right--;

      if (top <= bottom) {
        for(int i = right; i >= left; i--){
          result.push_back(matrix[bottom][i]);
        }
        bottom--;
      }

      if (left <= right) {
        for(int i = bottom; i >= top; i--){
          result.push_back(matrix[i][left]);
        }
        left++;
      }

    }

    return result;
  }
};

// 测试用例
void test() {
  Solution s;

  vector<vector<int>> matrix1 = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };
  vector<int> result1 = s.spiralOrder(matrix1);
  cout << "Test Case 1: ";
  for (int num : result1) cout << num << " ";
  cout << endl;

  vector<vector<int>> matrix2 = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
  };
  vector<int> result2 = s.spiralOrder(matrix2);
  cout << "Test Case 2: ";
  for (int num : result2) cout << num << " ";
  cout << endl;
}

int main() {
  test();
  return 0;
}
