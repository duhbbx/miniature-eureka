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



class Solution {
public:


    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> in(numCourses, 0);                 // 顶点的入度
        vector<vector<int>> g(numCourses, vector<int>());       // 邻接表


        vector<int> res;

        for (auto& p : prerequisites) {
            g[p[1]].push_back(p[0]);
            ++in[p[0]];
        }


        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (in[i] == 0) { q.push(i); }
        }

        while(!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; ++i) {
                int curr = q.front();
                res.push_back(curr);
                q.pop();
                for (auto& v : g[curr]) if (!--in[v])  q.push(v);
            }
        }

        vector<int> empty;
        return res.size() == numCourses ? res : empty;
    }
};