// 5477-minimum-swaps-to-arrange-a-binary-grid.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> suffixZeros(n);
        int swapStep = 0;

        for (int i = 0; i < n; i++) {
            int suffixZero = 0;
            for( int j=n-1; j>=0; j--) {
                if (grid[i][j] != 0) {
                    break;
                }
                suffixZero++;
            }
            suffixZeros[i] = suffixZero;
        }

        for (int i = 0; i < n - 1; i++) {
            int j = i;
            int targetSuffixZeros = n - i - 1;

            //从上往下找到第一个符合i行需求的行; 
            //  找不到则无解，返回-1; 
            //  找的到，从下往上将找到的行换到 i 行，累计交换步数;
            for (; j < n; j++) {
                if (suffixZeros[j] == targetSuffixZeros) {
                    break;
                }
            }
            if (j == n) {
                return -1;
            }
            for (; j > i; j--) {
                swap(grid[j], grid[j - 1]);
                swapStep++;
            }
        }

        return swapStep;
    }
};

int main()
{
    Solution slu;
    vector<vector<int>> gird = { {0,0,1},{1,1,0},{1,0,0} };
    int ans = slu.minSwaps(gird);
    std::cout << ans << "Hello World!\n";
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
