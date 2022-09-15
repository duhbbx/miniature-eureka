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

    vector<int> getNext(const string &needle) {

        int n = needle.length();
        vector<int> next(n, 0);


        // [0, i] 就是当前要判断的字符串的长度
        for (int i = 1; i < n; ++i) {
            cout << "当前判断的字符串为: " << needle.substr(0, i + 1) << endl;

            for (int j = 1; j <= i; ++j) {
                int tmp = 0;
                cout << "前缀: " << needle.substr(0, j) << ", 后缀：" << needle.substr(i + 1 - j, j) << endl;

                for (int k = 0; k < j; ++k) {
                    if (needle[k] == needle[i + 1 - j + k]) {
                        tmp++;
                    } else {
                        break;
                    }
                }

                if (tmp > next[i]) {
                    next[i] = tmp;
                }

            }

        }


        print(next);

        return next;
    }

    int strStr(string haystack, string needle) {

        if (needle.length() == 0) return -1;


        return -1;
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

    solution.getNext("ababaca");


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}