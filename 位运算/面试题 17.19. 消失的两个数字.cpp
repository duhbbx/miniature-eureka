//
// Created by duhbb on 2022/9/26.
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


class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        // 在 nums 后面补上 3 个数
        for (int i = 0; i < 3; i++) nums.push_back(-1);

        for (int i = 0; i < nums.size(); i++)
            while (i != nums[i] && nums[i] != -1)
                swap(nums[i], nums[nums[i]]);

        vector<int> ans;
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] == -1) ans.push_back(i);
        return ans;
    }
};


////////////////////////////////////////////////////////////////////////////////

int main() {


    printCurrentFileName();


    Solution solution;
    vector<int> nums = {2, 3, 4};

    solution.missingTwo(nums);


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}