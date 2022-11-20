
#include <bits/stdc++.h>

using namespace std;


//6241. 数组中不等三元组的数目

class Solution {
public:
    int unequalTriplets(vector<int>& nums) {

        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (nums[i] != nums[j] && nums[i] != nums[k] && nums[j] != nums[k]) {
                        ++res;
                    }
                }
            }
        }

        return res;

    }
};


int main() {


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}