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
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);

        int res = 0;
        for(int i = 0; i < n; ++i) {
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }

        int sum1 = 0;
        int sum2 = 0;
        for (int l1 = 0, l2 = 0, r = 0; r < n; ++r) {
            sum1 = prefixSum[r+1] - prefixSum[l1];
            while(l1 <= r && sum1 > goal) {
                sum1 -= nums[l1++];
            }

            sum2 =  prefixSum[r+1] - prefixSum[l2];
            while(l2 <= r && sum2 >= goal) {
                sum2 -= nums[l2++];
            }

            res += l2 - l1;


        }

        return res;
    }
};


int main() {


    Solution solution;

    vector<int> s = {1, 0};
    int goal = 0;

    solution.numSubarraysWithSum(s, goal);


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}