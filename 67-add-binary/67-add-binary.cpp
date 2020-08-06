// 67-add-binary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string* pRes;
        if (a.length() >= b.length()) {
            pRes = &a;
        }
        else {
            pRes = &b;
        }
        int i = a.size()-1;
        int j = b.size()-1;
        int k = max(i, j);
        int digit = 0;

        for (; i >= 0 || j >= 0; i--, j--) {
            int aVal = i >= 0 ? a[i] -'0' : 0;
            int bVal = j >= 0 ? b[j] -'0' : 0;
            digit += aVal + bVal;
            (*pRes)[k] = digit % 2 + '0';
            digit /= 2;
            k--;
        }

        if (digit) {
            return "1" + *pRes;
        }
        return *pRes;
    }
};

int main()
{
    Solution slu;
    string res = slu.addBinary("11", "1");
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
