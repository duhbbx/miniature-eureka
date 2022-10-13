//
// Created by duhbb on 2022/10/13.
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

const int M = 110;
const int N = 6010;
#define UN_REACH_ABLE 0x3f3f3f3f

class Solution {
public:

    int idx;
    int head[M];    // 节点最多 M 个
    int to[N];      // 边指向的点
    int pre[N];     // 上一条边序号
    int weight[N];  // 权重
    int dist[M];    // 记录起始点到各个其他点的距离
    bool visit[M];


    void add(int a, int b, int w) {
        to[idx] = b;        // 第 idx 条边指向的终点
        pre[idx] = head[a]; // 第 idx 条边的上一条
        weight[idx] = w;
        head[a] = idx++;    // 当前边
    }


    int networkDelayTime(const vector<vector<int>> &times, int n, int k) {
        idx = 0;

        memset(head, -1, sizeof(head)); // 将 head 都置为 -1
        memset(dist, 0x3F, sizeof(dist));
        memset(visit, 0, sizeof(visit));

        for (auto &t: times) {
            add(t[0], t[1], t[2]);
        }

        dist[k] = 0;    // 到自己的时间为 0
        const auto &dfs = [&](auto &&self, int k) -> void {
            for (int i = head[k]; ~i; i = pre[i]) { // 遍历每条边
                int v = to[i];                      // k 是边 i 的起点, v 是边 i 的终点
                if (dist[k] + weight[i] < dist[v]) {
                    dist[v] = dist[k] + weight[i];

                    self(self, v);

                }
            }
        };

        dfs(dfs, k);
        int max_time = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == UN_REACH_ABLE) {
                return -1;
            }

            max_time = max(dist[i], max_time);
        }

        return max_time == UN_REACH_ABLE ? -1 : max_time;
    }
};
////////////////////////////////////////////////////////////////////////////////

int main() {


    printCurrentFileName();


    Solution solution;

    // solution.networkDelayTime({{2,1,1}, {2,3,1}, {3,4,1}}, 4, 2);
    solution.networkDelayTime({{1,2,1}}, 2, 2);


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}