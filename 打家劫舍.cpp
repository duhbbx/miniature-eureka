
#include <bits/stdc++.h>
#define ENABLE_DEBUG

using namespace std;

#define __output(...) printf(__VA_ARGS__);

#define __format(__fmt__) "%s(%d)-<%s>: " __fmt__ "\n"

#ifdef ENABLE_DEBUG
#define TRACE_ME(__fmt__, ...) __output(__format(__fmt__), __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__);
#endif

#ifndef ENABLE_DEBUG
#define TRACE_ME(__fmt__, ...)
#endif

int dp[2];

class Solution {
  public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        dp[0] = 0;
        dp[1] = nums[0];

        for (int i = 1; i < n; ++i) {
            int a = max(dp[1], dp[0] + nums[i]);
            dp[0] = dp[1];
            dp[1] = a;
        }

        return dp[1];
    }
};

int main() {
    cout << "test...." << endl;

    Solution s;
    vector<int> a = {1};
    int res = s.rob(a);

    cout << "\nres = " << res << endl;
}
