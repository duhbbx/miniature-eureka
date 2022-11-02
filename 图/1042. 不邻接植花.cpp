//
// Created by duhbb on 2022/11/2.
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

    void dfs(int node, vector<vector<int>> &graph, vector<int> &res, int& count, int n) {
        if (count == n) {
            return;
        }

        int color[] = {1, 2, 3, 4};

        // 去掉邻居已经使用的颜色
        for (int nei : graph[node]) {
            if (res[nei - 1] != 0) {
                color[res[nei-1]-1] = 0;

            }
        }

        if (res[node-1] == 0) {
            // 给当前点选一个颜色
            for (int i = 0; i < 4; ++i) {
                if (color[i] != 0) {
                    res[node-1] = color[i];
                    ++count;
                    if (count == n) {
                        return;
                    }
                    break;
                }
            }
        } else {
            // 如果自己已经种了花了
            color[res[node-1]-1] = 0;

            // 给还没有种花的邻居把花种上
            for (int nei : graph[node]) {
                if (res[nei-1] == 0) {
                    for (int i = 0; i < 4; ++i) {
                        if (color[i] != 0) {
                            res[nei-1] = color[i];
                            ++count;
                            if (count == n) {
                                return;
                            }
                            color[i] = 0;
                            break;
                        }
                    }
                }
            }
        }
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>> &paths) {

        vector<vector<int>> graph(n + 1);

        for (auto &p: paths) {
            graph[p[0]].push_back(p[1]);
            graph[p[1]].push_back(p[0]);
        }

        vector<int> res(n, 0);
        int count =  0;

        for (int i = 1; i <= n; ++i) {
            dfs(i, graph, res, count, n);
        }

        return res;


    }
};


int main() {

    int n = 3;
    vector<vector<int>> paths = {{1,2},{2,3},{3,1}};





    Solution solution;

    solution.gardenNoAdj(n, paths);


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}