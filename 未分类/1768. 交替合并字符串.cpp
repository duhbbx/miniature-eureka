//
// Created by duhbb on 2022/10/23.
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
    string mergeAlternately(string word1, string word2) {

        int p = 0;

        string res = "";
        while(p < word1.length() && p < word2.length()) {

            res.push_back(word1[p]);
            res.push_back(word2[p]);

            ++p;
        }

        while(p < word1.length()) {
            res.push_back(word1[p]);
            ++p;
        }

        while (p < word2.length()) {
            res.push_back(word2[p]);
            ++p;
        }

        return res;
    }
};






int main() {


    Solution solution;

    solution.mergeAlternately("abc", "edf");


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}