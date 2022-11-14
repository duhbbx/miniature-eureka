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


// TODO 我写的
class Solution_1 {
public:
    long long countSubarrays(vector<int> &nums, int min_k, int max_k) {


        int n = nums.size();

        int res = 0;
        int out = -1, last_min = -1, last_max = -1;

        for (int i = 0; i < n; ++i) {
            int x = nums[i];

            if (x == min_k) {
                last_min = i;
            }

            if (x == max_k) {
                last_max = i;
            }

            if (x < min_k || x > max_k) {
                out = i;
            }

            res += max(min(last_min, last_max) - out, 0);
        }

        return res;
    }
};


// TODO 大佬写的
class Solution2 {
public:
    long long countSubarrays(vector<int> &nums, int min_k, int max_k) {
        long long ans = 0L;
        int n = nums.size(), min_i = -1, max_i = -1, i0 = -1;
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            if (x == min_k) min_i = i;
            if (x == max_k) max_i = i;
            if (x < min_k || x > max_k) i0 = i; // 子数组不能包含 nums[i0]
            ans += max(min(min_i, max_i) - i0, 0);
        }
        return ans;
    }
};


//作者：endlesscheng
//        链接：https://leetcode.cn/problems/count-subarrays-with-fixed-bounds/solution/jian-ji-xie-fa-pythonjavacgo-by-endlessc-gag2/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


int main() {


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}