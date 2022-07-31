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

        // ģ�廹�ǵ���ջ��ģ�壬���Ǽ���ѭ������Ĵ���
        for (int i = 2 * n - 1; i >= 0; i--) {  // ��װ���鳤�ȷ�����
            while (!s.empty() && s.top() <= nums[i % n])    // �����ʱ��ȡģ
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