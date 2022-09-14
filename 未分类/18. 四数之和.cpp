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
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());


        vector<vector<int>> res;
        int first = 0;
        while (first <= n - 4) {


            int second = first + 1;


            while (second <= n - 3) {

                int third = second + 1;
                int fourth = n - 1;

                while (third < fourth) {
                    long sum = 0L + nums[first] + nums[second] + nums[third] + nums[fourth];

                    if (sum == target) {
                        res.push_back({nums[first], nums[second], nums[third], nums[fourth]});

                        int thirdValue = nums[third];
                        while (third < fourth && thirdValue == nums[third]) {
                            ++third;
                        }

                        int fourthValue = nums[fourth];
                        while (third < fourth && fourthValue == nums[fourth]) {
                            --fourth;
                        }
                    } else if (sum < target) {
                        ++third;
                    } else {
                        --fourth;
                    }
                }

                int secondValue = nums[second];
                while (second <= n - 3 && secondValue == nums[second]) {
                    ++second;
                }
            }


            int firstValue = nums[first];
            while (first <= n - 4 && firstValue == nums[first]) {
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

    vector<int> nums = {2, 2, 2, 2, 2};
    solution.fourSum(nums, 8);


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}