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
#include <cstring>
#include "../../0000 API 模板 类/TreeNode.h"
#include "../../0000 API 模板 类/ListNode.h"


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
    bool equalFrequency(string word) {

        int a[26];
        memset(a, 0, sizeof(a));

        for (auto& c : word) {
            ++a[c - 'a'];
        }

        for (int i = 0; i < 26; ++i) {
            if (a[i] == 0) {
                continue;
            }

            a[i]--;

            int aa = 0, bb = 0, sum = 0;
            for (int j = 0; j < 26; ++j) {
                if (a[j] != 0) {
                    aa = max(a[j], aa);
                    bb++;
                }
                sum += a[j];
            }

            if (aa == 0 || sum / bb == aa) {
                return true;
            }
            a[i]++;
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
    solution.equalFrequency("abbcc");


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}