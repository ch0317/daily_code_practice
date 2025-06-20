//编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零。
//
//
//
//示例 1：
//
//输入：
//[
//  [1,1,1],
//  [1,0,1],
//  [1,1,1]
//]
//输出：
//[
//  [1,0,1],
//  [0,0,0],
//  [1,0,1]
//]
//示例 2：
//
//输入：
//[
//  [0,1,2,0],
//  [3,4,5,2],
//  [1,3,1,5]
//]
//输出：
//[
//  [0,0,0,0],
//  [0,4,5,0],
//  [0,3,1,0]
//]

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix) {
	int row_num = matrix.size();
    int col_num = matrix[0].size();

	bool first_row_has_zero = false;
	bool first_col_has_zero = false;

    // 判断第一列是否需要清零
    for (int i = 0; i < row_num; ++i) {
        if (matrix[i][0] == 0) {
            first_col_has_zero = true;
            break;
        }
    }

    // 先判断第一行是否需要清零
    for (int j = 0; j < col_num; ++j) {
        if (matrix[0][j] == 0) {
            first_row_has_zero = true;
            break;
        }
    }

    for(int i = 1; i < row_num; i++){
      for(int j = 1; j < col_num; j++){
        if(matrix[i][j] == 0){
          matrix[0][j] = 0;
          matrix[i][0] = 0;
        }
      }
    }

    for(int i = 1; i < row_num; i++){
		for(int j = 1; j < col_num; j++){
           if(matrix[i][0] == 0 || matrix[0][j] == 0){
             matrix[i][j] = 0;
           }
		}
    }

    if(first_row_has_zero){
      for(int j = 0; j < col_num; j++){
        matrix[0][j] = 0;
      }
    }

     if(first_col_has_zero){
      for(int i = 0; i < row_num; i++){
        matrix[i][0] = 0;
      }
    }
  }
};


// 用于比较矩阵是否一致
bool matrixEqual(const vector<vector<int>>& a, const vector<vector<int>>& b) {
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

void test() {
    Solution sol;

    {
        vector<vector<int>> input = {
            {1, 1, 1},
            {1, 0, 1},
            {1, 1, 1}
        };
        vector<vector<int>> expected = {
            {1, 0, 1},
            {0, 0, 0},
            {1, 0, 1}
        };
        sol.setZeroes(input);
        assert(matrixEqual(input, expected));
    }

    {
        vector<vector<int>> input = {
            {0, 1, 2, 0},
            {3, 4, 5, 2},
            {1, 3, 1, 5}
        };
        vector<vector<int>> expected = {
            {0, 0, 0, 0},
            {0, 4, 5, 0},
            {0, 3, 1, 0}
        };
        sol.setZeroes(input);
        assert(matrixEqual(input, expected));
    }

    {
        vector<vector<int>> input = {
            {1, 2},
            {3, 4}
        };
        vector<vector<int>> expected = {
            {1, 2},
            {3, 4}
        };
        sol.setZeroes(input);
        assert(matrixEqual(input, expected));
    }

    {
        vector<vector<int>> input = {
            {0, 0},
            {0, 0}
        };
        vector<vector<int>> expected = {
            {0, 0},
            {0, 0}
        };
        sol.setZeroes(input);
        assert(matrixEqual(input, expected));
    }

    {
        vector<vector<int>> input = {
            {1, 0},
            {1, 1}
        };
        vector<vector<int>> expected = {
            {0, 0},
            {1, 0}
        };
        sol.setZeroes(input);
        assert(matrixEqual(input, expected));
    }

    cout << "All test cases passed!" << endl;
}

int main() {
    test();
    return 0;
}