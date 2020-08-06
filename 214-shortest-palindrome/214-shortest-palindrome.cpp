// 214-shortest-palindrome.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        if (n < 2) {
            return s;
        }

        int subLen = 0;
        int maxLen = 0;
        int begin = 0;
        int end = 0;
        vector<vector<int>> dp(n, vector<int>(n));

        for (int delta = 0; delta < n; delta++) {
            for (int i = 0; i < n - delta; i++) {
                int j = i + delta;
                subLen = delta + 1;

                if (0 == delta) {
                    dp[i][j] = 1;
                }
                else if (1 == delta) {
                    dp[i][j] = (s[i] == s[j]);
                }
                else {
                    dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
                }

                if (subLen > maxLen && dp[i][j]) {
                    maxLen = subLen;
                    begin = i;
                    end = j;
                }

            }
        }

        string prefix = s.substr(end + 1, -1);
        reverse(prefix.begin(), prefix.end());
        return (prefix + s);
    }
};
int main()
{
    Solution slu;
    string s = "aacecaaa";
    string ans = slu.shortestPalindrome(s);
    std::cout << ans << endl;
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
