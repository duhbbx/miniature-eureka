//
// Created by duhbb on 2022/9/24.
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
    vector<int> decrypt(vector<int> &code, int k) {

        int window = k > 0 ? k : -k;
        int flag = 0;
        if (k > 0) {
            flag = 1;
        } else if (k < 0) {
            flag = -1;
        }
        int len = code.size();

        vector<int> res(code.size(), 0);
        if (flag == 0) return vector<int>(code.size(), 0);

        for (int i = 0; i < len; ++i) {
            for (int j = 1; j <= window; ++j) {
                int pos = i + j * flag;
                if (pos >= len) {
                    pos = pos % len;
                } else if (pos < 0) {
                    pos = pos % len + len;
                }
                res[i] += code[pos];
            }
        }

        return res;
    }
};


////////////////////////////////////////////////////////////////////////////////






int main() {


    printCurrentFileName();


    Solution solution;

    vector<int> v = {10,5,7,7,3,2,10,3,6,9,1,6};

    solution.decrypt(v, -4);




    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}