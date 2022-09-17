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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());



        int sum = 0;

        vector<int> choice;
        vector<vector<int>> res;

        backtrack(candidates, target, 0, choice, res, 0);

        return res;
    }

    void backtrack(vector<int>& candidates, int target, int sum, vector<int>& choice, vector<vector<int>>& res, int index) {

        if (sum == target) {
            res.push_back(choice);
            return;
        }


        for (int i = index; i < candidates.size(); i++) {

            int cur = candidates[i];
            if (cur + sum <= target) {
                choice.push_back(cur);
                backtrack(candidates, target, cur + sum, choice, res, i);
                choice.pop_back();
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