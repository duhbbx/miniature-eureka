//
// Created by tuhooo on 2022/10/24.
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
    int partitionDisjoint(vector<int>& nums) {

        vector<int> leftMax;
        vector<int> rightMin;

        for (int i = 0; i < nums.size(); ++i) {
            if (leftMax.empty()) {
                leftMax.push_back(nums[i]);
            } else {
                leftMax.push_back(max(nums[i], leftMax[leftMax.size()-1]));
            }
        }

        for (int i = nums.size()-1; i > 0; --i) {
            if (rightMin.empty()) {
                rightMin.push_back(nums[i]);
            } else {
                rightMin.push_back(min(nums[i], rightMin[rightMin.size()-1]));
            }
        }

        for (int i = 0; i <= nums.size()-2; ++i) {
            if (leftMax[i] <= rightMin[nums.size() - i - 1]) {
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