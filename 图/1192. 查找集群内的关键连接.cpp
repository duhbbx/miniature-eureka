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

private:
    const int maxn = 100;

    vector<int> dfn = vector<int>(maxn);                    // 节点访问的顺序
    vector<int> low = vector<int>(maxn);                    // 用于回溯
    vector<vector<int>> graph = vector<vector<int>>(maxn);  // 邻接列表
    int start = 0;
    vector<vector<int>> bridge = vector<vector<int>>();


public:


    void tarjan(int curr, int prev) {

        // 设置当前节点的 dfn 和 low

        // 遍历邻居节点
        for(int nei : graph[curr]) {
            if (!dfn[nei]) { // nei 还没有访问
                tarjan(nei, curr);
                low[curr] = min(low[curr], low[nei]);
                if (low[nei] > dfn[curr]) {

                }


            } else if (nei != prev) {
                // 此时 nei 是已经访问过的
                low[curr] = min(low[curr], dfn[nei]);

            }
        }
    }



    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        // 初始化 start
        start = 0;

        // 构造邻接列表


        for (int i = 0; i < n; ++i) {
            tarjan(i, -1);
        }


        return bridge;
    }
};


int main() {


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}