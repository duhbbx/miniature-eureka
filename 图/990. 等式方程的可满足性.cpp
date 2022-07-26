//
// Created by tuhooo on 2022/11/2.
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


class UnionSet {

private:
    vector<int> fa;
    int n;
public:

    UnionSet(int n) {
        this->n = n;
        fa = vector<int>(100, 0);
        iota(fa.begin(), fa.end(), 0);
    }

    int find(int x) {
        if (fa[x] == x) {
            return x;
        } else {
            fa[x] = find(fa[x]);
            return fa[x];
        }
    }

    void merge(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx == fy) {
            return;
        }
        fa[fx] = fy;
    }
};


class Solution {
public:
    bool equationsPossible(vector<string>& equations) {

        UnionSet usForEqual(26);


        for (string& e : equations) {
            if (e[1] == '=') {
                usForEqual.merge(e[0] - 'a', e[3] - 'a');
            }
        }


        for (string& e : equations) {
            if (e[1] == '!') {
                if(usForEqual.find(e[0] - 'a') == usForEqual.find(e[3] - 'a')) {
                    return false;
                }
            }
        }

        return true;

    }
};





int main() {


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}