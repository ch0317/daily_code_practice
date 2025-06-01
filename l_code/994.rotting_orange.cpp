//在给定的 m x n 网格 grid 中，每个单元格可以有以下三个值之一：
//
//值 0 代表空单元格；
//值 1 代表新鲜橘子；
//值 2 代表腐烂的橘子。
//每分钟，腐烂的橘子 周围 4 个方向上相邻 的新鲜橘子都会腐烂。
//
//返回 直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1 。
//
//
//
//示例 1：
//输入：grid =
// [[2,1,1],
// [1,1,0],
// [0,1,1]]
//输出：4
//示例 2：
//
//输入：grid =
// [[2,1,1],
// [0,1,1],
// [1,0,1]]
//输出：-1
//解释：左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4 个方向上。
//示例 3：
//
//输入：grid = [[0,2]]
//输出：0
//解释：因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
  int orangesRotting(vector<vector<int>>& grid) {
    queue<pair<int,int>> rot_queue;
    int fresh = 0;
    int row_num = grid.size();
    int col_num = grid[0].size();

    for (int i = 0; i < row_num; i++) {
      for (int j = 0; j < col_num; j++) {
        if (grid[i][j] == 2) {
          rot_queue.push({i,j});
        }else if (grid[i][j] == 1) {
          fresh++;
        }
      }
    }

    if (fresh == 0) return 0;

    int answer = -1;
    vector<pair<int,int>> direction = {{0,1},{0, -1}, {1,0}, {-1, 0}};

    while (!rot_queue.empty()) {
      int sz = rot_queue.size();
      answer++;
      for (int i = 0; i < sz; i++) {
        auto r = rot_queue.front();

        rot_queue.pop();
        for (auto [x,y] : direction) {
          int xd = r.first + x;
          int yd = r.second + y;
          if (xd < row_num && yd < col_num && xd >= 0 && yd >= 0 && grid[xd][yd] == 1) {
            fresh--;
            grid[xd][yd] = 2;
            rot_queue.push({xd, yd});
          }
        }
      }

    }

    return fresh == 0 ? answer : -1;

  }
};


int main() {
  Solution sol;

  vector<vector<int>> grid1 = {{2,1,1},{1,1,0},{0,1,1}};
  cout << "Test 1: " << sol.orangesRotting(grid1) << endl;  // 输出 4

  vector<vector<int>> grid2 = {{2,1,1},{0,1,1},{1,0,1}};
  cout << "Test 2: " << sol.orangesRotting(grid2) << endl;  // 输出 -1

  vector<vector<int>> grid3 = {{0,2}};
  cout << "Test 3: " << sol.orangesRotting(grid3) << endl;  // 输出 0

  return 0;
}