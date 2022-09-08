#include <iostream>              // 输入输出
#include <vector>                // 可变长度数组
#include <unordered_map>         // hashmap
#include <stack>                 // 栈
#include <string>                // 字符串
#include <queue>                 // 队列
#include <climits>               // 极限值
#include <algorithm>             // 算法相关的

using namespace std;



/// <summary>
/// 输出容器中的内容
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="t"></param>
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


struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* my_head = head;

        if (my_head == nullptr) {
            return my_head;
        }

        ListNode* p = nullptr;

        while (my_head) {
            if (p == nullptr) {
                p = my_head;
                my_head = my_head->next;
                p->next = nullptr;
            } else {
                ListNode* tmp = p;
                p = my_head;
                my_head = my_head->next;
                p->next = tmp;
            }
        }

        return p;
    }
};






////////////////////////////////////////////////////////////////////////////////












int main() {

    cout << "" << endl;

    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}