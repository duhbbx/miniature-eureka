//
// Created by tuhooo on 2022/9/21.
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



////////////////////////////////////////////////////////////////////////////////
/// 这里放OJ的类


class Solution {
public:
    int kSimilarity(string s1, string s2) {
        queue<pair<string, int>> qu;    // 广度优先搜索的队列
        qu.emplace(s1, 0);              // 先将根节点入列
        unordered_set<string> visited;  // 判断字符串之前是否已经处理过了

        int step = 0;
        while (!qu.empty()) {
            int n = qu.size();
            for (int i = 0; i < n; ++i) {
                auto [curr_s1, pos] = qu.front();
                if (curr_s1 == s2) return step;
                qu.pop();


                for (int j = pos; j < curr_s1.length(); ++j) {
                    if (curr_s1[j] == s2[j]) continue;

                    for (int k = j + 1; k < curr_s1.length(); ++k) {
                        if (curr_s1[k] != s2[k] && s2[j] == curr_s1[k]) {
                            swap(curr_s1[j], curr_s1[k]);

                            if (visited.find(curr_s1) == visited.end()) {
                                visited.insert(curr_s1);
                                qu.emplace(curr_s1, j + 1);
                            }

                            swap(curr_s1[j], curr_s1[k]);
                        }
                    }

                    break;
                }
            }
            ++step;
        }
        return step;
    }
};


////////////////////////////////////////////////////////////////////////////////




void printCurrentFileName() {
    string file = __FILE__;
    int pos = file.find_last_of("/");
    string fileName = pos == -1 ? file : file.substr(pos + 1);
    cout << "\n【当前题目为：" << fileName << "】" << endl;
}


int main() {


    printCurrentFileName();


    Solution solution;

    solution.kSimilarity("ab", "ba");


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}