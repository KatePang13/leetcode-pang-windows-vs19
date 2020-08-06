// 718-maximum-length-of-repeated-subarray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int maxLen = 0;

        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                int len = 0;
                int x = i;
                int y = j;
                while (A[x] == B[y] && x < A.size() && y < B.size()) {
                    len++;
                    x++;
                    y++;
                }
                maxLen = max(maxLen, len);
            }
        }

        return maxLen;
    }
};

int main()
{
    Solution slu;
    //[1,2,3,2,1]
    //[3, 2, 1, 4, 7]
    vector<int> A = { 1,2,3,2,1 };
    vector<int> B = { 3, 2, 1, 4, 7 };
    int res = slu.findLength(A, B);
    cout << res << "\n";
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
