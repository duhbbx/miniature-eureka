//
// Created by tuhooo on 2022/10/20.
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
    vector<int> eventualSafeNodes(vector<vector<int>> &graph) {

        int n = graph.size();

        queue<int> q;


        vector<vector<int>> out(n, vector<int>());

        vector<int> inDegree(n, 0);


        for (int i = 0; i < n; ++i) {
            if (graph[i].size() == 0) {
                q.push(i);      // 入度为0的入列
            } else {
                for (int j = 0; j < graph[i].size(); ++j) {
                    out[graph[i][j]].push_back(i);  // 记录节点的出度
                }
            }
            inDegree[i] = graph[i].size();
        }


        vector<int> res;

        while (!q.empty()) {
            int len = q.size();

            for (int i = 0; i < len; ++i) {

                int currVertex = q.front();
                q.pop();

                for (int j = 0; j < out[currVertex].size(); ++j) {
                    int adjacentVertex = out[currVertex][j];
                    --inDegree[adjacentVertex];

                    if (inDegree[adjacentVertex] == 0) {
                        q.push(adjacentVertex);
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                res.push_back(i);
            }
        }
        return res;

    }
};

int main() {


    Solution solution;

    vector<vector<int>> graph = {{1, 2},
                                 {2, 3},
                                 {5},
                                 {0},
                                 {5},
                                 {},
                                 {}};
    solution.eventualSafeNodes(graph);


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}