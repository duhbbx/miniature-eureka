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


class Solution {
public:

    string get(int x, const string& base, const string& mid, const string& large) {

        switch (x) {
            case 0:
                return "";
            case 1:
                return base;
            case 2:
                return base + base;
            case 3:
                return base + base + base;
            case 4:
                return base + mid;
            case 5:
                return mid;
            case 6:
                return mid+base;
            case 7:
                return mid+base+base;
            case 8:
                return mid + base + base + base;
            case 9:
                return base + large;
        }

        return "";
    }

    string intToRoman(int num) {


        int thou = num / 1000;
        int hund = (num % 1000) / 100;
        int deci = (num % 100) / 10;
        int digi = num % 10;

        return get(thou, "M", "", "") + get(hund, "C", "D", "M") + get(deci, "X", "L", "C") + get(digi, "I", "V", "X");
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


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}