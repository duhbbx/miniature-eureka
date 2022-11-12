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


class cmp {
public:
    //重载 () 运算符
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) {
        if (a.first < b.first) {
            return false;
        } else if (a.first > b.first) {
            return true;
        } else {
            if (a.second < b.second) {
                return false;
            } else if (a.second > b.second) {
                return true;
            } else {
                return false;
            }
        }
    }
};


class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {


        int n = costs.size();
        priority_queue<pair<int, int>, vector<pair<int,int>>, cmp> pq1;
        priority_queue<pair<int, int>, vector<pair<int,int>>, cmp> pq2;

        for (int i = 0; i < candidates; ++i) {
            pq1.emplace(costs[i], i);
            pq2.emplace(costs[n-i-1], i);
        }

        int left = candidates - 1;
        int right = n - candidates - 1;


        cmp c;
        int res = 0;

        for (int i = 0; i < k; ++i) {

            if (n - i < candidates) {
                if (left > right) {
                    res += pq1.top().first;
                    pq1.pop();
                } else {
                    res += pq2.top().first;
                    pq2.pop();
                }

            } else {

                if (c.operator()(pq1.top(), pq2.top())) {
                    res += pq1.top().first;
                    pq1.pop();
                    ++left;
                    pq1.emplace(costs[left], left);
                } else {
                    res += pq2.top().first;
                    pq2.pop();
                    --right;
                    pq1.emplace(costs[right], right);
                }

            }


        }

        return res;


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