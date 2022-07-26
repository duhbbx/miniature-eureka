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


class Solution {
public:
    int maximumSwap(int num) {
        string charArray = to_string(num);
        int n = charArray.size();
        int maxIdx = n - 1;
        int idx1 = -1, idx2 = -1;


        // 从最低位开始遍历
        for (int i = n - 1; i >= 0; i--) {
            if (charArray[i] > charArray[maxIdx]) {
                maxIdx = i;
            } else if (charArray[i] < charArray[maxIdx]) {
                idx1 = i;
                idx2 = maxIdx;
            }
        }

        if (idx1 >= 0) {
            swap(charArray[idx1], charArray[idx2]);
            return stoi(charArray);
        } else {
            return num;
        }
    }
};

//作者：LeetCode-Solution
//        链接：https://leetcode.cn/problems/maximum-swap/solution/zui-da-jiao-huan-by-leetcode-solution-lnd5/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

////////////////////////////////////////////////////////////////////////////////




void printCurrentFileName() {
    string file = __FILE__;
    int pos = file.find_last_of("/");
    string fileName = pos == -1 ? file : file.substr(pos+1);
    cout << "\n【当前题目为：" << fileName << "】" << endl;
}





int main() {


    printCurrentFileName();

    cout << INT_MAX << endl;


    Solution solution;

    cout << solution.maximumSwap(10) << endl;

    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}