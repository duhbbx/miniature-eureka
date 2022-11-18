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
    int maxSideLength(vector<vector<int>>& mat, int threshold) {

        int rowNum = mat.size();
        int colNum = mat[0].size();

        for (int i = 1; i < rowNum; ++i) {
            for (int j = 0; j < colNum; ++j) {
                mat[i][j] += mat[i-1][j];
            }
            cout << endl;
        }

        for (int i = 0; i < rowNum; ++i) {
            for (int j = 1; j < colNum; ++j) {
                mat[i][j] += mat[i][j-1];
            }
        }

        for (int i = 0; i < rowNum; ++i) {
            for (int j = 0; j < colNum; ++j) {

                cout << mat[i][j] << ", ";
            }
            cout << endl;
        }

        int res = 0;

        for (int i = -1; i < rowNum; ++i) {
            for (int j = -1; j < colNum; ++j) {
                for (int n = 1; n <= min(rowNum, colNum); ++n) {
                    if (i + n < rowNum && j + n < colNum) {


                        int lu = (i < 0 || j < 0) ? 0 : mat[i][j];
                        int ru = (i < 0) ? 0 : mat[i][j+n];
                        int ld = (j < 0) ? 0 : mat[i+n][j];
                        int rd = mat[i+n][j+n];

                        int sum = rd - ld - (ru - lu);

                        cout << "i = " << i << ", j = " << j << ", n = " << n << ", res = " << res << ", sum = " << sum << ", th = " << threshold << endl;


                        if (sum <= threshold) {
                            cout << "===========sum = " << sum << ", th = " << threshold << endl;
                            res = max(res, n);

                            cout << "i = " << i << ", j = " << j << ", n = " << n << ", res = " << res << ", sum = " << sum << ", th = " << threshold << endl;

                        }
                    } else {
                        break;
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