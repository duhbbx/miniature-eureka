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
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string parenthesis = "";
        int leftParenthesis = 0;
        int rightParenthesis = 0;
        backtrack(res, parenthesis, leftParenthesis, rightParenthesis, n);
        return res;
    }

private:
    void backtrack(vector<string> &res, string &parenthesis, int leftParenthesis, int rightParenthesis, int n) {
        if (rightParenthesis == n) {
            res.push_back(parenthesis);
            return;
        }

        if (leftParenthesis < n) {
            parenthesis.push_back('(');
            backtrack(res, parenthesis, leftParenthesis + 1, rightParenthesis, n);
            parenthesis.pop_back();
        }

        if (rightParenthesis < leftParenthesis) {
            parenthesis.push_back(')');
            backtrack(res, parenthesis, leftParenthesis, rightParenthesis + 1, n);
            parenthesis.pop_back();
        }
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

    solution.generateParenthesis(3);


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}