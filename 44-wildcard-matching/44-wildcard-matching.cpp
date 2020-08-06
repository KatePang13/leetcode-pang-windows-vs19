// 44-wildcard-matching.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (j == 0) {
                    dp[i][j] = (i == 0);
                    continue;
                }
                if (p[j - i] != '*') {
                    if ((i > 0) && (s[i - 1] == p[j - 1] || p[j - 1] == '?')) {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
                else {
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
                    if (i > 0) {
                        dp[i][j] == dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }

        return dp[m][n];
    }
};

int main()
{
    Solution slu;
    cout << slu.isMatch("aa", "a") << endl;
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
