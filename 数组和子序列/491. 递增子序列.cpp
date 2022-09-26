//
// Created by duhbb on 2022/9/25.
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
    string fileName = pos == -1 ? file : file.substr(pos + 1);
    cout << "\n【当前题目为：" << fileName << "】" << endl;
}




////////////////////////////////////////////////////////////////////////////////
/// 这里放OJ的类

class Solution {
public:


#define MAXN 1000
    int fa[MAXN];
    int rank[MAXN];


    inline void init(int n) {
        for (int i = 0; i < n; ++i) {
            fa[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        return x == fa[x] ? x : (fa[x] = find(fa[x]));
    }

    inline void merge(int i, int j) {
        int x = find(i), y = find(j);
        if (rank[x] <= rank[y])
            fa[x] = y;
        else
            fa[y] = x;

        if (rank[x] == rank[y] && x != y)
            rank[y]++;
    }



    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        init(edges.size());

        for (auto& e : edges) {
            if (find(e[0]) == find(e[1])) return e;
            merge(e[0], e[1]);
        }

        return {};
    }
};
////////////////////////////////////////////////////////////////////////////////

int main() {
    printCurrentFileName();
    vector<int> nums = {4,7,4,7};
    Solution solution;
    solution.findSubsequences(nums);
    /*print<vector<int>>({ 1, 2, 3, 4 });*/
    return 0;
}