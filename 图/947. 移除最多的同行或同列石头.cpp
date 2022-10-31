//
// Created by duhbb on 2022/10/31.
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

    void dfs(int r, int i, map<int, int>& m, vector<vector<int>> &graph, vector<int>& visited) {

        if (visited[i] == 1) {
            return;
        }
        ++m[r];
        visited[i] = 1;

        for (int nei : graph[i]) {
           dfs(r, nei, m, graph, visited);
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> graph(n);


        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        vector<int> visited(n, 0);
        map<int, int> m;

        for (int i = 0; i < n; ++i) {
            dfs(i, i, m, graph, visited);
        }

        int res = 0;
        for (auto& mm : m) {
            if (mm.second > 1) {
                res += mm.second - 1;
            }
        }
        return res;
    }
};



int main() {


    Solution solution;


    vector<vector<int>> stones = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    solution.removeStones(stones);


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}