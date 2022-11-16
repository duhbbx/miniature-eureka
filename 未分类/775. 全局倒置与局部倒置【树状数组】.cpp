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
    int n;
    vector<int> tr;

    int lowbit(int x) {
        return x & -x;
    }

    void add(int x) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tr[i]++;
        }

    }

    int query(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += tr[i];
        }

        return ans;
    }

    bool isIdealPermutation(vector<int> &nums) {
        n = nums.size();
        tr = vector<int>(n + 10);   // 树状数组
        add(nums[0] + 1);
        long a = 0, b = 0;
        for (int i = 1; i < n; i++) {
            a += query(n) - query(nums[i] + 1); // 统计全局转置的数量
            b += nums[i] < nums[i - 1] ? 1 : 0; // 统计局部转置的数量
            add(nums[i] + 1);
        }
        return a == b;
    }
};

int main() {


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}