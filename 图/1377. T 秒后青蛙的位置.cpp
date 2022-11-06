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

    int m_n;
    vector<vector<int>> graph;
    vector<int> res;
    vector<int> visited;
    int totalVisited;
    int m_t;
    int m_target;
    Solution() {
    }


    double dfs(int curr, int choice) {

        ++totalVisited;
        visited[curr] = 1;

        if (totalVisited == m_t + 1) {
            if (curr == m_target) {
                return 1.0  / (1.0 * choice);
            }
        } else if (curr == m_target) {
            if (graph[curr].size() == 1) {
                return 1.0 / (1.0 * choice);
            }
        } else {
            choice *= graph[curr].size() - 1;
            for (auto nei : graph[curr]) {
                if (visited[nei] == 0) {
                    visited[nei] = 1;
                    double p = dfs(nei, choice);
                    if (p != 0) {
                        return p;
                    }
                }
            }
        }

        visited[curr] = 0;
        --totalVisited;

        return 0;
    }

    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {

        if (edges.size() == 0 && target == 1) {
            return 1;
        }


        graph = vector<vector<int>>(n+1, vector<int>());
        res = vector<int>(n+1);
        visited = vector<int>(n+1);
        totalVisited = 0;
        m_n = n+1;
        m_t = t;
        m_target = target;

        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }


        visited[1] = 1;
        totalVisited = 1;
        int choice = graph[1].size();
        for (auto nei : graph[1]) {
            double p = dfs(nei, choice);
            if (p != 0) {
                return p;
            }
        }

        return 0;
    }
};


int main() {


    int n = 7;
    vector<vector<int>> edges = {{1,2},{1,3},{1,7},{2,4},{2,6},{3,5}};

    int t = 2;
    int target = 4;
    Solution solution;

    solution.frogPosition(n, edges, t, target);


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}