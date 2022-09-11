//
// Created by duhbb on 2022/9/11.
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


    if (!t.empty()) {
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


//857. 雇佣 K 名工人的最低成本
//        有 n 名工人。 给定两个数组 quality 和 wage ，其中，quality[i] 表示第 i 名工人的工作质量，其最低期望工资为 wage[i] 。
//
//现在我们想雇佣 k 名工人组成一个工资组。在雇佣 一组 k 名工人时，我们必须按照下述规则向他们支付工资：
//
//对工资组中的每名工人，应当按其工作质量与同组其他工人的工作质量的比例来支付工资。
//工资组中的每名工人至少应当得到他们的最低期望工资。
//给定整数 k ，返回 组成满足上述条件的付费群体所需的最小金额 。在实际答案的 10-5 以内的答案将被接受。。


class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {

        // 我感觉应该是背包问题

        // 计算的话要以工资比工作量最大的为准，也就是找出最水的那个，性价比，最低的，然后再是另外 k-1 个人的 quality 之和最少

        // 动态维护的话可以使用优先队列


        return 0;
    }
};



////////////////////////////////////////////////////////////////////////////////




void printCurrentFileName() {
    string file = __FILE__;
    int pos = file.find_last_of("/");
    string fileName = pos == -1 ? file : file.substr(pos+1);
    cout << "【当前题目为：" << fileName << "】" << endl;
}





int main() {


    printCurrentFileName();




    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}