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


    int minMoves(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int> pos(n);

        int index = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                pos[index++] = i;
            }
        }

        int ans = 0, count = 0, mid = k / 2;

        for (int i = 1; i < k; ++i) {
            count += (pos[i] - pos[i-1] - 1) * min(i, k - i);
        }

        ans = count;

        for (int i = k; i < index; ++i) {
            count -= pos[i - k + mid] - pos[i - k];
            count += pos[i] - pos[i - mid];
            ans = min(ans, count);
        }



        return ans;
    }


};


int main() {


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}