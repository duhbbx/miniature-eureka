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
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int> prefix_product(n + 1, 1);
        vector<int> suffix_product(n + 1, 1);

        for (int i = 0; i < n; ++i) {
            prefix_product[i+1] = nums[i] * prefix_product[i];
            suffix_product[i+1] = nums[n-i-1] * suffix_product[i];
        }

        vector<int> res(n, 1);

        for (int i = 0; i < n; ++i) {



            res[i] = res[i] * prefix_product[i] * suffix_product[n - i-1];
        }


        return res;
    }
};


int main() {


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}