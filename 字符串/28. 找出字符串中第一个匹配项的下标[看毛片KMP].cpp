

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
public:


    vector<int> getNext(const string& substring) {

        if (substring.size() == 0) {
            return {};
        }

        int n = substring.size();
        vector<int> next(n, -1);

        next[0] = -1;

        int j = -1;

        for (int i = 1; i < n; ++i) {

            while(j > -1 && substring[j + 1] != substring[i]) {
                j = next[j];
            }

            if (substring[j+1] == substring[i]) {
                ++j;
            }

            next[i] = j;
        }

        return next;
    }


    int strStr(string haystack, string needle) {

        if (needle.size() <= 0) {
            return 0;
        }

        vector<int> next = getNext(needle);


        int m = haystack.size();
        int n = needle.size();

        int j = -1;
        for (int i = 0; i < m; ++i) {
            while(j > -1 && needle[j+1] != haystack[i]) {
                j = next[j];
            }

            if (needle[j+1] == haystack[i]) {
                ++j;
            }

            if (j == n - 1) {
                return i - n + 1;
            }
        }



        return -1;
    }
};





int main() {


    string sub = "ababxca";


    Solution solution;

    auto next = solution.getNext(sub);

    for (int i = 0; i < next.size(); ++i) {
        cout << next[i] << ", ";
    }

    cout << endl;

    cout << "------------" << endl;

    cout << solution.strStr(sub, "xca") << "";




    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}