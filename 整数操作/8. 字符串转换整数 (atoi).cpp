//
// Created by duhbb on 2022/9/12.
//

#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {

        if (s.length() == 0) return 0;



        // 正负号的符号
        int flag = 0;


        int i = 0;

        while (s[i] == ' ' && i < s.length()) {
            i++;
        }

        if (i == s.length()) return 0;
        if (s[i] == '+') {
            flag = 1;
            ++i;
        } else if ('0' <= s[i] && s[i] <= '9') {
            flag = 1;   // 是正数
        } else if (s[i] == '-') {
            flag = 2;   // 是负数
            ++i;
        } else {
            // 如果是其他字符则为 0
            return 0;
        }

        int j = i;

        while (j < s.length()) {
            if (j == i && s[j] == '0') {
                j == ++i;
            } else if ('0' <= s[j] && s[j] <= '9') {
                j++;
            } else {
                break;
            }
        }

        if (i == j) return 0;

        // std::cout << "有效字符: " << s.substr(i, j - i) << std::endl;

        // 问题来了，如何判断溢出
        long long sum = 0;
        for (int k = i; k < j; k++) {
            sum = 10 * sum + (flag < 2 ? 1 : -1) * (s[k] - '0');

            if (sum >= INT_MAX) {
                return INT_MAX;
            } else if (sum <= INT_MIN) {
                return INT_MIN;
            }

        }

        if (sum >= INT_MAX) {
            return INT_MAX;
        } else if (sum <= INT_MIN) {
            return (int) INT_MIN;
        } else {
            return sum;
        }

    }
};

int main() {
    string s = "-91283472332";

    Solution solution;

    std::cout << solution.myAtoi(s) << std::endl;
}