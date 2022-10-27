//
// Created by duhbb on 2022/10/27.
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

private:
    /**
 * 并查集的底层数组
 */
    vector<int> unionSet;

    /**
     * 寻找根节点
     */
    int find(int i) {
        if (unionSet[i] == i) {
            return i;
        } else {
            unionSet[i] = find(unionSet[i]);    // 路径压缩
            return unionSet[i];
        }
    }

public:

    Solution() : unionSet(1000, 0) {}


    bool canVisitAllRooms(vector<vector<int>> &rooms) {

        int n = rooms.size();

        // 初始化并查集
        for (int i = 0; i < n; ++i) {
            unionSet[i] = i;
        }

        // 这里的两个for循环其实还是merge操作
        for (int i = 0; i < n; ++i) {
            int root = find(i);     // 找到当前房间的根

            for (auto &j: rooms[i]) {
                int keyRoot = find(j);
                // keyRoot有三种情况
                // keyRoot == 0 说明之前已经访问了
                // keyRoot == j 说明 j 是第一次被访问, 自然 j 对应的 root 就是 root
                // keyRoot != 0 && keyRoot != j
                if (keyRoot == 0) {
                    continue;
                }

                unionSet[keyRoot] = root;
            }
        }

        int rootCount = 0;
        for (int i = 0; i < n; ++i) {
            if (unionSet[i] == i)   // 节点的root是自己的话, 则是一个根
                ++rootCount;        // 节点计数+1
            if (rootCount > 1)      // 一旦发现根节点的个数大于1,可立即返回false
                return false;
        }

        return true;
    }
};


int main() {


    Solution solution;

    vector<vector<int>> rooms = {{},
                                 {3},
                                 {3},
                                 {}};

    solution.canVisitAllRooms(rooms);


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}