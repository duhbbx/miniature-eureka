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
    int pivotIndex(vector<int>& nums) {

        int n = nums.size();

        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }

        for (int i = 0; i < n; ++i) {
            int left = prefixSum[i];
            int right = prefixSum[n] - prefixSum[i+1];

            if (left == right) {
                return i;
            }
        }

        return -1;
    }
};


int main() {


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}