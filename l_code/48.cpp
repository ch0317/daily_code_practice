//给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
//
//你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。
//输入：matrix = [
// [1,2,3],
// [4,5,6],
// [7,8,9]]

//matrix = [
// [1,4,7],
// [2,5,8],
// [3,6,9]]

//输出：[
// [7,4,1],
// [8,5,2],
// [9,6,3]]

//输入：matrix = [
// [5,1,9,11],
// [2,4,8,10],
// [13,3,6,7],
// [15,14,12,16]]
//输出：[
// [15,13,2,5],
// [14,3,4,1],
// [12,6,8,9],
// [16,7,10,11]]

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for(int i = 0; i < n; i++){
      for(int j = i + 1; j < n; j++){
        swap(matrix[i][j], matrix[j][i]);
      }
    }

    for(int i = 0; i < n; i++){
      std::reverse(matrix[i].begin(), matrix[i].end());
    }
  }
};

// 工具函数：打印矩阵
void printMatrix(const vector<vector<int>>& matrix) {
  for (const auto& row : matrix) {
    for (int num : row) {
      cout << num << " ";
    }
    cout << endl;
  }
  cout << "------------------" << endl;
}

// 测试用例
void test() {
  Solution s;

  vector<vector<int>> matrix1 = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };
  cout << "Test Case 1 - Before:" << endl;
  printMatrix(matrix1);
  s.rotate(matrix1);
  cout << "Test Case 1 - After:" << endl;
  printMatrix(matrix1);

  vector<vector<int>> matrix2 = {
    {5, 1, 9, 11},
    {2, 4, 8, 10},
    {13, 3, 6, 7},
    {15, 14, 12, 16}
  };
  cout << "Test Case 2 - Before:" << endl;
  printMatrix(matrix2);
  s.rotate(matrix2);
  cout << "Test Case 2 - After:" << endl;
  printMatrix(matrix2);

  // 边界测试：1x1矩阵
  vector<vector<int>> matrix3 = {
    {42}
  };
  cout << "Test Case 3 - Before:" << endl;
  printMatrix(matrix3);
  s.rotate(matrix3);
  cout << "Test Case 3 - After:" << endl;
  printMatrix(matrix3);

  // 边界测试：2x2矩阵
  vector<vector<int>> matrix4 = {
    {1, 2},
    {3, 4}
  };
  cout << "Test Case 4 - Before:" << endl;
  printMatrix(matrix4);
  s.rotate(matrix4);
  cout << "Test Case 4 - After:" << endl;
  printMatrix(matrix4);
}

int main() {
  test();
  return 0;
}
