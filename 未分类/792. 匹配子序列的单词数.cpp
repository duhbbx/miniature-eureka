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


/*
 * 给定字符串 s 和字符串数组 words, 返回  words[i] 中是s的子序列的单词个数 。

字符串的 子序列 是从原始字符串中生成的新字符串，可以从中删去一些字符(可以是none)，而不改变其余字符的相对顺序。

例如， “ace” 是 “abcde” 的子序列。
 

示例 1:

输入: s = "abcde", words = ["a","bb","acd","ace"]
输出: 3
解释: 有三个是 s 的子序列的单词: "a", "acd", "ace"。
Example 2:

输入: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
输出: 2
 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/number-of-matching-subsequences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
class Solution {
public:

    bool find(vector<vector<int>>& p, string& w) {

        int position = -1;

        for (int i = 0; i < w.size(); ++i) {

            auto& seq = p[w[i]-'a'];
            if (seq.size() == 0 || seq.back() < position) {
                return false;
            }

            auto r = lower_bound(seq.begin(), seq.end(), position + 1);

            if (r == seq.end()) {
                return false;
            } else {
                position = *r;
            }
        }

        return true;
    }


    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> p(26, vector<int>());
        int s_len = s.size();

        for (int i = 0; i < s_len; ++i) {
            p[s[i] - 'a'].push_back(i);
        }

        int res  = 0;
        for (auto& w : words) {
            if (find(p, w)) {
                ++res;
            }
        }
        return res;
    }
};


int main() {


    Solution solution;

    string s = "abcde";
    vector<string> w = {"a","bb","acd","ace"};

    solution.numMatchingSubseq(s, w);

    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}