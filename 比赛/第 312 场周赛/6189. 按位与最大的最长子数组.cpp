//
// Created by duhbb on 2022/9/17.
//
#include <iostream>              // 输入输出
#include <vector>                // 可变长度数组
#include <unordered_map>         // hashmap
#include <stack>                 // 栈
#include <string>                // 字符串
#include <queue>                 // 队列
#include <climits>               // 极限值
#include <algorithm>             // 算法相关的
#include <set>                   // 集合
#include "../../0000 API 模板 类/TreeNode.h"
#include "../../0000 API 模板 类/ListNode.h"


using namespace std;


template<typename T>
void print(T t) {


    if (t.empty()) {
        cout << "容器为空............" << endl;
        return;
    }


    for (typename T::const_iterator it = t.begin(); it != t.end() - 1; ++it) {
        cout << *it << ", ";
    }

    cout << *(t.end() - 1) << endl;
}



////////////////////////////////////////////////////////////////////////////////
/// 这里放OJ的类


class Solution {
public:
    int longestSubarray(vector<int>& nums) {


        if (nums.size() == 1) return 1;

        int max = -1;
        int res = -1;

        int p = 0, q = 1;

        while(q < nums.size()) {
            if (nums[q] == nums[p]) {
                ++q;
            } else {
                if (nums[p] > max) {
                    max = nums[p];
                    res = q - p;
                } else if (nums[p] == max && q - p > res) {
                    res = q - p;
                }
                p = q;
                ++q;
            }
        }

        if (nums[p] > max) {
            return q - p;
        } else if (nums[p] == max && q - p > res) {
            return q - p;
        }


        return res;
    }
};


////////////////////////////////////////////////////////////////////////////////




void printCurrentFileName() {
    string file = __FILE__;
    int pos = file.find_last_of("/");
    string fileName = pos == -1 ? file : file.substr(pos + 1);
    cout << "\n【当前题目为：" << fileName << "】" << endl;
}


int main() {


    printCurrentFileName();


    Solution solution;

    vector<int> nums = {96317,96317,96317,96317,96317,96317,96317,96317,96317,279979};
  auto o = solution.longestSubarray(nums);

 cout << o << endl;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}