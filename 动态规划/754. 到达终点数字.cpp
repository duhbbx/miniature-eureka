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
    int reachNumber(int target) {

        for (int i = 1; i < 10000000; ++i) {

            int sum = i * (i + 1) / 2;

            if (sum >= abs(target)) {

                if (sum % 2) {


                    if (target % 2) {


                        return i;




                    } else {
                        if (i % 4 == 1) {
                            return i + 2;
                        } else {
                            return i + 1;
                        }
                    }

                } else {


                    if (target % 2) {


                        if (i % 4 == 3) {
                            return i + 2;
                        } else {
                            return i + 1;
                        }

                    } else {
                        return i;
                    }
                }
            }
        }

        return 0;
    }
};


int main() {


    Solution solution;

    solution.reachNumber(2);


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}