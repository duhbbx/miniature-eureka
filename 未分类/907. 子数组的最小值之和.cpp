//
// Created by tuhooo on 2022/10/28.
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


class Solution {
    const int mod = 1e9 + 7;    // 用来取余的数
public:
    int sumSubarrayMins(vector<int> &arr) {
        int n = arr.size();
        vector<int> p(n), fa(n), l(n), r(n), vis(n);
        iota(p.begin(), p.end(), 0);
        iota(fa.begin(), fa.end(), 0);
        iota(l.begin(), l.end(), 0);
        iota(r.begin(), r.end(), 0);
        sort(p.begin(), p.end(), [&](int i, int j) {
            return arr[i] > arr[j];
        });


        auto get = [&](int x) { // 并查集的找根操作, find
            while (x != fa[x]) x = fa[x] = fa[fa[x]];
            return x;
        };
        auto merge = [&](int u, int v) {    // 并查集的合并操作, merge
            int fu = get(u), fv = get(v);   // 先获取需要合并的两个点的父节点
            if (fu != fv) {
                l[fu] = min(l[fu], l[fv]);  // 更新左节点
                r[fu] = max(r[fu], r[fv]);  // 更新右节点
                fa[fv] = fu;                // 合并
            }
        };
        int ans = 0;
        for (auto i: p) {
            if (i + 1 < n && vis[i + 1]) merge(i, i + 1);
            if (i && vis[i - 1]) merge(i, i - 1);
            vis[i] = 1;
            auto f = get(i);
            ans = (ans +
                   1ll * (i - l[f] + 1) * (r[f] - i + 1) % mod * arr[i] % mod) %
                  mod;
        }
        return ans;
    }
};

int main() {


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}