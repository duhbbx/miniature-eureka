

#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;



class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {


        stack<int> monotonous_stack;        // ����ջ
        unordered_map<int, int> hashmap;    // �����ʱ����� hashmap
        vector<int> vec(nums.size(), 0);



        // TODO һ�������ң���һ�����ҵ���



        return {};
    }
};



int main() {


    Solution s;


    vector<int> nums = { 1, 2, 3, 4 };
    s.nextGreaterElements(nums);


    cout << "end......" << endl;

    return 0;
}