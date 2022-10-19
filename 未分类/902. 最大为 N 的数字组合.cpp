//
// Created by tuhooo on 2022/10/18.
//

#include <iostream>              // 输入输出
#include <vector>                // 可变长度数组
#include <unordered_map>         // hashmap
#include <unordered_set>         // 无序集合
#include <stack>                 // 栈
#include <string>                // 字符串
#include <queue>                 // 队列
#include <climits>               // 极限值
#include <algorithm>             // 算法相关的
#include <set>                   // 集合
#include "../0000 API 模板 类/TreeNode.h"
#include "../0000 API 模板 类/ListNode.h"
#include <numeric>
#include <map>
#include <cstring>


using namespace std;


template<typename T>
void print(T t) {


    if (t.empty()) {
        cout << "容器为空............" << endl;
        return;
    }


    for (typename T::const_iterator it = t.begin(); it != t.end() - 1; ++it) {
        cout << *it << ", ";
    }

    cout << *(t.end() - 1) << endl;
}

void printCurrentFileName() {
    string file = __FILE__;
    int pos = file.find_last_of("/");
    string fileName = pos == -1 ? file : file.substr(pos + 1);
    cout << "\n【当前题目为：" << fileName << "】" << endl;
}




////////////////////////////////////////////////////////////////////////////////
/// 这里放OJ的类


class Solution {
public:
    int atMostNGivenDigitSet(const vector<string> &digits, int n) {

        int m = n;
        vector<int> bits_of_n;
        while (m) {
            int rem = m % 10;
            bits_of_n.push_back(rem);
            m = (m - rem) / 10;
        }

        int bits_num = bits_of_n.size();

        vector<char> biggest(bits_num, ' ');


        const auto &dfs = [&](auto &&self, int first, int start, int last_digits_index, int digits_index) -> void {
            if (first == -1) {  // 如果已经遍历到了最后一位则退出
                return;
            }

            if (first == start) {   // 如果是第一位的话, 可能存在轮空的情况
                int j = digits_index;
                for (; j >= 0; --j) {
                    biggest[first] = digits[j][0];
                    if (lessEqual(biggest, n)) {    // 选择小于 n 的当前位的最大的一个数字
                        biggest[first] = digits[j][0];
                        last_digits_index = j;   // 记住此位的当前位置
                        break;
                    }

                    biggest[first] = ' ';
                }

                if (j == -1) {
                    biggest[first] = ' ';
                }

                self(self, first - 1, start, last_digits_index, digits.size() - 1);
            } else {
                if (biggest[first + 1] == ' ') {    // 如果前一位轮空了
                    for (int k = first; k >= 0; --k) {
                        biggest[k] = digits[digits.size() - 1][0];
                    }
                    self(self, -1, -1, -1, -1);
                } else {
                    int j = digits_index;
                    for (; j >= 0; --j) {
                        biggest[first] = digits[j][0];
                        if (lessEqual(biggest, n)) {    // 选择小于 n 的当前位的最大的一个数字
                            biggest[first] = digits[j][0];
                            last_digits_index = j;   // 记住此位的当前位置
                            self(self, first - 1, start, last_digits_index, digits.size() - 1);
                            break;
                        }
                        biggest[first] = ' ';
                    }
                    if (j == -1) {
                        self(self, first + 1, start, last_digits_index - 1, last_digits_index - 1);
                    }
                }
            }
        };

        dfs(dfs, bits_num - 1, bits_num - 1, -1, digits.size() - 1);

        unordered_map<char, int> map;
        for (int i = 0; i < digits.size(); ++i) {
            map[digits[i][0]] = i;
        }

        int res = 0;

        // 这个for循环是我从题解里面抄的
        for (int i = biggest.size() - 1; i >= 0; --i) {
            if (biggest[i] == ' ') continue;
            res = res * digits.size() + (map[biggest[i]] + 1);
        }
        return res;
    };

    bool lessEqual(vector<char> &biggest, int n) {
        int base = 1;
        long long sum = 0;
        for (int i = 0; i < biggest.size(); ++i) {
            sum += base * (biggest[i] == ' ' ? 0 : biggest[i] - '0');
            base *= 10;
        }
        return sum <= n;
    }
};


////////////////////////////////////////////////////////////////////////////////

int main() {


    printCurrentFileName();


    Solution solution;

    // solution.atMostNGivenDigitSet({"1", "2", "3", "6", "7", "8"}, 211);
    // solution.atMostNGivenDigitSet({"1",  "3", "5", "7"}, 100);
    solution.atMostNGivenDigitSet({"5", "7", "8"}, 59);


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}