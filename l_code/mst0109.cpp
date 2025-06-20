//字符串轮转。给定两个字符串s1和s2，请编写代码检查s2是否为s1旋转而成
// （比如，waterbottle是erbottlewat旋转后的字符串）。
//
//示例 1：
//
// 输入：s1 = "waterbottle", s2 = "erbottlewat"
// 输出：True
//示例 2：
//
// 输入：s1 = "aa", s2 = "aba"
// 输出：False
//提示：
//
//字符串长度在[0, 100000]范围内。
//说明:
//
//你能只调用一次检查子串的方法吗？


#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isFlipedString(string s1, string s2) {
		if(s1.length() != s2.length()) return false;
        string doubleS = s1 + s1;
        return doubleS.find(s2) != string::npos;
    }
};

// 测试代码
int main() {
    Solution sol;
    cout << boolalpha;

    // 示例1
    string s1 = "waterbottle", s2 = "erbottlewat";
    cout << "Test 1: " << sol.isFlipedString(s1, s2) << endl; // True

    // 示例2
    s1 = "aa", s2 = "aba";
    cout << "Test 2: " << sol.isFlipedString(s1, s2) << endl; // False

    // 边界情况
    s1 = "", s2 = "";
    cout << "Test 3: " << sol.isFlipedString(s1, s2) << endl; // True

    s1 = "a", s2 = "a";
    cout << "Test 4: " << sol.isFlipedString(s1, s2) << endl; // True

    s1 = "abcde", s2 = "deabc";
    cout << "Test 5: " << sol.isFlipedString(s1, s2) << endl; // True

    return 0;
}
