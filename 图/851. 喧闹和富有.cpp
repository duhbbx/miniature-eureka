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
    vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet) {
        int n = quiet.size();
        vector<vector<int>> g(n);
        for (auto &r : richer) {
            g[r[1]].emplace_back(r[0]);
        }

        vector<int> ans(n, -1);
        function<void(int)> dfs = [&](int x) {
            if (ans[x] != -1) {
                return;
            }
            ans[x] = x;
            for (int y : g[x]) {
                dfs(y);
                if (quiet[ans[y]] < quiet[ans[x]]) {
                    ans[x] = ans[y];
                }
            }
        };
        for (int i = 0; i < n; ++i) {
            dfs(i);
        }
        return ans;
    }
};



int main() {


    Solution solution;

    vector<vector<int>> r = {{1,0},{2,1},{3,1},{3,7},{4,3},{5,3},{6,3}};
    vector<int> quiet = {3,2,5,4,6,1,7,0};

    solution.loudAndRich(r, quiet);


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}