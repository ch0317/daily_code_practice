//给定两个由小写字母组成的字符串 s1 和 s2，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。
//
//示例 1：
//
//输入: s1 = "abc", s2 = "bca"
//输出: true
//示例 2：
//
//输入: s1 = "abc", s2 = "bad"
//输出: false
//说明：
//
//0 <= len(s1) <= 100
//0 <= len(s2) <= 100

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool CheckPermutation(string s1, string s2) {
    if(s1.length() != s2.length())
      return false;

    int count[26] = {0};
    for(char c : s1){
      count[c - 'a']++;
    }

    for(char c: s2){
      count[c - 'a']--;
      if(count[c - 'a'] < 0)
        return false;
    }

    return true;
  }
};


int main() {
  Solution solution;

  string s1 = "abc", s2 = "bca";
  cout << boolalpha << solution.CheckPermutation(s1, s2) << endl; // true

  s1 = "abc"; s2 = "bad";
  cout << boolalpha << solution.CheckPermutation(s1, s2) << endl; // false

  s1 = ""; s2 = "";
  cout << boolalpha << solution.CheckPermutation(s1, s2) << endl; // true

  s1 = "aabbcc"; s2 = "abcabc";
  cout << boolalpha << solution.CheckPermutation(s1, s2) << endl; // true

  s1 = "abcd"; s2 = "abce";
  cout << boolalpha << solution.CheckPermutation(s1, s2) << endl; // false

  return 0;
}
