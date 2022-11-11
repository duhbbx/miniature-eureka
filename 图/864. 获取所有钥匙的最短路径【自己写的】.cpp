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



struct Path {
    vector<pair<int, int>> p;
    vector<int> keys;
    int founded;
};


class Solution {
public:

    int shortestPathAllKeys(vector<string> &grid) {
        queue<Path> queue1;   //BFS的队列
        int m = grid.size();                    //网格的行数
        int n = grid[0].size();                 //网格的列数
        int totalKeys = 0;                      //总的钥匙有多少把

        //遍历网格,获取起始点的坐标,以及钥匙的数量
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '@') {
                    vector<pair<int, int>> path = vector<pair<int, int>>();
                    path.push_back(make_pair(i, j));
                    Path p;
                    p.p = path;
                    p.keys = vector<int>(26, 0);
                    p.founded = 0;
                    queue1.push(p);
                }
                if ('a' <= grid[i][j] && grid[i][j] <= 'z') {
                    ++totalKeys;        //更新钥匙的数量
                }
            }
        }
        while (!queue1.empty()) {
            int len = queue1.size();
            for (int i = 0; i < len; ++i) {
                auto cur = queue1.front();      //获取当前的路径
                queue1.pop();                   //弹出
                int x = cur.p.back().first;     //当前路径的当前位置坐标的行分量
                int y = cur.p.back().second;    //当前路径的当前位置坐标的列分量
                //当前点可走的四个方向:上,下,左,右
                vector<pair<int, int>> directions = {{-1, 0}, {1, 0},{0, -1},{0, 1}};
                for (auto &d: directions) {
                    int x_next = x + d.first;
                    int y_next = y + d.second;
                    //如果当前点不在网格范围内则跳过
                    if (x_next < 0 || x_next > m || y_next < 0 || y_next > n || grid[x_next][y_next] == '#') {
                        continue;
                    }

                    char room = grid[x_next][y_next];

                    if (room == '.' || room == '@') {





                    } else if ('a' <= grid[x_next][y_next] && grid[x_next][y_next] <= 'z') {
                        if (cur.keys[grid[x_next][y_next] - 'a'] == 0) {
                            cur.keys[grid[x_next][y_next] - 'a'] = 1;
                            ++cur.founded;
                            if (cur.founded == totalKeys) {
                                return cur.p.size();
                            }

                            Path np;
                            np = cur;
                            np.p.emplace_back(x_next, y_next);      // 当前路径加上这个点
                            queue1.push(np);                        // 新的路径入列
                        }
                    } else if ('A' <= grid[x_next][y_next] && grid[x_next][y_next] <= 'Z') {
                        if (cur.keys[grid[x_next][y_next] - 'A'] == 1) {
                            // 如果锁可以打开这个
                            Path np;
                            np = cur;
                            np.p.emplace_back(x_next, y_next);      // 当前路径加上这个点
                            queue1.push(np);                        // 新的路径入列
                        }
                    }
                }
            }

        }

        return -1;
    }
};


int main() {

    // vector<string> grid = {"@...a", ".###A", "b.BCc"};
    vector<string> grid = {"@abcdeABCDEFf"};

    Solution solution;

    solution.shortestPathAllKeys(grid);


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}