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
    int subarraysDivByK(vector<int>& nums, int k) {

        int res = 0;

        int n = nums.size();

        unordered_map<int, int> map1;

        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            ++map1[abs(sum % k)];
            if(nums[i] % k == 0) {
                ++res;
            }
        }

        for (auto& entry : map1) {
            if (entry.second > 1) {
                res += entry.second * (entry.second - 1) / 2;
            }
        }

        return res ;
    }
};




int main() {



    vector<int> nums = {2, -2,2,4};

    int k  = 6;
    Solution solution;

    int res = solution.subarraysDivByK(nums, k);


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}