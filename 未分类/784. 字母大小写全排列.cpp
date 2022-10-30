//
// Created by duhbb on 2022/10/30.
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
#include <numeric>
#include <map>
#include <cstring>


using namespace std;


class Solution {
public:

    void dfs(vector<string> &res, string &s, int idx, bool revert) {

        if (idx == s.length()) {
            return;
        }

        if ('0' > s[idx] || s[idx] > '9') {
            res.push_back(s);
        }

        dfs(res, s, idx + 1, true);


        if (revert) {
            char origin = s[idx];

            if ('a' <= s[idx] && s[idx] <= 'z') {
                s[idx] = s[idx] + ('A' - 'a');
                dfs(res, s, idx, false);
                s[idx] = origin;
            } else if ('A' <= s[idx] && s[idx] <= 'Z') {
                s[idx] = s[idx] + ('a' - 'A');
                dfs(res, s, idx, false);
                s[idx] = origin;
            }
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        dfs(res, s, 0, true);
        return res;
    }
};


int main() {


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}