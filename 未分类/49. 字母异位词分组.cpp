//
// Created by duhbb on 2022/9/13.
//
#include <iostream>              // 输入输出
#include <vector>                // 可变长度数组
#include <unordered_map>         // hashmap
#include <stack>                 // 栈
#include <string>                // 字符串
#include <queue>                 // 队列
#include <climits>               // 极限值
#include <algorithm>             // 算法相关的
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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {


        unordered_map<char, int> charFactorMap = {
                {'a', 2},
                {'b', 3},
                {'c', 5},
                {'d', 7},
                {'e', 11},
                {'f', 13},
                {'g', 17},
                {'h', 19},
                {'i', 23},
                {'j', 29},
                {'k', 31},
                {'l', 41},
                {'m', 43},
                {'n', 47},
                {'o', 43},
                {'p', 59},
                {'q', 61},
                {'r', 67},
                {'s', 71},
                {'t', 73},
                {'u', 79},
                {'v', 83},
                {'w', 89},
                {'x', 97},
                {'y', 101},
                {'z', 103},

        };

        unordered_map<long, vector<string>> res;

        int mod = 1000000007;
        for (auto& s : strs) {
            int hash = 1;
            for (auto& c : s) {
                hash = ((hash % mod) * (charFactorMap[c] % mod)) % mod;
            }
            res[hash].push_back(s);
        }

        vector<vector<string>> ans;

        for(auto& v : res) {
            ans.push_back(v.second);
        }

        return ans;
    }
};




////////////////////////////////////////////////////////////////////////////////




void printCurrentFileName() {
    string file = __FILE__;
    int pos = file.find_last_of("/");
    string fileName = pos == -1 ? file : file.substr(pos+1);
    cout << "\n【当前题目为：" << fileName << "】" << endl;
}





int main() {


    printCurrentFileName();


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}