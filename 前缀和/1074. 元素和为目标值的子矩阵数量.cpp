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
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {


        int m = matrix.size();
        int n = matrix[0].size();

        /*
        vector<vector<int>> prefixSum(m * n + 1, vector<int>(m * n + 1, 0));



        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                prefixSum[i+1][j+1] = prefixSum[i+1][j] + matrix[i][j];
            }
        }

        for (int i = 0; i < m + 1; ++i) {
            for (int j = 0; j < n + 1; ++j) {
                cout << prefixSum[i][j] << ", ";
            }
            cout << endl;
        }
        cout << "===============================" << endl;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j <= n; ++j) {
                prefixSum[i+1][j] = prefixSum[i][j] + prefixSum[i+1][j];
            }
        }

        for (int i = 0; i < m + 1; ++i) {
            for (int j = 0; j < n + 1; ++j) {
                cout << prefixSum[i][j] << ", ";
            }
            cout << endl;
        }


        */



        vector<vector<int>> prefixSum(m + 1, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                prefixSum[i+1][j] = prefixSum[i][j] + matrix[i][j];
            }
        }


        int res = 0;
        for (int x1 = 0; x1 < m; ++x1) {
            for (int y1 = 0; y1 < n; ++y1) {
//                for (int x2 = x1; x2 < m; ++x2) {
//                    for (int y2 = y1; y2 < n; ++y2) {
//                        int sum = prefixSum[x2+1][y2+1] - prefixSum[x2+1][y1] - prefixSum[x1][y2+1] + prefixSum[x1][y1];
//                        if (sum == target) {
//                            ++res;
//                        }
//                    }
//                }
                for (int i = 0; i < n; ++i) {

                    int sum = 0;
                    for (int l = 0, r = 0; r < n; ++r) {
                        sum +=
                    }


                }

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