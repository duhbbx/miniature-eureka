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
        int m = n / 2;
        int sum = accumulate(nums.begin(), nums.end(), 0);

        bool isPossible = false;
        for (int i = 1; i <= m; ++i) {
            if (sum * i % n == 0) {
                isPossible = true;
                break;
            }
        }

        if (!isPossible) {
            return false;
        }

        vector<unordered_set<int>> dp(m + 1);
        dp[0].insert(0);

//        for (int num : nums) {
//            for (int i = m; i >= 1; --i) {
//                for (int x : dp[i-1]) {
//                    int curr = x + num;
//                    if (curr * n == sum * i) {
//                        return true;
//                    }
//
//                    dp[i].emplace(curr);
//                }
//            }
//        }




        for (int i = 1; i <= m; ++i) {
            for (int x: dp[i - 1]) {

                for (int num: nums) {

                    int curr = x + num;
                    if (curr * n == sum * i) {
                        return true;
                    }

                    dp[i].emplace(curr);
                }
            }
        }

        return false;
    }
};


int main() {


    Solution solution;

    // vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> nums = {2,12,18,16,19,3};

    solution.splitArraySameAverage(nums);


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}