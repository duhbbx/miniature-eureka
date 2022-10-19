//
// Created by tuhooo on 2022/10/19.
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
    string fileName = pos == -1 ? file : file.substr(pos + 1);
    cout << "\n【当前题目为：" << fileName << "】" << endl;
}




////////////////////////////////////////////////////////////////////////////////
/// 这里放OJ的类

class Solution {
public:
    int countStudents(const vector<int> &students, const vector<int> &sandwiches) {


        int p = 0;

        vector<int>* remain1 = new vector<int>;
        vector<int>* remain2 = new vector<int>;

        for (int i = 0; i < students.size(); ++i) {
            if (sandwiches[p] == students[i]) {
                ++p;
            } else {
                remain1->push_back(students[i]);
            }
        }

        while(true) {

            for (int i = 0; i < remain1->size(); ++i) {
                if (sandwiches[p] == (*remain1)[i]) {
                    ++p;
                } else {
                    remain2->push_back((*remain1)[i]);
                }
            }

            if (remain2->size() == remain1->size()) {
                break;
            }
            swap(remain1, remain2);
            remain2->clear();
        }

        return sandwiches.size() - p;
    }
};



////////////////////////////////////////////////////////////////////////////////

int main() {


    printCurrentFileName();


    Solution solution;

    solution.countStudents({1,1,0,0},  {0,1,0,1});


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}