// 378-kth-smallest-element-in-a-sorted-matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int i = 0;
        int xleft = 0;
        int yleft = 1;
        int xdown = 1;
        int ydown = 0;
        int x = 0;
        int y = 0;

        for (int i = 1; i <= k; i++) {
            if (matrix[xleft][yleft] < matrix[xdown][ydown]) {
                x = xleft;
                y = yleft;
                yleft++;
                if (yleft == matrix.size()) {
                    yleft = ydown + 1;
                    xleft++;
                }
            }
            else {
                x = xdown;
                y = ydown;
                xdown++;
                if (xdown == matrix.size()) {
                    xdown = xleft + 1;
                    ydown++;
                }
            }
        }

        return matrix[x][y];
    }
};

int main()
{
    Solution slu;
    vector<vector<int>> matrix = { {1, 5, 9}, { 10, 11, 13 }, { 12, 13, 15 } };

    int res = slu.kthSmallest(matrix, 8);
    std::cout << res << "\n";
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
