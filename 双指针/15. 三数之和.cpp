//
// Created by duhbb on 2022/9/12.
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
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        int n = nums.size();

        int first = 0, second = 1, third = n - 1;


        while(first <= n - 3) {

            while(second < third) {

                int flag = nums[first] + nums[second] + nums[third];

                if (flag == 0) {
                    res.push_back({nums[first], nums[second], nums[third]});
                    int secondValue = nums[second];
                    while(second < third && nums[second] == secondValue) {
                        ++second;
                    }

                    int thirdValue = nums[third];
                    while(second < third && nums[third] == thirdValue) {
                        --third;
                    }

                } else if (flag > 0) {
                    --third;
                    // 这一步不是必要的
                    // 想想看如果 third + second 最小的都是大于0的话这个second已经没有意义了
//                    if (third == second) {
//                        ++second;
//                        third = n - 1;
//                    }
                } else {
                    ++second;
                }
            }

            int firstValue = nums[first];
            while(first <= n - 3 && nums[first] == firstValue) {
                ++first;
            }
            second = first + 1;
            third = n - 1;
        }

        return res;
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


    Solution solution;

    vector<int> nums = {1,-1,-1,0};
    vector<vector<int>> res = solution.threeSum(nums);

    printCurrentFileName();


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}