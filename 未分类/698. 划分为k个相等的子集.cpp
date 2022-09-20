//
// Created by duhbb on 2022/9/20.
//
#include <iostream>              // 输入输出
#include <vector>                // 可变长度数组
#include <unordered_map>         // hashmap
#include <stack>                 // 栈
#include <string>                // 字符串
#include <queue>                 // 队列
#include <climits>               // 极限值
#include <algorithm>             // 算法相关的
#include <set>                   // 集合
#include <numeric>
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
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int all = accumulate(nums.begin(), nums.end(), 0); // 对集合中的所有元素求和
        if (all % k > 0) return false;      // 如果和不是 k 的倍数的话肯定不行了
        int per = all / k;                  // 计算每个集合中的元素个数
        sort(nums.begin(), nums.end());     // 对整个数组进行排序
        if (nums.back() > per) return false;// 如果元素中的最大值大于 per 说明也不行
        int n = nums.size();
        vector<bool> dp(1 << n, true);      // 1 左移 n 位, 1 << n 个元素的 vector
        function<bool(int,int)> dfs = [&](int s, int p)->bool {
            if (s == 0) return true;        // s 中的数都取完了, 说明可以
            if (!dp[s]) return dp[s];       // dp[s] 为 false 就说明已经不行了
            dp[s] = false;
            for (int i = 0; i < n; i++) {
                if (nums[i] + p > per) {    // 我可能先回判断 s 中第 i 位会不会已经用了, 它这是放在前面
                    break;
                }
                if ((s >> i) & 1) {
                    if (dfs(s ^ (1 << i), (p + nums[i]) % per)) {
                        return true;
                    }
                }
            }
            return false;
        };
        return dfs((1 << n) - 1, 0);        // (1 << n) -1 就是 n - 1 个 1
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