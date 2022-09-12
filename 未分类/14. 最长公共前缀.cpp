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
    string longestCommonPrefix(vector<string>& strs) {

        int n = strs.size();
        if (n == 0) return "";
        if (n == 1) return strs[0];

        string prefix = strs[0];

        for (int i = 1; i < n; i++) {
            int j = -1;
            // NOTICE int类型的负数和 prefix.length() 【unsigned long】比较
            for (; j < (int) prefix.length() - 1 && j < (int) strs[i].length() - 1;) {
                if (prefix[j+1] == strs[i][j+1]) {
                    j++;
                } else {
                    break;
                }
            }
            if (j == -1) return "";

            prefix = prefix.substr(0, j + 1);

            // cout << "prefix = " << prefix << endl;
        }

        return prefix;
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

    vector<string> strs = {"flower","flow","flight"};
    // vector<string> strs = {"ab","a"};

    Solution solution;
    solution.longestCommonPrefix(strs);

    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}