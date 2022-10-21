//
// Created by duhbb on 2022/10/21.
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
    vector<int> sumOfDistancesInTree(int n, const vector<vector<int>> &edges) {

        if (n <= 1) {
            return {0};
        }


        vector<vector<int>> g(n, vector<int>());

        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        vector<int> visited(n, 0);



        queue<tuple<int, int, int>> q;
        vector<tuple<int, int, int>> tree(n, tuple<int, int, int>());

        q.emplace(-1, edges[0][0], 0);

        while (!q.empty()) {
            int len = q.size();

            for (int i = 0; i < len; ++i) {

                int parentNode, currNode, layer;
                tie(parentNode, currNode, layer) = q.front();
                q.pop();
                visited[currNode] = 1;
                tree[currNode] = {parentNode, currNode, layer};

                for (auto adjacentNode : g[currNode]) {
                    if (visited[adjacentNode] == 0) {
                        q.emplace(currNode, adjacentNode, layer+1);
                    }

                }
            }
        }

        vector<int> res(n, 0);

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {

                int parent_i, curr_i, layer_i;
                int parent_j, curr_j, layer_j;

                tie(parent_i, curr_i, layer_i) = tree[i];
                tie(parent_j, curr_j, layer_j) = tree[j];

                int it_i = curr_i;
                int it_j = curr_j;



                int leastCommonParentLayer = min(layer_i, layer_j);

                while(get<2>(tree[it_i]) != leastCommonParentLayer) {
                    it_i = get<0>(tree[it_i]);
                }

                while(get<2>(tree[it_j]) != leastCommonParentLayer) {
                    it_j = get<0>(tree[it_j]);
                }

                while(it_i != it_j) {
                    it_i = get<0>(tree[it_i]);
                    it_j = get<0>(tree[it_j]);
                }

                int dist = layer_i - get<2>(tree[it_i]) + layer_j - get<2>(tree[it_i]);

                // cout << "curr_i = " << curr_i << ", curr_j = " << curr_j << ", dist = " << dist << endl;

                res[i] += dist;
                res[j] += dist;
            }
        }

        return res;
    }
};


int main() {


    Solution solution;

    // solution.sumOfDistancesInTree(6, {{0,1},{0,2},{2,3},{2,4},{2,5}});
    // solution.sumOfDistancesInTree(2, {{0,1}});
    solution.sumOfDistancesInTree(2, {{1,0}});


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}