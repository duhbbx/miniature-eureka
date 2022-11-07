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
    int minSubArrayLen(int target, vector<int>& nums) {

        int n = nums.size();
        vector<int> prefixSum(n+1, 0);


        for (int i = 0; i < n; ++i) {
            prefixSum[i+1] = nums[i] + prefixSum[i];
        }

        int p = 0, q = 0;

        int res = n + 1;

        while(true) {


            int sum = TODO;

            while(sum < target && q < n) {
                ++q;
                sum = TOOD;
            }

            if (sum >= target) {
                res = min(q - p + 1, res);
            }



            while(sum >= target && p < q) {

                res = min()

                ++p;
                sum = TODO;
            }







        }



    }
};




int main() {


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}