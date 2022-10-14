//
// Created by tuhooo on 2022/10/14.
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


#define MOD 1000000007
#define N 2000



class Solution {
public:
    int distinctSubseqII(string s) {

        int dp[N];      // 用于动态规划的
        memset(dp, 0, sizeof(dp));  // 将值都设置为 0
        long long m[26];      // 记录以某个字母结尾的子序列个数
        memset(m, 0, sizeof(m));

        long long sum = 0;


        for (int i = 0; i < s.length(); ++i) {
            long long tmp = m[s[i]-'a'];
            m[s[i] - 'a'] = sum + 1;
            sum += (sum + 1 - tmp) % MOD;
        }

        return sum % MOD;
    }
};



////////////////////////////////////////////////////////////////////////////////

int main() {


    printCurrentFileName();


    Solution solution;

    solution.distinctSubseqII("aaa");


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}