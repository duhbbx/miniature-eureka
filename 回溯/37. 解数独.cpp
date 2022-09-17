//
// Created by duhbb on 2022/9/17.
//
#include <iostream>              // 输入输出
#include <vector>                // 可变长度数组
#include <unordered_map>         // hashmap
#include <stack>                 // 栈
#include <string>                // 字符串
#include <queue>                 // 队列
#include <climits>               // 极限值
#include <algorithm>             // 算法相关的
#include <set>                   // 集合
#include "../0000 API 模板 类/TreeNode.h"
#include "../0000 API 模板 类/ListNode.h"


using namespace std;


template<typename T>
void print(T t) {


    if (t.empty()) {
        cout << "容器为空............" << endl;
        return;
    }


    for (typename T::const_iterator it = t.begin(); it != t.end() - 1; ++it) {
        cout << *it << ", ";
    }

    cout << *(t.end() - 1) << endl;
}



////////////////////////////////////////////////////////////////////////////////
/// 这里放OJ的类

class Solution {
public:
    void solveSudoku(vector<vector<char>> &board) {
        int n = board.size();
        vector<vector<int>> track;
        for (int i = n - 1; 0 <= i; --i) {
            for (int j = n - 1; 0 <= j; --j) {

                if (board[i][j] == '.') {
                    track.push_back({i, j});
                }
            }
        }

        trackback(board, track);
    }


    bool trackback(vector<vector<char>> &board, vector<vector<int>> &track) {

        if (track.size() == 0) {
            return true;
        }


        int row = track.back()[0];
        int col = track.back()[1];


        for (int i = 1; i <= 9; ++i) {

            char candidate = '0' + i;

            // 校验当前的行是否满足要求
            bool flag = true;
            for (int j = 0; j < 9; ++j) {
                if (j == col) {
                    continue;
                }
                if (board[row][j] == candidate) {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                continue;
            }

            // 校验当前列
            for (int j = 0; j < 9; ++j) {
                if (j == row) {
                    continue;
                }

                if (board[j][col] == candidate) {
                    flag = false;
                    break;
                }
            }

            if (!flag) {
                continue;
            }


            // 校验当前小格

            for (int j = (row / 3) * 3; j < (row / 3 + 1) * 3; ++j) {
                for (int k = (col / 3) * 3; k < (col / 3 + 1) * 3; ++k) {
                    if (j == row && k == col) {
                        continue;
                    }

                    if (board[j][k] == candidate) {
                        flag = false;
                        break;
                    }
                }
            }


            if (!flag) {
                continue;
            }


            board[row][col] = candidate;
            track.pop_back();


            bool result = trackback(board, track);

            if (result) {
                return true;
            } else {
                board[row][col] = '.';
                track.push_back({row, col});
            }
        }

        return false;
    }
};


////////////////////////////////////////////////////////////////////////////////




void printCurrentFileName() {
    string file = __FILE__;
    int pos = file.find_last_of("/");
    string fileName = pos == -1 ? file : file.substr(pos + 1);
    cout << "\n【当前题目为：" << fileName << "】" << endl;
}


int main() {


    printCurrentFileName();


    Solution solution;


    vector<vector<char>> board = {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    solution.solveSudoku(board);


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}