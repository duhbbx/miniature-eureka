//
// Created by duhbb on 2022/9/15.
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
#include <set>

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
    int flipLights(int n, int presses) {

        if (n == 1) {
            if (presses == 0) {
                return 1;
            } else {
                return 2;
            }
        }

        if (n == 2) {
            if (presses == 0) {
                return 1;
            } else if (presses == 1) {
                return 3;
            } else {
                return 4;
            }
        }


        if (presses > 3) {
            presses = 3;
        }


        set<unsigned int> res;
        int current_presses = 0;
        unsigned int current_state = 7;
        backtrack(res, current_presses, presses, current_state);



        return res.size();
    }

    void backtrack(set<unsigned int>& res, int current_presses, int presses, unsigned int current_state) {

        if (current_presses == presses) {
            res.insert(current_state);
            return;
        }

        // 操作1 全部取反
        backtrack(res, current_presses + 1, presses, operate0(current_state));

        // 操作2 奇数位取反
        backtrack(res, current_presses + 1, presses, operate1(current_state));

        // 操作2 偶数位取反
        backtrack(res, current_presses + 1, presses, operate2(current_state));

        // 操作3 3k+1位取反
        backtrack(res, current_presses + 1, presses, operate3(current_state));

    }


    unsigned int operate0(unsigned int state) {
        switch (state) {
            case 0:
                return 7;
            case 1:
                return 6;
            case 2:
                return 5;
            case 3:
                return 4;
            case 4:
                return 3;
            case 5:
                return 2;
            case 6:
                return 1;
            case 7:
                return 0;
        }

        return 0;
    }


    unsigned int operate1(unsigned int state) {
        switch (state) {
            case 0:
                return 5;
            case 1:
                return 4;
            case 2:
                return 2;
            case 3:
                return 2;
            case 4:
                return 5;
            case 5:
                return 0;
            case 6:
                return 3;
            case 7:
                return 2;
        }

        return 0;
    }

    unsigned int operate2(unsigned int state) {
        switch (state) {
            case 0:
                return 2;
            case 1:
                return 3;
            case 2:
                return 0;
            case 3:
                return 1;
            case 4:
                return 6;
            case 5:
                return 7;
            case 6:
                return 4;
            case 7:
                return 5;
        }

        return 0;
    }
    unsigned int operate3(unsigned int state) {
        switch (state) {
            case 0:
                return 4;
            case 1:
                return 5;
            case 2:
                return 6;
            case 3:
                return 7;
            case 4:
                return 0;
            case 5:
                return 1;
            case 6:
                return 2;
            case 7:
                return 3;
        }

        return 0;
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

    solution.flipLights(3, 1);


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}