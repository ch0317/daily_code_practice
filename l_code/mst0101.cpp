//实现一个算法，确定一个字符串 s 的所有字符是否全都不同。
//
//示例 1：
//
//输入: s = "leetcode"
//输出: false
//示例 2：
//
//输入: s = "abc"
//输出: true
//限制：
//
//0 <= len(s) <= 100
//s[i]仅包含小写字母
//如果你不使用额外的数据结构，会很加分。


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool isUnique(string astr) {
    int mark = 0;
    for(auto c : astr){
      int d = c - 'a';
      if(mark &( 1 << d)){
        return false;
      }
      mark |= (1 << d);
    }
    return true;
  }
};

// 测试函数
int main() {
  Solution sol;
  vector<string> tests = {"leetcode", "abc", "", "a", "abab", "abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyza"};
  for (const auto& s : tests) {
    cout << "输入: \"" << s << "\"\t输出: " << (sol.isUnique(s) ? "true" : "false") << endl;
  }
  return 0;
}
