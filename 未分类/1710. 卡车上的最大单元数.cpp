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
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {


        sort(boxTypes.begin(), boxTypes.end(),
             [&](const vector<int> &a, vector<int> &b) -> bool {
                 return a[1] > b[1];
             });

//        for (auto &box: boxTypes) {
//            cout << box[1] << ", ";
//        }
//        cout << endl;


        int res = 0;
        for (auto &box: boxTypes) {
            if (truckSize < 1) {
                break;
            }

            int fetch = min(truckSize, box[0]);

            res += fetch * box[1];
            truckSize -= fetch;
        }
        return res;
    }

};


int main() {


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}