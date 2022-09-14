//
// Created by duhbb on 2022/9/12.
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
    /**
     * 给你一个字符串 s 和一个字符规律 p
     * @param s 给定字符串
     * @param p 模式
     * @return 是否 match
     */
    bool isMatch(string s, string p) {

        int length_of_s = s.length();
        int length_of_p = p.length();
        vector<vector<bool>> dp(length_of_s + 1, vector<bool>(length_of_p + 1, false));


        // s 为空，p 也为空则可以匹配上
        dp[0][0] = true;

        // 第一列中 s 不为空，但是 p 为空，则肯定匹配不上
        for (int i = 1; i < length_of_s + 1; ++i) {
            dp[i][0] = false;
        }

        // 处理第一行
        for (int j = 1; j < length_of_p + 1; ++j) {
            if (p[j-1] == '.') {
                dp[0][j] = false;
            } else if (p[j-1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        for (int i = 1; i <= length_of_s; ++i) {
            for (int j = 1; j <= length_of_p; ++j) {

                // cout << "i = " << i << ", j = " << j << endl;

                if (p[j-1] == '.') {   // p 能匹配任意单个字符
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] == '*') { // p 为 * 号
                    if (s[i-1] == p[j-2] || p[j-2] == '.')  {
                        dp[i][j] = (dp[i-1][j] || dp[i][j-2]);
                    } else {
                        dp[i][j] = dp[i][j-2];
                    }
                } else if (s[i-1] == p[j-1]) {       // p 为具体的某个字符
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }


        return dp[length_of_s][length_of_p];
    }
};




////////////////////////////////////////////////////////////////////////////////




void printCurrentFileName() {
    string file = __FILE__;
    int pos = file.find_last_of("/");
    string fileName = pos == -1 ? file : file.substr(pos + 1);
    cout << "【当前题目为：" << fileName << "】" << endl;
}


int main() {


    printCurrentFileName();

    Solution solution;

    cout << "res = " << solution.isMatch("aab", "c*a*b") << endl;

    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}