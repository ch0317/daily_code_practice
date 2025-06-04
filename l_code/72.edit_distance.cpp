//给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。
//
//你可以对一个单词进行如下三种操作：
//
//插入一个字符
//删除一个字符
//替换一个字符
//
//
//示例 1：
//
//输入：word1 = "horse", word2 = "ros"
//输出：3
//解释：
//horse -> rorse (将 'h' 替换为 'r')
//rorse -> rose (删除 'r')
//rose -> ros (删除 'e')
//示例 2：
//
//输入：word1 = "intention", word2 = "execution"
//输出：5
//解释：
//intention -> inention (删除 't')
//inention -> enention (将 'i' 替换为 'e')
//enention -> exention (将 'n' 替换为 'x')
//exention -> exection (将 'n' 替换为 'c')
//exection -> execution (插入 'u')

//给定两个字符串 word1 和 word2，我们定义 dp[i][j] 表示将 word1[0..i-1] 转换为 word2[0..j-1] 的最小操作数。
//
//✨转移方程：
//若 word1[i-1] == word2[j-1]，则不需要任何操作：
//
//cpp
//复制
//编辑
//dp[i][j] = dp[i-1][j-1];
//若 word1[i-1] != word2[j-1]，我们考虑三种操作：
//
//插入：dp[i][j-1] + 1
//
//删除：dp[i-1][j] + 1
//
//替换：dp[i-1][j-1] + 1
//
//所以有：
//
//cpp
//复制
//编辑
//dp[i][j] = min({dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + 1});
//✅边界初始化：
//dp[0][j] = j：从空串变成 word2[0..j-1]，需要插入 j 次。
//
//dp[i][0] = i：从 word1[0..i-1] 变成空串，需要删除 i 次。

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
  int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for(int i = 0; i <= m; i++){
      dp[i][0] = i;
    }

    for(int j = 0; j <= n; j++){
      dp[0][j] = j;
    }

    for(int i = 1; i <= m; i++){
      for(int j = 1; j <= n; j++){
        if(word1[i - 1] == word2[j - 1]){
          dp[i][j] = dp[i - 1][j - 1];
        }else{
          dp[i][j] = min(
              {dp[i - 1][j - 1] + 1,
              dp[i - 1][j] + 1,
              dp[i][j - 1] + 1}
          );
        }
      }
    }

    return dp[m][n];
  }
};


int main() {
  Solution sol;
  cout << sol.minDistance("horse", "ros") << endl;        // 输出: 3
  cout << sol.minDistance("intention", "execution") << endl;  // 输出: 5
  return 0;
}