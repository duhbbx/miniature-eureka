//
// Created by duhbb on 2022/9/19.
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
#include "../0000 API 模板 类/TreeNode.h"
#include "../0000 API 模板 类/ListNode.h"
#include <unordered_map>


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

    static unordered_map<int, int> m;

    static bool compare(int a, int b) {
        if (m[a] < m[b]) {
            return true;
        } else if (m[a] == m[b]) {
            return a > b;
        }
        return false;
    }

    vector<int> frequencySort(vector<int> &nums) {

        m.clear();

        for (auto i : nums) {
            m.find(i) == m.end() ? m[i] = 1 : ++m[i];
        }

        sort(nums.begin(), nums.end(), compare);
        return nums;
    }
};

unordered_map<int, int> Solution::m;

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


    vector<int> nums = {1, 2, 2, 3, 4, 1, 1};


    solution.frequencySort(nums);


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}