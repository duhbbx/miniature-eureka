//
// Created by duhbb on 2022/10/26.
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




class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {

        vector<int>::iterator begin = nums.begin();
        vector<int>::iterator end = nums.begin();
        int sum = 0;
        for (; end < nums.end(); ++end) {
            sum += *end;
            if (sum >= k) {
                break;
            }
        }
        if (sum < k) {
            return -1;
        }
        int res = end - begin + 1;



        while(end < nums.end()) {

            while(sum >= k) {
                res = min(res, (int) (end - begin + 1));
                sum -= *begin;
                ++begin;
            }

            while(sum < k && end < nums.end()) {
                ++end;
                sum += *end;
            }

        }
        return res;


    }
};


int main() {


    Solution solution;

    vector<int> nums = {1};

    solution.shortestSubarray(nums, 1);

    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}