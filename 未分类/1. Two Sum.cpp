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
#include <numeric>
#include <map>
#include <cstring>


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
    vector<int> twoSum(const vector<int>& nums, int target) {

        unordered_map<int, int> m1;
        unordered_map<int, int> m2;

        for (int i = 0; i < nums.size(); ++i) {
            if (m1.find(nums[i]) == m1.end()) {
                m1[nums[i]] = i;
            } else {
                m2[nums[i]] = i;
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (m1.find(target - nums[i]) != m1.end() && m1[target - nums[i]] != i) {
                return {min(i, m1[target - nums[i]]), max(i, m1[target - nums[i]])};
            } else if (m2.find(target - nums[i]) != m2.end()) {
                return {min(i, m2[target - nums[i]]), max(i, m2[target - nums[i]])};
            }
        }

        return {};
    }
};

////////////////////////////////////////////////////////////////////////////////

int main() {


    printCurrentFileName();


    Solution solution;

    solution.twoSum({3,3}, 6);


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}