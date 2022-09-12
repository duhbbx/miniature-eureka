//
// Created by duhbb on 2022/9/13.
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


class Solution {
public:

        int get(const vector<int>& nums) {
            int res = 0;

            for (int i = nums.size() - 1; i >= 0; --i) {
                res = res * 10 + nums[i];
            }

            return res;
        }

    int maximumSwap(int num) {

            int p = num;
            if (num < 10) return num;
        vector<int> digits;

        while(num) {
            digits.push_back(num % 10);
            num = num / 10;
        }


        int n = digits.size();

        int res = p;

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(digits[i], digits[j]);
                int tmp = get(digits);
                if (tmp > res) {
                    res = tmp;
                }
                swap(digits[i], digits[j]);
            }
        }



        return res;
    }
};



////////////////////////////////////////////////////////////////////////////////




void printCurrentFileName() {
    string file = __FILE__;
    int pos = file.find_last_of("/");
    string fileName = pos == -1 ? file : file.substr(pos+1);
    cout << "\n【当前题目为：" << fileName << "】" << endl;
}





int main() {


    printCurrentFileName();

    cout << INT_MAX << endl;


    Solution solution;

    cout << solution.maximumSwap(10) << endl;

    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}