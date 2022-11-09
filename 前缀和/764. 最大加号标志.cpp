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
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {


        vector<vector<int>> rowPrefixSum(n + 1, vector<int>(n, 0));
        vector<vector<int>> colPrefixSum(n, vector<int>(n+1, 0));


        vector<vector<int>> grid(n, vector<int>(n, 1));

        for (auto& m :mines) {
            grid[m[0]][m[1]] = 0;
        }


        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                rowPrefixSum[j+1][i] = rowPrefixSum[j][i] + grid[j][i];
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                colPrefixSum[i][j+1] = colPrefixSum[i][j] + grid[i][j];
            }
        }



        for (int i = (n - 1) / 2; i >= 0; --i) {

            int sum = 2 * i + 1;

            for (int j = i; j + i < n; ++j) {

                for (int k = i; k + i < n; ++k) {

                    if (rowPrefixSum[j+i+1][k] - rowPrefixSum[j-i][k] == sum && colPrefixSum[j][k+i+1] - colPrefixSum[j][k-i] == sum) {
                        return i + 1;
                    }
                }


            }
        }

        return 0;
    }
};


int main() {


    int n =  2;
    vector<vector<int>> mines = {{0,0},{0,1},{1,0}};

    Solution solution;

    solution.orderOfLargestPlusSign(n, mines);


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}