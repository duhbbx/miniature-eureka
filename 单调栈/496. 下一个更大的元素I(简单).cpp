#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int> monotonous_stack;      // �����ݼ���ջ
        unordered_map<int, int> hashmap;  // �����ʱ���
        vector<int> vec(nums1.size(), 0); // �����󷵻صĽ��

        // ά��һ�������ݼ���ջ
        for (int value : nums2) {

            // ��ջβ��С�� value ��ֵ������ȥ��������Щ̸��ȥ��ֵ����һ������ֵΪ value
            while (!monotonous_stack.empty() && value > monotonous_stack.top()) {
                hashmap[monotonous_stack.top()] = value;
                monotonous_stack.pop();
            }

            // �����С�� value ��ֵ������ȥ�˻���ջΪ���ˣ�����Խ� value ��ջ
            monotonous_stack.push(value);
        }

        // ջ����Ķ��Ǻ���û�и���ֵ��Ԫ��
        while (!monotonous_stack.empty()) {
            hashmap[monotonous_stack.top()] = -1;
            monotonous_stack.pop();
        }

        // unordered_map תΪ vector ���ؽ��
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