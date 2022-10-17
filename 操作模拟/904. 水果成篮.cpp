//
// Created by duhbb on 2022/10/17.
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
    int totalFruit(const vector<int>& fruits) {

        int res = 0;
        int a = 0, b = 0;
        int continuous_a = 0, continuous_b = 0;
        int p = -1, q = -1;
        int len = fruits.size();

        for (int i = 0; i < len; ++i) {
            if (p == -1) {
                p = fruits[i];
                ++continuous_a;
                ++a;
                continuous_b = 0;
            } else if (p == fruits[i]) {
                ++a;
                ++continuous_a;
                continuous_b = 0;
            } else if (q == -1) {
                q = fruits[i];
                ++continuous_b;
                ++b;
                continuous_a = 0;
            } else if (q == fruits[i]) {
                ++b;
                ++continuous_b;
                continuous_a = 0;
            } else {
                res = max(a+b, res);

                if (fruits[i-1] == p) {
                    a = continuous_a;
                    q = fruits[i];
                    continuous_a = 0;
                    continuous_b = 1;
                    b = 1;
                } else if (fruits[i-1] == q) {
                    b = continuous_b;
                    p = fruits[i];
                    continuous_b = 0;
                    continuous_a = 1;
                    a = 1;
                }
            }
        }

        return max(res, a+b);
    }
};

////////////////////////////////////////////////////////////////////////////////

int main() {


    printCurrentFileName();


    Solution solution;


    // solution.totalFruit({1, 2, 1});
    // solution.totalFruit({1,0,1,4,1,4,1,2,3});
    solution.totalFruit({3,3,3,1,2,1,1,2,3,3,4});



    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}