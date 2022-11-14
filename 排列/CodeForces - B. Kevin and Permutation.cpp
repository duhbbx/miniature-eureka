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
#include <numeric>
#include <map>
#include <cstring>


using namespace std;


void permutation(int n) {
    if (n % 2 == 1) {
        for (int i = 1; i <= n; ++i) {
            cout << i << " ";
        }
    } else {
        for (int i = 1; i <= n; ++i) {
            if (i % 2 == 0) {
                cout << i << " ";
            }
        }

        for (int i = 1; i <= n; ++i) {
            if (i % 2 == 1) {
                cout << i << " ";
            }
        }
    }

    cout << endl;
}



int main() {

    int test_case_n = 0;
    cin >> test_case_n;

    for (int i = 0; i < test_case_n; ++i) {
        int n = 0;
        cin >> n;
        permutation(n);
    }
}