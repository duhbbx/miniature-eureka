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
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();    // 网格的列数和行数
        int sx = 0, sy = 0;                         // 起始位置
        unordered_map<char, int> key_to_idx;        // 对钥匙编号
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '@') {
                    sx = i;
                    sy = j;
                } else if (islower(grid[i][j])) {
                    if (!key_to_idx.count(grid[i][j])) {
                        int idx = key_to_idx.size();
                        key_to_idx[grid[i][j]] = idx;
                    }
                }
            }
        }

        queue<tuple<int, int, int>> q;
        vector<vector<vector<int>>> dist(m, vector<vector<int>>(n, vector<int>(1 << key_to_idx.size(), -1)));
        q.emplace(sx, sy, 0);       // 入口位置入列,目前有0个钥匙
        dist[sx][sy][0] = 0;
        while (!q.empty()) {
            auto [x, y, mask] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] != '#') {
                    if (grid[nx][ny] == '.' || grid[nx][ny] == '@') {
                        if (dist[nx][ny][mask] == -1) {
                            dist[nx][ny][mask] = dist[x][y][mask] + 1;
                            q.emplace(nx, ny, mask);
                        }
                    } else if (islower(grid[nx][ny])) {
                        int idx = key_to_idx[grid[nx][ny]];     // 获取钥匙的编号
                        if (dist[nx][ny][mask | (1 << idx)] == -1) {
                            dist[nx][ny][mask | (1 << idx)] = dist[x][y][mask] + 1;

                            // 找到了所有的钥匙
                            if ((mask | (1 << idx)) == (1 << key_to_idx.size()) - 1) {
                                return dist[nx][ny][mask | (1 << idx)];
                            }
                            q.emplace(nx, ny, mask | (1 << idx));
                        }
                    } else {
                        int idx = key_to_idx[tolower(grid[nx][ny])];
                        if ((mask & (1 << idx)) && dist[nx][ny][mask] == -1) {
                            dist[nx][ny][mask] = dist[x][y][mask] + 1;
                            q.emplace(nx, ny, mask);
                        }
                    }
                }
            }
        }
        return -1;
    }

private:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};


int main() {

    // vector<string> grid = {"@...a", ".###A", "b.BCc"};
    vector<string> grid = {"@abcdeABCDEFf"};

    Solution solution;

    solution.shortestPathAllKeys(grid);


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}