//
// Created by tuhooo on 2022/9/17.
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

    vector<int> recurse(vector<int>& nums, int begin, int end, int target) {

        if (begin > end) return {-1, -1};
        if (begin == end) {
            if (nums[begin] != target) {
                return {-1, -1};
            } else {
                return {begin, begin};
            }
        }

        int l = begin;
        int r = end;


        while(l <= r) {
            int mid = (l + r) >> 1;
            if (nums[mid] < target) {
                l = mid + 1;
            } else if (nums[mid] == target) {
                vector<int> resLeft = recurse(nums, begin, mid - 1, target);
                vector<int> resRight = recurse(nums, mid + 1, end, target);

                vector<int> res(2, mid);
                if (resLeft[0] != -1) {
                    res[0] = resLeft[0];
                }
                if (resRight[1] != -1) {
                    res[1] = resRight[1];
                }
                return res;
            } else {
                r = mid - 1;
            }
        }

        return {-1, -1};
    }



    vector<int> searchRange(vector<int>& nums, int target) {
        return recurse(nums, 0, nums.size()-1, target);
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


    vector<int> nums = {5, 7, 7, 8, 8, 10};

    Solution solution;

    solution.searchRange(nums, 7);


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}