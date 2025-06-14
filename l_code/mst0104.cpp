//给定一个字符串，编写一个函数判定其是否为某个回文串的排列之一。
//
//回文串是指正反两个方向都一样的单词或短语。排列是指字母的重新排列。
//
//回文串不一定是字典当中的单词。
//
//
//
//示例1：
//
//输入："tactcoa"
//输出：true（排列有"tacocat"、"atcocta"，等等）


#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
  bool canPermutePalindrome(string s) {
    unordered_set<char> st;
    for(auto c : s){
      if(st.count(c)){
        st.erase(c);
      }else{
        st.insert(c);
      }
    }

    return st.size() <= 1;
  }
};
int main() {
  Solution sol;

  cout << boolalpha;

  // 示例 1
  cout << sol.canPermutePalindrome("tactcoa") << endl; // true

  // 全部偶数次 → true
  cout << sol.canPermutePalindrome("aabbcc") << endl; // true

  // 有两个奇数次 → false
  cout << sol.canPermutePalindrome("aabbc") << endl; // false

  // 单字符 → true
  cout << sol.canPermutePalindrome("a") << endl; // true

  // 空字符串 → true（认为它是回文）
  cout << sol.canPermutePalindrome("") << endl; // true

  // 全奇数次数（3个）→ false
  cout << sol.canPermutePalindrome("abc") << endl; // false

  return 0;
}
