//
// Created by duhbb on 2022/9/27.
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
#include <map>


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
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        unordered_map<string, map<string, int>> g;

        for (auto & e : tickets) {
            ++g[e[0]][e[1]];
        }

        vector<string> path;

        string start = "JFK";

        // 广度优先也行, 就是走完了要回来
        // 走还是正常走, 但是要知道什么时候走不通, 且走不通了需要撤回来, 走下一个

        while(!g.empty()) {

            path.push_back(start);

            auto &adjc = g[start];
            for (auto& end : adjc) {
                if (end.second != 0) {
                    string new_start = end.first;
                    --end.second;

                    if (end.second == 0) {

                        adjc.erase(end.first);
                        if (adjc.size() == 0) {
                            g.erase(start);
                            start = new_start;
                            break;
                        }
                    }

                    start = new_start;
                    break;
                }
            }
        }

        path.push_back(start);


        return path;



    }
};

////////////////////////////////////////////////////////////////////////////////

int main() {


    printCurrentFileName();


    Solution solution;

    // vector<vector<string>> tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    // vector<vector<string>> tickets = {{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}};
    vector<vector<string>> tickets = {{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};

    solution.findItinerary(tickets);


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}