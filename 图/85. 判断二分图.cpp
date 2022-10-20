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
    bool isBipartite(const vector<vector<int>>& graph) {

        int n = graph.size();

        vector<int> color(n, 0);

        queue<int> q;
        q.push(0);
        color[0] = 1;
        int k = 1;

        while(!q.empty()) {

            int len = q.size();

            for (int i = 0; i < len; ++i) {
                int currVertex = q.front();
                q.pop();
                for (int j = 0; j < graph[currVertex].size(); ++j) {
                    int adjacentVertex = graph[currVertex][j];

                    if (color[adjacentVertex] == 0) {
                        if (color[currVertex] == 1) {
                            color[adjacentVertex] = 2;
                        } else {
                            color[adjacentVertex] = 1;
                        }
                        q.push(adjacentVertex);
                    } else if (color[currVertex] == color[adjacentVertex]) {
                        return false;
                    }
                }

            }

            if (q.empty()) {
                while(k < n) {
                    if (color[k] != 0) {
                        ++k;
                    } else {
                        q.push(k);
                        color[k] = 0;  // 这一步漏了就会导致死循环了....
                        break;
                    }
                }
            }
        }
        return true;
    }
};


int main() {


    Solution solution;

    solution.isBipartite({{4},{},{4},{4},{0,2,3}});


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}