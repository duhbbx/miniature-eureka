//
// Created by tuhooo on 2022/10/31.
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
    int magicalString(int n) {

        if (n <= 3) {       // n <= 3 时, s 最多只有一个 '1'
            return 1;
        }

        int res = 1;
        queue<char> q;
        q.push('2');        // 将 "122" 中的最后一个 2 入列
        int len = 3;        // 字符串当前长度
        while(len < n) {
            char front = q.front(); // 获取生成下一个分组的当前字符
            q.pop();                // 注意这里不要忘了弹出来
            int size = front - '0'; // 下一个分组的长度
            char nextGroupChar = '\0';
            if (q.back() == '1') {      // 通过队列的最后一个元素(即最后一个分组的最后一个元素)
                nextGroupChar = '2';    // 判断下一个分组的元素是啥
            } else {
                nextGroupChar = '1';
            }

            for (int i = 0; i < size; ++i) {
                if (nextGroupChar == '1') {
                    ++res;
                }
                q.push(nextGroupChar);  // 将当前生成的分组中的元素入列
                ++len;                  // 字符串长度+1
                if (len == n) {         // 如果满足了当前长度则可以终端循环
                    break;
                }
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