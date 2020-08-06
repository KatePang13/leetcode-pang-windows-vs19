// 1095-find-in-mountain-array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
  */
class MountainArray {
private:
    vector<int> mArray;
    int mN;
public:


    MountainArray(vector<int> nums) : mArray(nums) {
        mN = nums.size();
    }

    int get(int index) {
        if ( index < 0 || index >= mN) {
            cout << "index overrange:" << index << endl;
        }
        return mArray[index];
    }

    int length() {
        return mN;
    }
 };


class Solution {
public:
    int findInMountainArray(int target, MountainArray& mountainArr) {
        //先找到封顶下标;
        //左半部分二分查找，如果没有找到target,再右半部分二分查找
        //两边都未找到 -1;
        int n = mountainArr.length();
        int peakIdx = getPeakIndex(mountainArr);
        int ans = -1;
        if (peakIdx == -1) {
            return -1;
        }
        if (target == mountainArr.get(peakIdx)) {
            return peakIdx;
        }
        ans = search(mountainArr, target, 0, peakIdx - 1, true);
        if (ans == -1) {
            ans = search(mountainArr, target, peakIdx + 1, n - 1, false);
        }
        return ans;
    }

    int getPeakIndex(MountainArray& mountainArr) {
        int n = mountainArr.length();
        int l = 1;
        int r = n - 2;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if ( mountainArr.get(mid) > mountainArr.get(mid - 1) && mountainArr.get(mid) > mountainArr.get(mid + 1)) {
                return mid;
            }
            else if (mountainArr.get(mid) > mountainArr.get(mid - 1)) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return -1;
    }

    int search(MountainArray& mountainArr, int target, int l, int r, bool up) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (mountainArr.get(mid) == target) {
                return mid;
            }
            if (up) {
                if (mountainArr.get(mid) < target) {
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            else {
                if (mountainArr.get(mid) < target) {
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
        }
        return -1;
    }
};

int main()
{
    MountainArray Array({ 3,5,3,2,0});
    Solution slu;
    int ans = slu.findInMountainArray(0, Array);

    std::cout << "findInMountainArray:" << ans << endl;
}
