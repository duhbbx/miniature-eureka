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

    int s[100];

    int subarraySum(int len, int t) {

        unordered_map<int, int> m;
        m[0] = 1;

        int count = 0, pre = 0;

        for (int i = 0; i < len; ++i) {
            auto x = s[i];
            pre += x;
            if (m.find(pre - t) != m.end()) {
                count += m[pre-t];
            }
            ++m[pre];
        }

        return count;
    }

    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {

        auto& m = matrix;
        int r = matrix.size();
        int c = matrix[0].size();
        auto& t = target;
        int ans = 0;
        for (int i = 0; i < r; ++i) {
            memset(s, 0, sizeof(s));
            for (int j = i; j < r; ++j) {
                for (int k = 0; k < c; ++k) {
                    s[k] += m[j][k];
                }

                ans += subarraySum(c, t);
            }


        }

        return ans;
    }
};


int main() {


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}