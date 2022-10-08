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
#include <stdlib.h>
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

/*


class Solution {
public:


    vector<int> findMinHeightTrees(int n, const vector<vector<int>> &edges) {

        vector<vector<int>> adj(n, vector<int>());


        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> tree(n, -1);

        auto bfs = [&](int start) -> int {
            queue<int> q;
            vector<bool> visited(n, false);
            q.emplace(start);



            int last = 0;

            while(!q.empty()) {
                int len = q.size();

                for (int i = 0; i < len; ++i) {
                    int cur = q.front();
                    q.pop();


                    last = cur;
                    for (auto& j : adj[cur]) {
                        if (!visited[j]) {
                            tree[j] = cur;
                            q.emplace(j);
                            visited[cur] = true;
                        }

                    }
                }
            }
            return last;
        };

//        cout << "11111" << endl;

        int x = bfs(0);
//        cout << "11111222222" << endl;
tree[x] = -1;
        int y = bfs(x);
//        cout << "33333333" << endl;
        vector<int> path;

//        cout << "x = " << x  << ", y = " << y << endl;

        while(tree[y] != -1) {
            path.push_back(y);
            y = tree[y];
        }

        // cout << "22222" << endl;

        path.push_back(x);

        if (path.size() % 2 == 0) {
            return {path[(0 + path.size() - 1) >> 1], path[((0 + path.size() - 1) >> 1) + 1]};
        } else {
            return {path[(0 + path.size() - 1) >> 1]};
        }
    }
};

*/


const int N = 20010;

class Solution {
public:
    int idx;
    int h[N];
    int e[N << 1];
    int ne[N << 1];
    int in[N];

    int ql;
    int qr;
    int q[N];
    int dep[N];

    void add(int a, int b) {
        e[idx] = b;         //
        in[b] += 1;         // in 是入度, 就是从 a 到 b
        ne[idx] = h[a];
        h[a] = idx++;
    }

    vector<int> findMinHeightTrees(int n, const vector<vector<int>> &edges) {
        idx = 0;
        ql = 1;
        qr = 0;

        memset(h, -1, sizeof(h));

        for (int i = 0; i < n - 1; ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            add(u, v);
            add(v, u);
        }

        // q 实际上是个队列, 将入度为 1 的节点都入列
        for (int i = 0; i < n; ++i)
            if (in[i] == 1)     // 将入度为 1 的点先入列
                q[++qr] = i;    // 队列从 1 开始


        while (ql <= qr) {      // ql 最开始是 1, qr 是队列的最后一个节点
            int u = q[ql++];    // 获取最开始的一个节点, 并将队列的头后移一个
            for (int i = h[u]; ~i; i = ne[i]) { // 用跳的方法获取邻接点
                int v = e[i];                   // 获取到了邻接点
                if (--in[v] == 1) {             // 如果去掉了当前点的边, 入度为 1
                    dep[v] = dep[u] + 1;        // 则 v 的深度加 1
                    q[++qr] = v;                // 将 v 入列
                }
            }
        }

        int maxD = *max_element(dep, dep + n);  // 求 dep 的最大值
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (dep[i] == maxD)
                res.push_back(i);
        }
        return res;
    }
};



////////////////////////////////////////////////////////////////////////////////

int main() {


    printCurrentFileName();


    Solution solution;

    solution.findMinHeightTrees(4, {{1, 0},
                                    {1, 2},
                                    {1, 3}});


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}