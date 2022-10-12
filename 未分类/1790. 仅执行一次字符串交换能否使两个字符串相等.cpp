//
// Created by tuhooo on 2022/10/11.
//
#include <iostream>              // 输入输出
#include <vector>                // 可变长度数组
#include <unordered_map>         // hashmap
#include <unordered_set>         // 无序集合
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

void printCurrentFileName() {
    string file = __FILE__;
    int pos = file.find_last_of("/");
    string fileName = pos == -1 ? file : file.substr(pos + 1);
    cout << "\n【当前题目为：" << fileName << "】" << endl;
}




////////////////////////////////////////////////////////////////////////////////
/// 这里放OJ的类

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        char a, b;
        int flag = 0;
        bool use = false;
        if (s1.length() != s2.length()) {
            return false;
        }

        int len = s1.length();
        for (int i = 0; i < len; ++i) {
            if (s1[i] == s2[i]) {
                continue;
            }

            if (use) {
                return false;
            }

            if (flag == 0) {
                a = s1[i];
                b = s2[i];
                flag = 1;
            } else if (flag == 1) {
                if (s1[i] == b && s2[i] == a) {
                    use = true;
                    flag = 2;
                } else {
                    return false;
                }
            } else {
                return false;
            }

        }

        return flag != 1;
    }
};

////////////////////////////////////////////////////////////////////////////////

int main() {


    printCurrentFileName();


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}