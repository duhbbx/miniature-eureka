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
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> row = {(double) poured};
        for (int i = 2; i <= query_row + 1; ++i) {
            vector<double> next_row(i);
            for (int j = 0; j < i-1; ++j) {
                if (row[j] > 1) {
                    next_row[j] += (row[j] - 1) / 2;
                    next_row[j+1] += (row[j] - 1) / 2;
                    row[j] = 1;
                }
            }
            row = next_row;
        }
        return min(1.0, row[query_glass]);
    }
};


int main() {


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}