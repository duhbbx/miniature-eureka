//
// Created by tuhooo on 2022/9/22.
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
    bool canFormArray(vector<int> &arr, vector<vector<int>> &pieces) {

        unordered_map<int, vector<int> *> um;
        for (auto &p: pieces) um.emplace(p[0], &p);

        int p = 0;
        while (p < arr.size()) {
            if (um.find(arr[p]) == um.end()) return false;
            vector<int> *cur = um[arr[p]];

            for (int i = 0; i < cur->size(); ++i) {

                if (p == arr.size()) {
                    return false;
                }

                if (arr[p] == (*cur)[i]) {
                    ++p;
                }
            }
        }


        return p == arr.size();
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


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}