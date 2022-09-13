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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode* p = nullptr;

        if (list1->val < list2->val) {
            p = list1;
            list1 = list1->next;
        } else {
            p = list2;
            list2 = list2->next;
        }

        ListNode* tail = p;
        tail->next = nullptr;

        while(true) {

            if (list1 == nullptr) {
                tail->next = list2;
                break;
            }

            if (list2 == nullptr) {
                tail->next = list1;
                break;
            }

            if (list1->val < list2->val) {
                tail->next = list1;
                tail = tail->next;
                list1 = list1->next;
                tail->next = nullptr;
            } else {
                tail->next = list2;
                tail = tail->next;
                list2 = list2->next;
                tail->next = nullptr;
            }
        }

        return p;
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

    ListNode*p = solution.mergeTwoLists(ListNode::create({1, 2 ,4}), ListNode::create({1, 3, 4}));


    p->print();


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}