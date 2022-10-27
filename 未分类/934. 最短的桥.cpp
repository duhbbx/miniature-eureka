//
// Created by tuhooo on 2022/10/25.
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


int s[10000];

#define X(i) (i / (int) grid.size())
#define Y(i) (i % (int) grid.size())


class Solution {
public:

    int find(int x) {
        return x == s[x] ? x : (s[x] = find(s[x]));
    }

    void merge(int x, int y) {
        int i = find(x), j = find(y);
        if (i != j) {
            s[i] = j;
        }
    }


    int shortestBridge(vector<vector<int>> &grid) {

        memset(s, 0, sizeof(s));    // 将s清空
        for (int i = 0; i < grid.size() * grid.size(); ++i) {
            if (grid[X(i)][Y(i)] == 0) {
                s[i] = -1;
            } else {
                s[i] = i;
            }

        }

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid.size(); ++j) {
                if (grid[i][j] == 0) {
                    continue;
                } else {
                    if (j > 0 && grid[i][j - 1] == 1) {
                        merge(i * grid.size() + j, i * grid.size() + j - 1);
                    }
                    if (j < grid.size() - 1 && grid[i][j + 1] == 1) {
                        merge(i * grid.size() + j, i * grid.size() + j + 1);
                    }

                    if (i < grid.size() - 1 && grid[i + 1][j] == 1) {
                        merge(i * grid.size() + j, (i + 1) * grid.size() + j);
                    }
                }
            }
        }


        int res = 10000;
        for (int i = 0; i < grid.size() * grid.size(); ++i) {

            int ix = X(i);
            int iy = Y(i);

            if (grid[ix][iy] == 0) {
                continue;
            }

            for (int j = i + 1; j < grid.size() * grid.size(); ++j) {

                int jx = X(j);
                int jy = Y(j);


                if (grid[jx][jy] == 0 || find(i) == find(j) ) {
                    continue;
                }


                res = min(abs(ix - jx) + abs(iy - jy) - 1, res);
            }
        }

        return res;
    }
};


int main() {


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}