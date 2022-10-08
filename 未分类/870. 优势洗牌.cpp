//
// Created by duhbb on 2022/10/8.
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
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {

        sort(nums1.begin(), nums1.end());

        vector<pair<int, int>> pair_vector;




        int len = nums2.size();

        for (int i = 0; i < len; ++i) {
            pair_vector.push_back(pair(nums2[i], i));
        }

        sort(pair_vector.begin(), pair_vector.end());




        vector<int> res(len, 0);


        int low = 0;
        int index = len - 1;
        for (int i = len-1; i >=low; ) {
            if (nums1[i] > pair_vector[index].first) {
                res[pair_vector[index].second] = nums1[i];
                --i;
            } else {
                res[pair_vector[index].second] = nums1[low];
                ++low;
            }
            --index;
        }


        return res;
    }
};

////////////////////////////////////////////////////////////////////////////////

int main() {


    printCurrentFileName();


    Solution solution;

    vector<int> nums1 = {12,24,8,32};
    vector<int> nums2 = {13,25,32,11};

    solution.advantageCount(nums1, nums2);


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}