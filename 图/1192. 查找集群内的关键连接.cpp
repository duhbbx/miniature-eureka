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


using G=vector<vector<pair<int, int>>>;


class Solution {
public:

    void dfs(int node, G& g, vector<int>& path) {





    }


    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        vector<vector<pair<int, int>>> graph(n);

        for (auto& c : connections) {
            graph[c[0]].emplace_back(c[1], 0);
            graph[c[1]].emplace_back(c[0], 0);
        }



        vector<int> path;





    }
};


int main() {


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}