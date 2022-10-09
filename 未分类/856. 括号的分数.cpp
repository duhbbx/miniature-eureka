//
// Created by tuhooo on 2022/10/9.
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
    string fileName = pos == -1 ? file : file.substr(pos+1);
    cout << "\n【当前题目为：" << fileName << "】" << endl;
}


////////////////////////////////////////////////////////////////////////////////
/// 这里放OJ的类


class Solution {
public:
    int scoreOfParentheses(string s) {

        char stk[100];

        int top = -1;

        int sum = 0;

        int m, n;
        for (int i = 0; i < s.length(); ++i) {


            if (top == -1) {
                stk[++top] = s[i];
                m = i;
            } else {
                if (stk[top] == '(') {

                    if (s[i] == '(') {
                        stk[++top] = '(';
                    } else {
                        --top;
                    }
                }
            }

            if (top == -1) {
                n = i;

                if (n - m == 1) {
                    sum += 1;
                } else {
                    sum += 2 * scoreOfParentheses(s.substr(m+1, n-m));
                }
            }
        }


        return sum;
    }
};

////////////////////////////////////////////////////////////////////////////////

int main() {


    printCurrentFileName();


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}