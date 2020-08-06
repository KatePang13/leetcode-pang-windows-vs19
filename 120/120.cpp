// 120.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int ans = INT_MAX;
        int n = triangle.size();
        if (n == 0) {
            return 0;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0) {
                    triangle[i][j] += triangle[i - 1][j];
                }
                else if (j == i) {
                    triangle[i][j] += triangle[i - 1][j - 1];
                }
                else {
                    triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
                }
                cout << triangle[i][j] << ",";
            }
            cout << endl;
        }

        for (int j = 0; j < n; j++) {
            ans = min(ans, triangle[3][j]);
        }

        return ans;
    }
};

int main()
{
    Solution slu;
    vector<vector<int>> triangle = { {2},{3,4},{6,5,7},{4,1,8,3} };
    cout<<slu.minimumTotal(triangle) <<endl;
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
