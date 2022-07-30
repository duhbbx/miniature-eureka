#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int> monotonous_stack;      // 单调递减的栈
        unordered_map<int, int> hashmap;  // 存放临时结果
        vector<int> vec(nums1.size(), 0); // 存放最后返回的结果

        // 维护一个单调递减的栈
        for (int value : nums2) {

            // 从栈尾将小于 value 的值都弹出去，并且这些谈出去的值的下一个最大的值为 value
            while (!monotonous_stack.empty() && value > monotonous_stack.top()) {
                hashmap[monotonous_stack.top()] = value;
                monotonous_stack.pop();
            }

            // 如果将小于 value 的值都弹出去了或者栈为空了，则可以将 value 入栈
            monotonous_stack.push(value);
        }

        // 栈里面的都是后面没有更大值的元素
        while (!monotonous_stack.empty()) {
            hashmap[monotonous_stack.top()] = -1;
            monotonous_stack.pop();
        }

        // unordered_map 转为 vector 返回结果
        for (int i = 0; i < nums1.size(); i++) {
            vec[i] = hashmap.at(nums1[i]);
        }

        return vec;
    }
};

int main() {

    cout << "hello, world\n" << endl;

    Solution s;

    vector<int> nums1 = { 4, 1, 2 };
    vector<int> nums2 = { 1, 3, 4, 2 };
    auto res = s.nextGreaterElement(nums1, nums2);
    for (auto i : res) {
        cout << i << ", ";
    }

    return 0;
}