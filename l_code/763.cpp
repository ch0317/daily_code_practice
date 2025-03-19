// 给你一个字符串 s 。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。
// 例如，字符串 "ababcc" 能够被分为 ["abab", "cc"]，但类似 ["aba", "bcc"] 或 ["ab", "ab", "cc"] 的划分是非法的。
//
//注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是 s 。
//
//返回一个表示每个字符串片段的长度的列表。
//
//
//
//示例 1：
//输入：s = "ababcbacadefegdehijhklij"
//输出：[9,7,8]
//解释：
//划分结果为 "ababcbaca"、"defegde"、"hijhklij" 。
//每个字母最多出现在一个片段中。
//像 "ababcbacadefegde", "hijhklij" 这样的划分是错误的，因为划分的片段数较少。
//示例 2：
//
//输入：s = "eccbbbbdec"
//输出：[10]
#include <vector>
#include <string>
#include <iostream>

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> result;
        vector<int> last_index_tbl(26,0);

        for (int i = 0; i < s.length(); i++)
        {
            last_index_tbl[s[i] - 'a'] = i;
        }

        int start = 0;
        int end = 0;
        for (int i = 0; i < s.length(); i++)
        {
            end = max(end, last_index_tbl[s[i] - 'a']);
            if (i == end)
            {
                result.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return result;
    }
};

// 测试
int main() {
    Solution solution;
    string s1 = "ababcbacadefegdehijhklij";
    vector<int> result1 = solution.partitionLabels(s1);

    for (int len : result1) {
        cout << len << " ";
    }
    cout << endl;

    string s2 = "eccbbbbdec";
    vector<int> result2 = solution.partitionLabels(s2);

    for (int len : result2) {
        cout << len << " ";
    }
    cout << endl;

    return 0;
}
