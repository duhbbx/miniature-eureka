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


class NumArray {
public:

    vector<int> prefixeSum = vector<int>(10001, 0);

    NumArray(vector<int>& nums) {
        int n = nums.size();


        for (int i = 0; i < n; ++i) {
            prefixeSum[i+1] = prefixeSum[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {


        return prefixeSum[right+1] - prefixeSum[left];

    }
};


int main() {





    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}