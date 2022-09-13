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
#include <set>

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
    vector<string> generateParenthesis(int n) {

        if (n == 0) return {};
        if (n == 1) return {"()"};

        vector<string> res;

        set<string> myset;



        string semifinished = "()";
        backtrack(myset, 1, n, semifinished);


        res.assign(myset.begin(), myset.end());
        return res;
    }

    void backtrack(set<string>& myset, int index, int n, string& semifinished) {

        if (index == n) {
            myset.insert(semifinished);
            return;
        }

        semifinished.push_back('(');
        semifinished.push_back(')');

        backtrack(myset, index + 1, n, semifinished);

        semifinished.pop_back();
        semifinished.pop_back();

        semifinished = "(" + semifinished + ")";
        backtrack(myset, index + 1, n, semifinished);
        semifinished = semifinished.substr(1, semifinished.length() - 2);

        semifinished = "()" + semifinished;
        backtrack(myset, index + 1, n, semifinished);
        semifinished = semifinished.substr(2);
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