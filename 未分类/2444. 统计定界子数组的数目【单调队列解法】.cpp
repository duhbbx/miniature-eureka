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
    long long countSubarrays(const vector<int>& nums, int minK, int maxK) {
        const int n = nums.size();
        long long ans = 0;

        // 相当于设置了4个队列
        int q1[n], l1 = 0, r1 = 0;
        int q2[n], l2 = 0, r2 = 0;
        int q3[n], l3 = 0, r3 = 0;
        int q4[n], l4 = 0, r4 = 0;


        int p1 = -1, p2 = -1, p3 = -1, p4 = -1;


        for (int i = 0;i < n;++i) {
            while (l1 < r1 && nums[q1[r1 - 1]] > nums[i])
                --r1;
            q1[r1++] = i;
            while (l1 < r1 && nums[q1[l1]] < minK)
                p1 = q1[l1++];
            while (l2 < r2 && nums[q2[r2 - 1]] > nums[i])
                --r2;
            q2[r2++] = i;
            while (l2 < r2 && nums[q2[l2]] <= minK)
                p2 = q2[l2++];
            while (l3 < r3 && nums[q3[r3 - 1]] < nums[i])
                --r3;
            q3[r3++] = i;
            while (l3 < r3 && nums[q3[l3]] > maxK)
                p3 = q3[l3++];
            while (l4 < r4 && nums[q4[r4 - 1]] < nums[i])
                --r4;
            q4[r4++] = i;
            while (l4 < r4 && nums[q4[l4]] >= maxK)
                p4 = q4[l4++];
            ans += max(min(p2, p4) - max(p1, p3), 0);
        }
        return ans;
    }
};


//作者：endlesscheng
//        链接：https://leetcode.cn/problems/count-subarrays-with-fixed-bounds/solution/jian-ji-xie-fa-pythonjavacgo-by-endlessc-gag2/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


int main() {


    vector<int> nums = {1,3,5,2,7,5};

    int minK = 1;
    int maxK = 5;

    Solution solution;

    solution.countSubarrays(nums, minK, maxK);

    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}