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
    int longestWPI(vector<int>& hours) {

        int n = hours.size();

        set<int> set1;
        map<int, int> map1;

        map1[0] = -1;
        set1.insert(0);

        int sum = 0;
        int res = 0;
        for (int i = 0; i < n; ++i) {

            sum += hours[i] > 8 ? 1 : -1;



            if (!set1.empty()) {
                int s = *set1.begin();
                if (sum > s) {
                    res = max(res, i - map1[s] + 1);
                }
            }

            if (map1.count(sum) == 0) {
                map1[sum] = i;
                set1.insert(sum);
            }
        }

        return res;
    }
};

int main() {


    Solution solution;


    vector<int> hours = {6, 9, 9};

    solution.longestWPI(hours);

    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}