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
    int minCost(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0x3F3F3F3F));

        vector<vector<int>> visited(m, vector<int>(n));

        queue<pair<int, int>> queue1;
        dp[0][0] = 0;
        queue1.emplace(0, 0);


        while(!queue1.empty()) {
            int len = queue1.size();
            for (int i = 0; i < len; ++i) {
                int row, col;
                tie(row, col) = queue1.front();

                if (visited[row][col] == 2) {
                    continue;
                }

                visited[row][col] = 2;

                if(row - 1 >= 0) {
                    int relax = dp[row][col]+ (grid[row][col] == 4 ? 0 : 1);
                    if (relax < dp[row-1][col]) {
                        if (visited[row-1][col] == 0) {
                            queue1.emplace(row-1, col);
                            visited[row-1][col] = 1;
                        }
                        dp[row-1][col] = relax;
                    }
                }

                if (row + 1 < m) {
                    int relax = dp[row][col]+ (grid[row][col] == 3 ? 0 : 1);
                    if (relax < dp[row+1][col]) {


                        if (visited[row+1][col] == 0) {
                            queue1.emplace(row+1, col);
                            visited[row+1][col] = 1;
                        }

                        dp[row+1][col] = relax;
                    }
                }

                if (col - 1 >= 0) {

                    int relax = dp[row][col]+ (grid[row][col] == 2 ? 0 : 1);
                    if (relax < dp[row][col-1]) {


                        if (visited[row][col-1] == 0) {
                            queue1.emplace(row, col-1);
                            visited[row][col-1] = 1;
                        }

                        dp[row][col-1] = relax;
                    }
                }

                if (col + 1 < n) {

                    int relax = dp[row][col]+ (grid[row][col] == 1 ? 0 : 1);
                    if (relax < dp[row][col+1]) {


                        if (visited[row][col+1] == 0) {
                            queue1.emplace(row, col+1);
                            visited[row][col+1] = 1;
                        }

                        dp[row][col+1] = relax;
                    }
                }

                queue1.pop();
            }
        }


        return dp[m-1][n-1];
    }
};





int main() {


    Solution solution;

    // vector<vector<int>> grid = {{1,1,3},{3,2,2},{1,1,4}};
    vector<vector<int>> grid = {{2,2,2},{2,2,2}};

    solution.minCost(grid);


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}