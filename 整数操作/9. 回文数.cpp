//
// Created by duhbb on 2022/9/11.
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
    bool isPalindrome(int x) {

        if (x < 0) {
            return false;
        }

        long reverse = 0;
        int a = x;
        while(x > 0) {
            // 这样可能存在溢出
            reverse = 10 * reverse + x % 10;
            x /= 10;
        }

        return a == reverse;

    }


    bool isPalindrome_1(int x) {

        if (x < 0) {
            return false;
        }

        vector<int> bit_vec = {};


        while(x) {
            bit_vec.push_back(x % 10);
            x /= 10;
        }

        // print(bit_vec);

        int size = bit_vec.size();

        int i = 0;
        int j = size-1;

        while(i < j) {
            if (bit_vec[i] != bit_vec[j]) {
                return false;
            }
            ++i;
            --j;
        }

        return true;
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

    Solution s;

    s.isPalindrome(10);


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}