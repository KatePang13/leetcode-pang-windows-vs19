// 632-smallest-range-covering-elements-from-k-lists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        map<int, vector<int>> freq; //< val, index of nums that include val>
        int vMax = INT_MIN;
        int vMin = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int val : nums[i]) {
                freq[val].push_back(i);
                vMax = max(vMax, val);
                vMin = min(vMin, val);
            }
        }

        vector<int> winFreq(n);
        int left = vMin;
        int right = vMin;
        int bestLeft = vMin;
        int bestRight = vMax;
        int nInclude = 0;

        while (right <= vMax) {
            if (freq.count(right) == 0) {
                right++;
                continue;
            }

            for (int i : freq[right]) {
                winFreq[i]++;
                if (winFreq[i] == 1) {
                    nInclude++;
                }
            }

            while (nInclude == n) {
                if (right - left < bestRight - bestLeft) {
                    bestLeft = left;
                    bestRight = right;
                }

                if (freq.count(left) == 0) {
                    left++;
                    continue;
                }

                for (int i : freq[left]) {
                    winFreq[i]--;
                    if (winFreq[i] == 0) {
                        nInclude--;
                    }
                }
                left++;
            }
            right++;
        }
        return { bestLeft, bestRight };
    }
};


int main()
{
    Solution slu;
    vector<vector<int>> nums = { {4,10,15,24,26},{0,9,12,20},{5,18,22,30} };
    auto ans =slu.smallestRange(nums);
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
