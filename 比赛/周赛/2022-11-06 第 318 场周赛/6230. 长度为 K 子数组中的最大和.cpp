//
// Created by duhbb on 2022/9/17.
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
#include "../../../0000 API 模板 类/TreeNode.h"
#include "../../../0000 API 模板 类/ListNode.h"


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
    long long maximumSubarraySum(vector<int> &nums, int k) {


        long long res = 0;

        int n = nums.size();
        vector<long long> prefixSum(n+1, 0);

        for (int i = 1; i < n+1; ++i) {
            prefixSum[i] = nums[i-1] + prefixSum[i-1];
        }

        unordered_map<int, int> map1;


        int least = 0;
        for (int i = 0; i < n; ++i) {
            if (map1.find(nums[i]) != map1.end()) {
                int r = map1.find(nums[i])->second;
                for (int j = least; j <= r; ++j) {
                    map1.erase(nums[j]);
                }
                map1.emplace(nums[i], i);
                least = r + 1;
            } else {
                map1.emplace(nums[i], i);
            }

            if (map1.size() == k) {
                res = max(res, prefixSum[i+1] - prefixSum[least]);

                map1.erase(nums[least]);
                ++least;
            }
        }

        return res;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */

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

    vector<int> nums = {1,5,4,2,9,9,9};
    solution.maximumSubarraySum(nums, 3);


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}