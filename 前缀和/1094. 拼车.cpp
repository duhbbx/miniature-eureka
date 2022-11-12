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
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        vector<int> passengersPerMile(1002, 0);
        vector<int> passengersOutPerMile(1002, 0);


        int maxDest = 0;
        for (auto& trip : trips) {
            passengersPerMile[trip[1]] += trip[0];
            passengersOutPerMile[trip[2]] += trip[0];
            maxDest = max(trip[2], maxDest);
        }

        for (int i = 1; i <= maxDest; ++i) {
            passengersPerMile[i] = passengersPerMile[i] + passengersPerMile[i-1];
            passengersOutPerMile[i] = passengersOutPerMile[i] + passengersOutPerMile[i-1];
        }

        for (int i = 0; i <= maxDest; ++i) {
            if (passengersPerMile[i] - passengersOutPerMile[i] > capacity) {
                return false;
            }
        }

        return true;
    }
};

int main() {


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}