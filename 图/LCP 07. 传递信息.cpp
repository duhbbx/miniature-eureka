

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

#include <functional>

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
    int numWays(int n, vector<vector<int>> &relation, int k) {

        vector<vector<int>> g(n, vector<int>(n, 0));

        for (auto &o: relation) {
            g[o[1]][o[0]] = 1;
        }

        bool allZero = true;
        for (int i = 0; i < n; ++i) {
            if (g[n - 1][i] != 0) {
                allZero = false;
                break;
            }
        }

        if (allZero) return 0;

        const auto &f = [&](auto &&self, int step, int point) -> int {

            if (step == 1) {
                return g[point][0];
            }

            int res = 0;
            for (int i = 0; i < n; ++i) {
                if (g[point][i] == 0) {
                    continue;
                }
                res += self(self, step - 1, i);
            }

            return res;
        };

        return f(f, k, n - 1);
    }
};

////////////////////////////////////////////////////////////////////////////////

int main() {


    printCurrentFileName();


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}