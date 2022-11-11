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


class Solution {

private:
    static constexpr char table[] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
    static constexpr int n = 10;
public:
    bool halvesAreAlike(string s) {


        int part1 = 0;
        int part2 = 0;
        int i = 0, j = s.size() - 1;

        while(i < j) {
            for (int k = 0; k < n; ++k) {
                if (table[k] == s[i]) {
                    ++part1;
                }

                if (table[k] == s[j]) {
                    ++part2;
                }
            }

            ++i;
            --j;
        }

        return part1 == part2;
    }
};


int main() {


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}