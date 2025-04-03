//给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。
//
//题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。
//
//请 不要使用除法，且在 O(n) 时间复杂度内完成此题。
//
//
//
//示例 1:
//
//输入: nums = [1,2,3,4]
//输出: [24,12,8,6]
//示例 2:
//
//输入: nums = [-1,1,0,-3,3]
//输出: [0,0,9,0,0]
//
//
//提示：
//
//2 <= nums.length <= 105
//-30 <= nums[i] <= 30
//输入 保证 数组 answer[i] 在  32 位 整数范围内
//
//
//进阶：你可以在 O(1) 的额外空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组 不被视为 额外空间。）

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n,1);
        // 1 2 3 4
        //
        unsigned u = 4294967295u;
        int tu = (int)u;
        cout << "u:" << u << " tu:" << tu << endl;
        for(int i = 1; i < n; i++){
            answer[i] = answer[i - 1] * nums[i - 1];
            //cout << i << " : " << answer[i] << endl;
        }

        int suffix = 1;
        cout << "suffix:" << endl;
        for(int i = n - 2; i >= 0; i--){
          //cout << i << " : " << suffix << endl;
          suffix *= nums[i + 1];
          answer[i] = suffix * answer[i];

        }

        return answer;
    }
};

// 测试函数
void runTest(vector<int> nums, vector<int> expected) {
    Solution sol;
    vector<int> result = sol.productExceptSelf(nums);

    cout << "输入:  ";
    for (int num : nums) cout << num << " ";
    cout << "\n输出:  ";
    for (int num : result) cout << num << " ";
    cout << "\n期望:  ";
    for (int num : expected) cout << num << " ";
    cout << "\n" << (result == expected ? "✅ 测试通过\n" : "❌ 测试失败\n") << endl;

    assert(result == expected);  // 断言检查，确保输出正确
}

int main() {
    // 测试用例
    runTest({1, 2, 3, 4}, {24, 12, 8, 6});
    runTest({-1, 1, 0, -3, 3}, {0, 0, 9, 0, 0});
    runTest({2, 3, 4, 5}, {60, 40, 30, 24});
    runTest({-1, -2, -3, -4}, {-24, -12, -8, -6});
    runTest({5, 0, 2, 4}, {0, 40, 0, 0});
    runTest({0, 0, 0, 0}, {0, 0, 0, 0});
    runTest({10}, {1});  // 边界情况：单元素数组

    cout << "所有测试用例执行完毕！" << endl;
    return 0;
}
