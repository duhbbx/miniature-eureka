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

private:
    const int maxn = 100000;

    vector<int> dfn = vector<int>(maxn);                    // 节点访问的顺序
    vector<vector<int>> graph = vector<vector<int>>(maxn);  // 邻接列表
    int start = 0;
    vector<vector<int>> bridge = vector<vector<int>>();


public:


    int tarjan(int curr, int prev) {

        int currLow = ++start;
        dfn[curr] = currLow;

        // 遍历邻居节点
        for(int nei : graph[curr]) {
            // nei 还没有访问, dfn 所有元素的默认值都是 0, 所以 !dfn[nei] 为真说明 nei 还没访问过
            if (!dfn[nei]) {
                // nei还没访问过的话,就以nei为根节点继续找
                int neiLow = tarjan(nei, curr);
                // 计算 curr 的追溯值
                currLow = min(currLow, neiLow);
                // 出现这种请情况表示从curr可以到nei,但是nei永远回不去curr了
                if (neiLow > dfn[curr]) {
                    bridge.push_back({curr, nei});
                }
            } else if (nei != prev) {
                // 此时nei是已经访问过的,从nei开始回溯
                currLow = min(currLow, dfn[nei]);
            }
        }

        return currLow;
    }



    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        // 初始化 start
        start = 0;

        // 构造邻接列表
        for (auto& c : connections) {
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }

        tarjan(0, -1);
        return bridge;
    }
};


int main() {


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}