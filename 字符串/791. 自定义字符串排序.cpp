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
    string customSortString(string order, string s) {

        vector<int> orderHash(26);

        for (int i = 0; i < order.size(); ++i) {
            orderHash[order[i] - 'a'] = i;
        }

        sort(s.begin(), s.end(), [&](const char& a, const char& b) -> bool {
            return orderHash[a - 'a'] < orderHash[b - 'b'];
        });

        return s;
    }
};


int main() {


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}