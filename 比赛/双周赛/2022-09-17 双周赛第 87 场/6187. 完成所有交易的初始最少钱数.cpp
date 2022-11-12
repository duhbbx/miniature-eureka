//
// Created by duhbb on 2022/9/17.
//
//
// Created by duhbb on 2022/9/17.
//
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
#include "../../../0000 API 模板 类/TreeNode.h"
#include "../../../0000 API 模板 类/ListNode.h"


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

/*
 *
 * [[2,1],[5,0],[4,2]]
[[3,0],[0,3]]
 *
 *
 */

bool compare(vector<int> & a, vector<int>& b) {

    return a[1] < b[1];
}

class Solution {
public:



    long long minimumMoney(vector<vector<int>>& transactions) {

        sort(transactions.begin(), transactions.end(), compare);


        long long max = 0;
        long long remain = 0;

        for (auto& i : transactions) {

            if (remain == 0) {
                max += i[0];
                remain += i[1];
            } else if (remain <= i[0]) {
                max += i[0] - remain;
                remain = i[1];
            } else {
                remain -= i[0] - i[1];
            }
        }


        return max;
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


    vector<vector<int>> nums = {{2,1},{5,0},{4,2}};
    Solution solution;

    solution.minimumMoney(nums);

    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}