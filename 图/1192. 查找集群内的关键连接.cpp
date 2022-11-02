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


class UnionSet {

private:
    vector<int> fa;
    int n;
public:

    UnionSet(int n) {
        this->n = n;
        fa = vector<int>(100, 0);
        iota(fa.begin(), fa.end(), 0);
    }

    int find(int x) {
        if (fa[x] == x) {
            return x;
        } else {
            fa[x] = find(fa[x]);
            return fa[x];
        }
    }

    void merge(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx == fy) {
            return;
        }
        fa[fx] = fy;
    }

    void reset(int x) {
        fa[x] = x;
    }
};


class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        UnionSet us(n);

        vector<vector<int>> graph(n);

        vector<vector<int>> res;

        for (auto& c : connections) {
            us.merge(c[0], c[1]);
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }

        for (auto& c : connections) {

            if (graph[c[0]].size() == 1 || graph[c[1]].size() == 1) {
                res.push_back(c);
                continue;
            }

            us.reset(c[0]);
            us.reset(c[1]);

            for (auto nei : graph[c[0]]) {
                if (nei != c[1]) {
                    us.merge(nei, c[0]);
                    break;
                }
            }

            for (auto nei : graph[c[1]]) {
                if (nei != c[0]) {
                    us.merge(nei, c[1]);
                    break;
                }
            }

            if (us.find(c[0]) != us.find(c[1])) {
                
            }



        }
    }
};


int main() {


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}