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


#define X(i) (i / n)
#define Y(i) (i % n)
#define IDX(x, y) (x * n + y)


class Solution {
public:
    int regionsBySlashes(vector<string> &grid) {

        int n = grid.size() + 1;    // 每条边上的点数

        vector<vector<int>> graph(n);

        // 四周的边
        for (int i = 0; i < n - 1; ++i) {
            graph[IDX(i, 0)].push_back(IDX(i + 1, 0));
            graph[IDX(n - 1, i)].push_back(IDX(n - 1, i + 1));
            graph[IDX(n - i, n - 1)].push_back(IDX(n - i - 1, n - 1));
            graph[IDX(0, n - i)].push_back(IDX(0, n - i - 1));

            graph[IDX(i + 1, 0)].push_back(IDX(i, 0));
            graph[IDX(n - 1, i + 1)].push_back(IDX(n - 1, i));
            graph[IDX(n - i - 1, n - 1)].push_back(IDX(n - i, n - 1));
            graph[IDX(0, n - i - 1)].push_back(IDX(0, n - i));
        }


        // 每个格子里的边
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - 1; ++j) {

            }
        }

        // 下面就是求无向图中的环的个数的常规操作了, DFS




        return 0;
    }
};


int main() {


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}