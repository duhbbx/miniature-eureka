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
    int numTilings(int n) {
        vector<long> dp(n + 4, 0);

        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;

        int mod = 1000000007;

        for (int i = 4; i <= n; ++i) {

            dp[i] = (dp[i] + (2 * dp[i-3]) % mod);
            dp[i] = (dp[i] + (1 * dp[i-2]) % mod);
            dp[i] = (dp[i] + (1 * dp[i-1]) % mod);



            for (int j = i; j >= 4; j--) {
                dp[i] = (dp[i] + (dp[j-4] * 2) % mod);
            }
        }

        return dp[n] % mod;
    }
};



int main() {


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}