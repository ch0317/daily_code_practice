//URL化。编写一种方法，将字符串中的空格全部替换为%20。
// 假定该字符串尾部有足够的空间存放新增字符，并且知道字符串的“真实”长度。
// （注：用Java实现的话，请使用字符数组实现，以便直接在数组上操作。）
//
//
//
//示例 1：
//
//输入："Mr John Smith    ", 13
//输出："Mr%20John%20Smith"
//示例 2：
//
//输入："               ", 5
//输出："%20%20%20%20%20"
//
//
//提示：
//
//字符串长度在 [0, 500000] 范围内。




#include <iostream>
using namespace std;
class Solution {
public:
  string replaceSpaces(string S, int length) {
    int spaceCount = 0;
    for(int i = 0; i < length; i++){
      if(S[i] == ' '){
        spaceCount++;
      }
    }


    int newLength = length + 2 * spaceCount;

    S.resize(newLength);
    int i = length - 1;
    int j = newLength - 1;
    while(i >= 0){
      if(S[i] == ' '){
        S[j--] = '0';
        S[j--] = '2';
        S[j--] = '%';
      }else{
        S[j--] = S[i];
      }
      i--;
    }

    return S;
  }
};
int main() {
  Solution sol;

  // 示例 1
  string s1 = "Mr John Smith    ";
  cout << sol.replaceSpaces(s1, 13) << endl; // 输出: "Mr%20John%20Smith"

  // 示例 2
  string s2 = "               "; // 15 个空格
  cout << sol.replaceSpaces(s2, 5) << endl; // 输出: "%20%20%20%20%20"

  // 边界情况：无空格
  string s3 = "HelloWorld";
  cout << sol.replaceSpaces(s3, 10) << endl; // 输出: "HelloWorld"

  // 边界情况：全是空格
  string s4 = "     ";
  cout << sol.replaceSpaces(s4, 5) << endl; // 输出: "%20%20%20%20%20"

  // 边界情况：空字符串
  string s5 = "";
  cout << sol.replaceSpaces(s5, 0) << endl; // 输出: ""

  return 0;
}
