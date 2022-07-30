

#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;



class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {


        stack<int> monotonous_stack;        // 单调栈
        unordered_map<int, int> hashmap;    // 存放临时结果的 hashmap
        vector<int> vec(nums.size(), 0);



        // TODO 一个从左到右，另一个从右到左



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