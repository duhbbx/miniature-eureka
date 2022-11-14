
#include <bits/stdc++.h>

using namespace std;



//6234. 最小公倍数为 K 的子数组数目

class Solution {
public:

    int subarrayLCM(vector<int>& nums, int k) {

        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int curLCM = nums[i];   // 获取当前数作为起始值
            if (k % curLCM != 0) {  // 如果k不能被整除说明当前的i不是因子
                continue;
            }

            for (int j = i; j < n; ++j) {
                curLCM = lcm(curLCM, nums[j]);
                if (curLCM == k) {
                    ++res;
                } else if (k % curLCM != 0) {
                    break;
                }
            }
        }

        return res;
    }
};


int main() {


    Solution solution;

    vector<int> nums = {3,6,2,7,1};

    int target = 2;

    solution.subarrayLCM(nums, 6);


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}