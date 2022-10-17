//
// Created by tuhooo on 2022/10/17.
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
    string fileName = pos == -1 ? file : file.substr(pos+1);
    cout << "\n【当前题目为：" << fileName << "】" << endl;
}




////////////////////////////////////////////////////////////////////////////////
/// 这里放OJ的类

class Solution {
public:
    bool possibleBipartition(int n, const vector<vector<int>>& dislikes) {

        vector<int> group(n+1, -1);
        vector<vector<int>> g(n+1, vector<int>());
        vector<int> visited(n+1, false);

        for (auto &d : dislikes) {
            g[d[0]].push_back(d[1]);
            g[d[1]].push_back(d[0]);
        }


        queue<int> qu;
        qu.emplace(1);

        int visited_num = 0;
        int start = 1;

        while(!qu.empty()) {
            int len = qu.size();

            for (int i = 0; i < len; ++i) {


                int cur = qu.front();

                int cur_flag = group[cur];
                if (cur_flag == -1) {
                    group[cur] = 0;
                }

                for (auto &dislike : g[cur]) {
                    if (visited[dislike] == 0) {
                        qu.emplace(dislike);
                        visited[dislike] = 1;
                    }

                    // 存在冲突则直接返回false
                    if (group[dislike] == group[cur]) {
                        return false;
                    }

                    group[dislike] = group[cur] == 0 ? 1 : 0;
                }

               cout << "cur = " << cur << endl;

                qu.pop();
                visited[cur] = 2;
                ++visited_num;
            }


            if (qu.empty() && visited_num != n) {
                while(visited[start] != 0) {
                    ++start;
                }

                cout << "visited_num = " << visited_num << ", start = " <<  start << endl;
                qu.emplace(start);
                visited[start] = 1;
            }


        }

        return true;
    }
};

////////////////////////////////////////////////////////////////////////////////

int main() {


    printCurrentFileName();


    Solution solution;

    solution.possibleBipartition(5, {{1,2},{3,4},{4,5},{3,5}});


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}