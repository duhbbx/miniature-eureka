//
// Created by duhbb on 2022/9/13.
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


/*

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {


        int n = nums.size();

        if (n == 0 || n == 1) return n;

        int index = 0, val = nums[0];

        for (int i = 1; i < n; i++) {

            if (nums[i] == val) {
                continue;
            } else {
                nums[index + 1] = nums[i];

                val = nums[i]; // val 要用新的值
                ++index;       // index是自增而不是到 i
            }

        }


        return index+1;
    }
};

 */


class Solution {
public:
    int removeDuplicates(vector<int> &nums) {

        int n = nums.size();
        if (n == 0) return 0;

        int p = 0;
        int q = 1;

        while(q < n) {
            if (nums[p] != nums[q]) {
                if (q - p > 1) {
                    nums[p + 1] = nums[q];
                }
                p++;
            }

            q++;
        }

        return p + 1;
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