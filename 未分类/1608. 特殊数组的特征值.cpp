//
// Created by duhbb on 2022/9/12.
//


#include <iostream>              // 输入输出
#include <vector>                // 可变长度数组
#include <unordered_map>         // hashmap
#include <stack>                 // 栈
#include <string>                // 字符串
#include <queue>                 // 队列
#include <climits>               // 极限值
#include <algorithm>             // 算法相关的
#include "../0000 API 模板 类/TreeNode.h"
#include "../0000 API 模板 类/ListNode.h"

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


/**
 * 排序，然后二分，用了 c++ 里面的一个工具
 */

class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i <= n; i++) {
            int index = std::lower_bound(nums.begin(), nums.end(), i) - nums.begin();
            if (n - index == i) {
                return i;
            }
        }
        return -1;
    }
};



////////////////////////////////////////////////////////////////////////////////




void printCurrentFileName() {
    string file = __FILE__;
    int pos = file.find_last_of("/");
    string fileName = pos == -1 ? file : file.substr(pos+1);
    cout << "【当前题目为：" << fileName << "】" << endl;
}





int main() {


    printCurrentFileName();

    Solution solution;

    vector<int> nums = {3, 5};
    solution.specialArray(nums);


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}