//
// Created by duhbb on 2022/9/9.
//

#ifndef LEETCODE_LISTNODE_H
#define LEETCODE_LISTNODE_H

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}


    static ListNode* create(vector<int> nums) {


        if (nums.empty()) {
            std::cout << "数据为空哦" << std::endl;
            return nullptr;
        }

        auto* p = new ListNode(nums[0]);

        ListNode* head = p;
        for (int i = 1; i < nums.size(); i++) {
            p->next = new ListNode(nums[i]);
            p = p->next;
        }

        return head;
    }

    static void destroy(ListNode* head) {

        std::cout << "开始销毁链表" << std::endl;

        ListNode* p = head;
        ListNode* tmp = head;
        while(p) {
            tmp = p;
            p = p->next;
            delete tmp;
        }

        std::cout << "链表销毁完毕.........." << std::endl;
    }

    void print() {
        auto* p = this;
        while(p) {
            if (p->next) {
                std::cout << p->val << ", ";

            } else {
                std::cout << p->val << std::endl;
            }
            p = p->next;
        }
    }
};





#endif //LEETCODE_LISTNODE_H
