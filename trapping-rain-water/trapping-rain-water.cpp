// trapping-rain-water.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 2) {
            return 0;
        }

        int area = 0;
        stack<int> st;

        st.push(0);
        for (int i = 1; i <= n; i++) {
            while (height[i] > height[st.top()]) {
                int cur = st.top();
                st.pop();
                int l = st.top();
                int r = i;
                int h = min(height[l], height[r]) - height[cur];
                int w = r - l;
                area += h * w;
            }
            st.push(i);
        }

        return area;
    }
};

int main()
{
    Solution slu;
    vector<int> heights = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    cout << slu.trap(heights) << endl ;
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
