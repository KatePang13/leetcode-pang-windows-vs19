// 3sum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue; //第一个元素去重;
            }

            int l = i + 1;
            int r = n - 1;
            int target = 0 - nums[i];

            while (l < r) {
                int sum = nums[l] + nums[r];
                if (sum == target) {
                    ans.push_back({ nums[i], nums[l], nums[r] });

                    int lVal = nums[l];
                    int rVal = nums[r];

                    while (lVal == nums[l]) {
                        l++;
                    }

                    while (rVal == nums[r]) {
                        r--;
                    }
                }
                else if (sum < target) {
                    l++;
                }
                else {
                    r--;
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution slu;
    vector<int> nums = { 0, 0, 0 };
    vector<vector<int>> ans = slu.threeSum(nums);
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
