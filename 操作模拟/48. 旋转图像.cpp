//
// Created by duhbb on 2022/9/13.
//
#include <iostream>              // 输入输出
#include <vector>                // 可变长度数组
#include <unordered_map>         // hashmap
#include <stack>                 // 栈
#include <string>                // 字符串
#include <queue>                 // 队列
#include <climits>               // 极限值
#include <algorithm>             // 算法相关的
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
    void rotate(vector<vector<int>>& matrix) {

        int m = matrix.size();

        for (int i = 0; i < m - 1; ++i) {
            for (int j = i + 1; j < m; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }




        for (int k = 0; k < m; ++k) {





            int i = 0;
            int j = m - 1;
            while (i < j) {
                swap(matrix[k][i], matrix[k][j]);
                ++i;
                --j;
            }


        }
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

    vector<vector<int>> max = {
            {1, 2 ,3},
            {4, 5, 6},
            {7, 8, 9}
    };
    Solution solution;

    solution.rotate(max);


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}