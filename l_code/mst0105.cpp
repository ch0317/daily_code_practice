//字符串有三种编辑操作:插入一个英文字符、删除一个英文字符或者替换一个英文字符。 给定两个字符串，编写一个函数判定它们是否只需要一次(或者零次)编辑。
//
//
//
//示例 1：
//
//输入：
//first = "pale"
//second = "ple"
//输出：True
//
//
//示例 2：
//
//输入：
//first = "pales"
//second = "pal"
//输出：False

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  bool oneEditAway(string first, string second) {
    int len1 = first.length();
    int len2 = second.length();

    if(abs(len1 - len2) > 1) return false;
    string *longer = nullptr;
    string *shorter = nullptr;
    if(len2 > len1){
      longer = &second;
      shorter = &first;
    }else{
      longer = &first;
      shorter = &second;
    }

    int i = 0,j = 0;
    bool findDifference = false;
    while(i < longer->size() && j < shorter->size()){
      if((*longer)[i] != (*shorter)[j]){
        if(findDifference) {
          return false;
        }
        findDifference = true;

        if(len1 == len2){
          i++;
          j++;

        }else{
          i++;
        }

      }else{
        i++;
        j++;
      }
    }
    return true;
  }
};


int main() {
  Solution sol;
  cout << boolalpha;

  cout << sol.oneEditAway("pale", "ple") << endl;    // True
  cout << sol.oneEditAway("pales", "pal") << endl;   // False
  cout << sol.oneEditAway("pale", "bale") << endl;   // True (replace p -> b)
  cout << sol.oneEditAway("pale", "pales") << endl;  // True (insert s)
  cout << sol.oneEditAway("pale", "bake") << endl;   // False (replace p -> b, l -> k)
  cout << sol.oneEditAway("", "") << endl;           // True
  cout << sol.oneEditAway("a", "") << endl;          // True
  cout << sol.oneEditAway("abc", "ab") << endl;      // True
  cout << sol.oneEditAway("mart", "karma") << endl;    // True

  return 0;
}
