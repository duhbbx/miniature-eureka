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

    int toIndex(string &s) {
        vector<int> month2Day = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int month = stoi(s.substr(0, 2));
        int day = stoi(s.substr(3, 2));
        int sum = 0;

        for (int i = 1; i < month; ++i) {
            sum += month2Day[i - 1];
        }
        return sum + day;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {

        int arriveAliceInt = toIndex(arriveAlice);
        int leaveAliceInt = toIndex(leaveAlice);
        int arriveBobInt = toIndex(arriveBob);
        int leaveBobInt = toIndex(leaveBob);


        if (leaveAliceInt < arriveBobInt || leaveBobInt < arriveAliceInt) {
            return 0;
        }


        return min(leaveAliceInt, leaveBobInt) - max(arriveAliceInt, arriveBobInt) + 1;


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

    cout << solution.countDaysTogether("08-15", "08-18","08-16", "08-19" ) << endl;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}