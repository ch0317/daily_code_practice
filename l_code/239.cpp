//给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
//
//返回 滑动窗口中的最大值 。
//
//
//
//示例 1：
//
//输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
//输出：[3,3,5,5,6,7]
//解释：
//滑动窗口的位置                最大值
//---------------               -----
//[1  3  -1] -3  5  3  6  7       3
// 1 [3  -1  -3] 5  3  6  7       3
// 1  3 [-1  -3  5] 3  6  7       5
// 1  3  -1 [-3  5  3] 6  7       5
// 1  3  -1  -3 [5  3  6] 7       6
// 1  3  -1  -3  5 [3  6  7]      7
//示例 2：
//
//输入：nums = [1], k = 1
//输出：[1]

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!dq.empty() && dq[0] <= i - k)
            {
                dq.pop_front();
            }

            while (!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }

            dq.push_back(i);

            if (!dq.empty() && i >= k - 1)
            {
                result.push_back(nums[dq[0]]);
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = s.maxSlidingWindow(nums, k);// 输出: [3,3,5,5,6,7]

    cout << "滑动窗口最大值结果: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
