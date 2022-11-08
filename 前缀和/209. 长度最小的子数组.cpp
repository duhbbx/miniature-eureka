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
    int minSubArrayLen(int target, vector<int> &nums) {
        int n = nums.size();

        vector<int> prefixSum(n + 1, 0);        //存储前缀和的容器, 多一个元素作为哨兵
        for (int i = 0; i < n; ++i) {           //求前缀和
            prefixSum[i + 1] = nums[i] + prefixSum[i];
        }

        int p = 1, q = 1;
        int res = n + 1;

        while (q < n) {
            //prefixSum[q] - prefixSum[p - 1]是用来求[p,q]闭区间的前缀和

            //q往前面拱
            while (prefixSum[q] - prefixSum[p - 1] < target && q < n) {
                ++q;
            }

            if (prefixSum[q] - prefixSum[p - 1] >= target) {
                res = min(q - p + 1, res);
                if (res == 1) {
                    return res;
                }
            }

            //p往前面推
            while (prefixSum[q] - prefixSum[p - 1] >= target && p <= q) {
                res = min(q - p + 1, res);
                if (res == 1) {
                    return res;
                }
                ++p;
            }
        }
        return res == n + 1 ? 0 : res;
    }
};


int main() {


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}