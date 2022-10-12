//
// Created by tuhooo on 2022/10/10.
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

class Solution_of_myself {
public:
    vector<double>
    calcEquation(vector<vector<string>> &equations, vector<double> &values,
                 vector<vector<string>> &queries) {

        vector<double> res;
        unordered_map<string, unordered_map<string, double>> g;

        for (int i = 0; i < equations.size(); ++i) {
            auto &e = equations[i];
            g[e[0]][e[1]] = values[i];
            g[e[1]][e[0]] = 1 / values[i];
        }

        auto dfs = [&](string curr, string end, unordered_set<string> visited,
                       auto &&self) -> double {

            if (g.find(curr) == g.end()) {
                return -1;
            }

            if (curr == end) {
                return 1;
            }

            if (visited.find(curr) != visited.end()) {
                return -1;
            }

            visited.emplace(curr);
            for (auto &edges: g[curr]) {
                double result =
                        edges.second * self(edges.first, end, visited, self);
                if (result >= 0) {
                    return result;
                }
            }
            visited.erase(curr);
            return -1;
        };

        unordered_set<string> visited;
        for (auto &q: queries) {
            visited.clear();
            res.push_back(dfs(q[0], q[1], visited, dfs));
        }

        return res;
    }
};


class Solution {
    vector<int> f;
    vector<double> w;

public:
    int find1(int x) {
        if (f[x] != x) {
            int father = find1(f[x]);
            w[x] = w[x] * w[f[x]];
            f[x] = father;
        }
        return f[x];
    }

    void meger(int x, int y, double val) {
        int fa = find1(x);
        int fb = find1(y);
        f[fa] = fb;
        w[fa] = w[y] / w[x] * val;    // 沃日, 牛逼, 并查集还能这么用
    }


    vector<double>
    calcEquation(vector<vector<string>> &equations, vector<double> &values,
                 vector<vector<string>> &queries) {
        int n = 0;
        int len = equations.size();
        unordered_map<string, int> m;
        for (auto &e: equations) {      // 相当于给字符串的数字编号了
            if (m.count(e[0]) == 0)m[e[0]] = n++;
            if (m.count(e[1]) == 0)m[e[1]] = n++;
        }
        f.resize(n);                    // vector 的长度增长到 n 个
        iota(f.begin(), f.end(), 0);    // 将其值都转为 0
        w.resize(n, 1.0);               // 权重长度为 n, 每个元素值为0
        for (int i = 0; i < len; i++) { // 组装并查集
            int fa = m[equations[i][0]];
            int fb = m[equations[i][1]];
            meger(fa, fb, values[i]);
        }
        vector<double> ans;
        for (auto &q: queries) {
            double ret = -1.0;
            if (m.count(q[0]) && m.count(q[1])) {
                int fa = find1(m[q[0]]);
                int fb = find1(m[q[1]]);
                if (fa == fb) {
                    ret = w[m[q[0]]] / w[m[q[1]]];
                }
            }
            ans.push_back(ret);
        }
        return ans;
    }
};

////////////////////////////////////////////////////////////////////////////////

int main() {


    printCurrentFileName();


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}