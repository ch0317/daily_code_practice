//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
//
//有效字符串需满足：
//
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//每个右括号都有一个对应的相同类型的左括号。
//
//
//示例 1：
//
//输入：s = "()"
//
//输出：true
//
//示例 2：
//
//输入：s = "()[]{}"
//
//输出：true
//
//示例 3：
//
//输入：s = "(]"
//
//输出：false
//
//示例 4：
//
//输入：s = "([])"
//
//输出：true


#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
      unordered_map<char,char> mp ={
        {'}','{'},
        {']','['},
        {')','('}
      };
      stack<char> st;

      for(char c : s){
        if(mp.count(c)){
          if(st.empty()) return false;
          char t = st.top();
          st.pop();
          if(mp[c] != t) return false;
        }else{
          st.push(c);
        }
      }
      if (!st.empty()) return false;
      return true;

  }
};


int main() {
  Solution sol;

  cout << boolalpha;  // 打印 true/false
  cout << sol.isValid("()") << endl;        // true
  cout << sol.isValid("()[]{}") << endl;    // true
  cout << sol.isValid("(]") << endl;        // false
  cout << sol.isValid("([])") << endl;      // true
  cout << sol.isValid("([)]") << endl;      // false
  cout << sol.isValid("{[()]}") << endl;    // true
  cout << sol.isValid("") << endl;          // true
  cout << sol.isValid("(") << endl;         // false
  cout << sol.isValid("]") << endl;         // false

  return 0;
}

