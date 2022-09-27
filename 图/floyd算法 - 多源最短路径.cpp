//
// Created by duhbb on 2022/9/27.
//
//
// Created by tuhooo on 2022/9/27.
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
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        vector<int> res;

        if (n == 1) {
            res.push_back(0);
            return res;
        }


        vector<vector<int>> g(n, vector<int>(n, (int) 1e9+5));

        for (auto& e : edges) {
            g[e[0]][e[1]] = 1;
            g[e[1]][e[0]] = 1;
        }



        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }

        unordered_map<int, int> m;

        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (g[i][j] > m[i]) {
                    m[i] = g[i][j];
                }

                if (g[i][j] > m[j]) {
                    m[j] = g[i][j];
                }
            }
        }

        int minimum = INT_MAX;
        for (auto& p : m) {
            if (p.second < minimum) {
                minimum = p.second;
            }
        }


        for (auto& p : m) {
            if (p.second == minimum) {
                res.push_back(p.first);
            }
        }

        return res;

    }
};

////////////////////////////////////////////////////////////////////////////////

int main() {


    printCurrentFileName();


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}