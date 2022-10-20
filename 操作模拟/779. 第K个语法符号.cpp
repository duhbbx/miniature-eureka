//
// Created by tuhooo on 2022/10/20.
//

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
    int kthGrammar(int n, int k) {

        vector<int> path;   // 从最底层爬到顶点的路径
        int p = k;  // 记录当前位置

        while(p) {
            path.push_back(p % 2 ? 1 : 0);
            p >>= 1;
        }

        int top = 0;
        for (int i = path.size()-1; i >= 0; --i) {
            if (top == 0) {
                top = path[i] ? 1 : 0;
            } else {
                top = path[i] ? 0 : 1;
            }
        }

        return top;
    }
};


int main() {


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}