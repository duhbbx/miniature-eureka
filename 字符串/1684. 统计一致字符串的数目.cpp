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
    int countConsistentStrings(string allowed, vector<string>& words) {

        int a[26];
        memset(a, 0, sizeof(a));

        for (char c: allowed) {
            a[c - 'a'] = 1;
        }

        int res = 0;

        for (auto &s: words) {

            int accord = 1;

            for (auto &c: s) {
                if (a[c - 'a'] != 1) {
                    accord = 0;
                    break;
                }
            }

            if (accord) {
                ++res;
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