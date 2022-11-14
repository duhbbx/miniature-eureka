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
    bool splitArraySameAverage(vector<int> &nums) {

        int n = nums.size();
        if (n < 2) {
            return false;
        }
        int sum = 0;

        for (auto &item: nums) {
            sum += item;
        }

        vector<int> transform = nums;
        for (auto &item: transform) {
            item = item * n - sum;
        }

        unordered_set<int> left;

        int l = (n + 1) / 2;


        for (int i = 1; i < (1 << l); ++i) {    // 这个地方得是小于
            int temp = 0;

            for (int j = 0; j < l; ++j) {
                if (i & (1 << j)) {
                    temp += transform[j];
                }
            }

            if (temp == 0) {
                return true;
            } else {
                left.insert(temp);
            }
        }

        // 求有右边区间的和
        int rsum = accumulate(transform.begin() + l, transform.end(), 0);

        for (int i = 1; i < (1 << (n - l)); ++i) {
            int temp = 0;
            for (int j = 0; j < n - l; ++j) {
                if (i & (1 << j)) {
                    temp += transform[l + j];
                }
            }

            // 为什么要加上右边区间的和呢?
            if (temp == 0 || (rsum != temp && left.count(-temp))) {
                return true;
            }
        }

        return false;
    }
};


int main() {


    Solution solution;

    vector<int> nums = {3, 1};

    solution.splitArraySameAverage(nums);


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}