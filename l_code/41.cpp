//给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
//
//请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
//
//
//示例 1：
//
//输入：nums = [1,2,0]
//输出：3
//解释：范围 [1,2] 中的数字都在数组中。
//示例 2：
//
//输入：nums = [3,4,-1,1]
//输出：2
//解释：1 在数组中，但 2 没有。
//示例 3：
//
//输入：nums = [7,8,9,11,12]
//输出：1
//解释：最小的正数 1 没有出现。
// 考察的是原地哈希（或称“置换到位”）思想，时间复杂度 O(n)，空间复杂度 O(1)。
#include <vector>
using namespace std;
#include <iostream>
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
            {
                swap(nums[i], nums[nums[i] - 1]);
                cout << "i: " << i << "....: ";
                for (int i = 0; i < n; i++)
                {
                    cout << nums[i] << " ";
                }
                cout << endl;
            }

        }

        for (int i = 0; i < n; i++)
        {
            cout << nums[i] << " ";
        }
        cout << endl;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i + 1)
            {
                return i + 1;
            }
        }

        return n + 1;
    }
};


int main() {
    Solution s;
    vector<int> nums1 = {1, 2, 0};
    vector<int> nums2 = {3, 4, -1, 1};
    vector<int> nums3 = {7, 8, 9, 11, 12};

    cout << "test: " << s.firstMissingPositive(nums1) << endl; // 输出 3
    cout << "test: " << s.firstMissingPositive(nums2) << endl; // 输出 2
    cout << "test: " << s.firstMissingPositive(nums3) << endl; // 输出 1

    return 0;
}
