//字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。
// 比如，字符串aabcccccaaa会变为a2b1c5a3。
// 若“压缩”后的字符串没有变短，则返回原先的字符串。你可以假设字符串中只包含大小写英文字母（a至z）。
//
//示例 1：
//
//输入："aabcccccaaa"
//输出："a2b1c5a3"
//示例 2：
//
//输入："abbccd"
//输出："abbccd"
//解释："abbccd"压缩后为"a1b2c2d1"，比原字符串长度更长。
//提示：
//
//字符串长度在 [0, 50000] 范围内。

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  string compressString(string S) {
    if(S.empty()) return S;

    string res;
    int count = 1;
    for(int i = 1; i < S.size(); i++){
      if(S[i - 1] == S[i]){
        count++;
      }else{
        res += S[i - 1] + to_string(count);
        count = 1;
      }
    }

    res += S.back() + to_string(count);


    return res.size() >= S.size() ? S : res;

  }

};
int main() {
  Solution sol;
  cout << sol.compressString("aabcccccaaa") << endl; // 输出 a2b1c5a3
  cout << sol.compressString("abbccd") << endl;      // 输出 abbccd
  cout << sol.compressString("a") << endl;           // 输出 a
  cout << sol.compressString("") << endl;            // 输出 （空字符串）
  cout << sol.compressString("abc") << endl;         // 输出 abc
  cout << sol.compressString("aaabbbccc") << endl;   // 输出 a3b3c3
  return 0;
}