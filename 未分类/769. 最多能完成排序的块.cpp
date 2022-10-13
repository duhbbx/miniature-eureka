//
// Created by tuhooo on 2022/10/13.
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

void printCurrentFileName() {
    string file = __FILE__;
    int pos = file.find_last_of("/");
    string fileName = pos == -1 ? file : file.substr(pos+1);
    cout << "\n【当前题目为：" << fileName << "】" << endl;
}




////////////////////////////////////////////////////////////////////////////////
/// 这里放OJ的类

class Solution {
public:
    int maxChunksToSorted(const vector<int>& arr) {



        int left = 0;
        int right = arr.size() - 1;

        int res = 0;
        for (int i = left; i <= right-1; ++i) {

            int leftMax = 0;
            for (int j = left; j <= i; ++j) {
                leftMax = max(leftMax, arr[j]);
            }

            int rightMin = 10000;
            for (int k = i + 1; k <= right; ++k) {
                rightMin = min(rightMin, arr[k]);
            }

            if (leftMax < rightMin) {
                ++res;
                left = i + 1;
            }
        }

        return ++res;
    }
};

////////////////////////////////////////////////////////////////////////////////

int main() {


    printCurrentFileName();


    Solution solution;

    solution.maxChunksToSorted({1, 0, 2, 3 ,4});


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}