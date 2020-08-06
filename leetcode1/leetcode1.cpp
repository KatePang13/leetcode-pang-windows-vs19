// leetcode1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //8个方向的坐标偏移量：从左上角开始，顺时针.
    int dx[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
    int dy[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        vector<vector<int>> visited(board.size(), vector<int>(board[0].size()));
        int row = click[0];
        int col = click[1];
        if (!isValidPos(board, row, col)) {
            return board;
        }

        if (board[row][col] == 'M') {
            board[row][col] = 'X';
            return board;
        }

        dfs(board, visited, row, col);
        return board;
    }

    void dfs(vector<vector<char>>& board, vector<vector<int>>& visited, int row, int col) {
        visited[row][col] = 1;
        int x = 0, y = 0;

        //如果相邻有炸弹，则标记炸弹数并返回;
        int mn = findMine(board, row, col);
        if (mn > 0) {
            board[row][col] = '0' + mn;
            return;
        }

        //如果相邻没炸弹，则标记为'B'，并向周边继续扩散;
        board[row][col] = 'B';
        for (int i = 0; i < 8; i++) {
            x = row + dx[i];
            y = col + dy[i];
            if (isValidPos(board, x, y) && (!visited[x][y]) && (board[x][y] == 'E')) {
                dfs(board, visited, x, y);
            }
        }
    }

    int findMine(vector<vector<char>>& board, int row, int col) {
        int mn = 0;
        int x = 0, y = 0;
        for (int i = 0; i < 8; i++) {
            x = row + dx[i];
            y = col + dy[i];
            if (isValidPos(board, x, y) && board[x][y] == 'M') {
                mn++;
            }
        }
        return mn;
    }

    int isValidPos(vector<vector<char>>& board, int row, int col) {
        int rows = board.size();
        int cols = board[0].size();
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            return true;
        }
        else {
            return false;
        }
    }



};

int main()
{
    Solution slu;
    //[["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]]
    vector<vector<char>> input = { {'E','E','E','E','E'},{'E','E','M','E','E'}, {'E','E','E','E','E'}, {'E','E','E','E','E'} };
    vector<int> click = { 3, 0 };
    slu.updateBoard(input, click);
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
