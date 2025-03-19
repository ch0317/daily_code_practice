//给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
//
//
//
//示例 1:
//
//输入: s = "cbaebabacd", p = "abc"
//输出: [0,6]
//解释:
//起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
//起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
// 示例 2:
//
//输入: s = "abab", p = "ab"
//输出: [0,1,2]
//解释:
//起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
//起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
//起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> sCount(26, 0);
        vector<int> pCount(26, 0);
        vector<int> result;

        for (const char c: p)
        {
            pCount[c - 'a']++;
        }

        for (int i = 0; i < s.size(); i++)
        {
            sCount[s[i] - 'a']++;

            if (i >= p.size())
            {
                sCount[s[i - p.size()] - 'a']--;
            }

            if (sCount == pCount) result.push_back(i - p.size() + 1);
        }

        return result;
    }
};

// 辅助函数：打印 vector
void printVector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i < v.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// 测试函数
void test() {
    Solution solution;

    // 测试用例 1
    string s1 = "cbaebabacd";
    string p1 = "abc";
    vector<int> expected1 = {0, 6};
    vector<int> result1 = solution.findAnagrams(s1, p1);
    printVector(result1);
    assert(result1 == expected1);

    // 测试用例 2
    string s2 = "abab";
    string p2 = "ab";
    vector<int> expected2 = {0, 1, 2};
    vector<int> result2 = solution.findAnagrams(s2, p2);
    printVector(result2);
    assert(result2 == expected2);

    cout << "所有测试通过！" << endl;
}

int main() {
    test();
    return 0;
}
