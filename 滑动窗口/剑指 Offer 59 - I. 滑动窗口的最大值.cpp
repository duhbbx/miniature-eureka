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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> queue1;

        int n = nums.size();

        vector<int> res;

        for (int i = 0; i < n; ++i) {
            if (!queue1.empty() && i - queue1.front() >= k) {
                queue1.pop_front();
            }

            while(!queue1.empty() && nums[queue1.back()] < nums[i]) {
                queue1.pop_back();
            }

            queue1.push_back(i);

            if (i >= k - 1) {
                res.push_back(nums[queue1.front()]);
            }
        }

        return res;


    }
};


int main() {


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}