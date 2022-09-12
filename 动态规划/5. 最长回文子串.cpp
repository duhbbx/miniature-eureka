
#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Solution {
public:

    string longestPalindrome(string s) {

        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int maxLen = 1;
        int start = 0;

        for (int L = 1; L <= n; L++) {
            for (int i = 0; i < n; i++) {

                int j = i + L - 1;

                if (j >= n) break;

                if (L == 1) {
                    dp[i][j] = true;
                    continue;
                } else if (L == 2 || L == 3) {
                    dp[i][j] = s[i] == s[j];
                } else {
                    dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
                }

                if (L > maxLen) {
                    if (dp[i][j]) {
                        maxLen = L;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};