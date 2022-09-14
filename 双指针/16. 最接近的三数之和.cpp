//
// Created by duhbb on 2022/9/14.
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

        int distance(int sum, int target) {
            return target > sum ? target - sum : sum - target;
        }

    int threeSumClosest(vector<int> &nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int first = 0;
        int res = 1000000000;
        int min_distance = 1000000000;


        while (first <= n - 3) {

            int second = first + 1;
            int third = n - 1;

            while(second < third) {
                int sum = nums[first] + nums[second] + nums[third];
                if (sum == target) {
                    return target;
                }

                int current_distance = distance(sum, target);
                if (current_distance < min_distance) {
                    res = sum;
                    min_distance = current_distance;
                }

                if (sum < target) {
                    int secondValue = nums[second];
                    while(second < third && secondValue == nums[second]) {
                        ++second;
                    }
                } else {
                    int thirdValue = nums[third];
                    while(second < third && thirdValue == nums[third]) {
                        --third;
                    }
                }
            }

            int firstValue = nums[first];
            while(first <= n-3 && firstValue == nums[first]) {
                ++first;
            }
        }

        return res;
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


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}