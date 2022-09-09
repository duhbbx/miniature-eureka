#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();
        vector<int> res(n);
        stack<int> s;

        // 模板还是单调栈的模板，但是加入循环数组的处理
        for (int i = 2 * n - 1; i >= 0; i--) {  // 假装数组长度翻倍了
            while (!s.empty() && s.top() <= nums[i % n])    // 计算的时候取模
                s.pop();
            res[i % n] = s.empty() ? -1 : s.top();
            s.push(nums[i % n]);
        }

        return res;
    }
};

int main() {

    Solution s;
    vector<int> nums = { 1, 2, 3, 4 };
    vector<int> res = s.nextGreaterElements(nums);

    for (auto i : res)
        cout << i << ", ";

    cout << endl;
    return 0;
}