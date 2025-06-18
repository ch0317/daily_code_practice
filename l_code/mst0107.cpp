// 给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。
// 请你设计一种算法，将图像旋转 90 度。
//
//不占用额外内存空间能否做到？
//
//
//
//示例 1：
//
//给定 matrix =
//[
//  [1,2,3],
//  [4,5,6],
//  [7,8,9]
//],
//
//原地旋转输入矩阵，使其变为:
//[
//  [7,4,1],
//  [8,5,2],
//  [9,6,3]
//]
//示例 2：
//
//给定 matrix =
//[
//  [ 5, 1, 9,11],
//  [ 2, 4, 8,10],
//  [13, 3, 6, 7],
//  [15,14,12,16]
//],
//
//原地旋转输入矩阵，使其变为:
//[
//  [15,13, 2, 5],
//  [14, 3, 4, 1],
//  [12, 6, 8, 9],
//  [16, 7,10,11]
//]

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>>& matrix) {
    //Transpose, then reverse each row.

    // 1.转置
    int row_num = matrix.size();
    int col_num = matrix[0].size();
    for(int i = 0; i < row_num; i++){
      for(int j = i + 1; j < col_num; j++){
        swap(matrix[i][j], matrix[j][i]);
      }
    }
    // 2.行反转

    for(int i = 0; i < row_num; i++){
      reverse(matrix[i].begin(), matrix[i].end());
    }

  }
};

// 打印矩阵的工具函数
void printMatrix(const vector<vector<int>>& matrix) {
  for (const auto& row : matrix) {
    for (int val : row) {
      cout << val << " ";
    }
    cout << endl;
  }
}

int main() {
  Solution sol;

  vector<vector<int>> matrix1 = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };
  sol.rotate(matrix1);
  cout << "Rotated Matrix 1:" << endl;
  printMatrix(matrix1);

  vector<vector<int>> matrix2 = {
    {5, 1, 9, 11},
    {2, 4, 8, 10},
    {13, 3, 6, 7},
    {15, 14, 12, 16}
  };
  sol.rotate(matrix2);
  cout << "Rotated Matrix 2:" << endl;
  printMatrix(matrix2);

  return 0;
}