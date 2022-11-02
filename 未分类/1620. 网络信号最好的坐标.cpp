//
// Created by tuhooo on 2022/11/2.
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


#define D(x, y, i) sqrt((towers[i][0] - (x)) * (towers[i][0] - (x)) + (towers[i][1] - (y))*(towers[i][1] - (y)))


/**
 * 按照[0]从大到小, [1]从小到大, [2] 从小到大
 * @param a 信号强度,坐标的 tuple
 * @param b 信号强度,坐标的 tuple
 * @return 比较结果
 */
bool cmp(const tuple<int, int, int> &a, const tuple<int, int, int> &b) {
    int strength_a, x_a, y_a, strength_b, x_b, y_b;
    tie(strength_a, x_a, y_a) = a;
    tie(strength_b, x_b, y_b) = b;

    if (strength_a < strength_b) {
        return true;
    } else if (strength_a > strength_b) {
        return false;
    } else if (x_a > x_b) {
        return true;
    } else if (x_a < x_b) {
        return false;
    } else if (y_a > y_b) {
        return true;
    } else if (y_a < y_b) {
        return false;
    }

    return false;
}

class Solution {
public:

    vector<int> bestCoordinate(vector<vector<int>> &towers, int radius) {
        int n = towers.size();

        auto base = make_tuple(0, 0, 0);

        for (int i = 0; i <= 50; ++i) {
            for (int j = 0; j <= 50; ++j) {
                int strength = 0;
                for (int k = 0; k < n; ++k) {

                    int xx = towers[k][0];
                    int yy = towers[k][1];
                    if (i - xx > radius || i - xx < -radius ||
                        j - yy > radius || j - yy < -radius) {
                        continue;
                    }

                    double d = D(i, j, k);
                    if (d > radius) {
                        continue;
                    }

                    strength += (int) (towers[k][2] / (1 + 1.0 * d));
                }

                auto curr = make_tuple(strength, i, j);

                if (cmp(base, curr)) {
                    base = curr;
                }
            }


        }


        return {get<1>(base), get<2>(base)};
    }
};


int main() {


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}