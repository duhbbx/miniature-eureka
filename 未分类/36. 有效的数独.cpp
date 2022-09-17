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
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<vector<int>> col(9, vector<int>(9));
        vector<vector<int>> row(9, vector<int>(9));
        vector<vector<vector<int>>> littleBox(3, vector<vector<int>>(3, vector<int>(9)));


        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {


                char c = board[i][j];

                if (c == '.') {
                    continue;
                }

                // cout << "c - '1'" << (int) (c - '1') << endl;


                if (row[i][c - '1'] == 1) {
                    return false;
                } else {
                    row[i][c - '1'] = 1;
                }

                if (col[j][c - '1'] == 1) {
                    return false;
                } else {
                    col[j][c - '1'] = 1;
                }

                if (littleBox[i / 3][j / 3][c - '1'] == 1) {
                    return false;
                } else {
                    littleBox[i / 3][j / 3][c - '1'] = 1;
                }


            }
        }

        return true;

    }
};


////////////////////////////////////////////////////////////////////////////////




void printCurrentFileName() {
    string file = __FILE__;
    int pos = file.find_last_of("/");
    string fileName = pos == -1 ? file : file.substr(pos+1);
    cout << "\n【当前题目为：" << fileName << "】" << endl;
}





int main() {


    printCurrentFileName();


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}