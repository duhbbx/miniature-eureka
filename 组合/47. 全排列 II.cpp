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
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<vector<int>> res;

        vector<int> item;
        vector<int> flagArray(nums.size(), 0);
        set<string> setForNonrepeat;
        backtrack(res, item, flagArray, nums, setForNonrepeat);
        return res;
    }

    string vector2String(vector<int>& item) {
        string s;

        for(int i : item) {
            s += (char) ('0' + i);
        }
        return s;
    }

    void backtrack(vector<vector<int>>& res, vector<int>& item, vector<int>& flagArray, vector<int> nums, set<string>& setForNonrepeat) {

        if (item.size() == nums.size()) {
            string s = vector2String(item);
            if (setForNonrepeat.find(s) == setForNonrepeat.end()) {
                res.push_back(item);
                setForNonrepeat.insert(s);
            }
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (flagArray[i] == 0) {
                flagArray[i] = 1;
                item.push_back(nums[i]);
                backtrack(res, item, flagArray, nums, setForNonrepeat);
                flagArray[i] = 0;
                item.pop_back();
            }
        }
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