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
    ListNode *swapPairs(ListNode *head) {

        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *newHead = head->next;
        ListNode *tail = nullptr;

        while (true) {
            ListNode *p = head;
            if (p == nullptr) break;
            ListNode *q = p->next;
            if (q == nullptr) break;

            p->next = q->next;
            q->next = p;

            // 处理链表的时候 tail 需要注意
            if (tail == nullptr) {
                tail = p;
            } else {
                tail->next = q;
                tail = p;
            }

            head = p->next;
        }


        return newHead;
    }
};


/*


递归版本就是要比迭代慢啊

 class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* p = head;
        ListNode* q = head->next;
        ListNode* tmp = q->next;

        q->next = p;
        p->next =swapPairs(tmp);

        return q;
    }
};




 */


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


    ListNode* list = ListNode::create({1, 2, 3, 4, 5});

    list = solution.swapPairs(list);


    list->print();

    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}