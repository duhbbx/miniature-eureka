
#include <iostream>                // 输入输出
#include <vector>                // 可变长度数组
#include <unordered_map>        // hashmap
#include <stack>                // 栈
#include <string>                // 字符串
#include <cstring>

using namespace std;


int a[50010];



class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {

        memset(a, 0, sizeof(a));
        int top = -1;

        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while(top == -1 || nums[a[top]] > nums[i]) {
                a[++top] = i;
            }
        }

        int res = 0;
        for (int i = n-1; i >= 0; --i) {
            while(top != -1 && nums[i] >= nums[a[top]]) {
                res = max(i - a[top], res);
                --top;
            }
        }

        return res;
    }
};


template<typename T>
void print(T t) {
    for (typename T::const_iterator it = t.begin(); it != t.end(); ++it) {
        cout << *it << endl;
    }
}



int main() {


    print<vector<int>>({ 1, 2, 3, 4, 5});

    // vector<int> nums = {6,0,8,2,1,5};
    vector<int> nums = {9,8,1,0,1,9,4,0,4,1};

    Solution solution;

    solution.maxWidthRamp(nums);





    return 0;
}