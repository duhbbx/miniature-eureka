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

    const int INF = 0x3F3F3F3F;


    int reachableNodes(vector<vector<int>> &edges, int maxMoves, int n) {

        vector<vector<pair<int, int>>> graph(n);

        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }


        queue<int> q;

        q.push(0);

        while(!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; ++i) {

            }
        }


    }
};


int main() {


    Solution solution;

    vector<vector<int>> edges = {{0, 1, 10},
                                 {0, 2, 1},
                                 {1, 2, 2}};
    solution.reachableNodes(edges, 6, 3);


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}