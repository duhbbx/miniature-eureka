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
    vector<bool> canMakePaliQueries(string s, vector<vector<int>> &queries) {

        int n = queries.size();
        vector<bool> res(n, false);

        vector<vector<int>> prefixSum(s.size() + 1, vector<int>(26, 0));


        for (int i = 0; i < s.size(); ++i) {
            prefixSum[i + 1] = prefixSum[i];
            ++prefixSum[i + 1][s[i] - 'a'];
        }


        for (int i = 0; i < n; ++i) {

            auto &query = queries[i];

            int diff = 0;
            for (int j = 0; j < 26; ++j) {

                diff += (prefixSum[query[1] + 1][j] - prefixSum[query[0]][j]) % 2 ? 1 : 0;
            }


            res[i] = query[2] >= diff / 2;


        }

        return res;
    }
};

//class Solution
//{
//public:
//    /*每次迭代均递归，超时*/
//    vector<bool> canMakePaliQueries_prev(string s, vector<vector<int>> &queries)
//    {
//        vector<bool> result;
//        for (auto &query : queries)
//        {
//            int left = query[0], right = query[1], k = query[2];
//            unordered_map<char, int> dict;
//            /*构建哈希表，即每个字母和出现的次数*/
//            for (int i = left; i <= right; i++)
//                dict[s[i]]++;
//            int need_to_change = 0;
//            /*遍历哈希表求得出现奇数次数的字母*/
//            for (auto &p : dict)
//                if (p.second % 2)
//                    need_to_change++;
//            /*判断子串是否是奇数长度*/
//            int odd = (right - left + 1) % 2;
//            /*每次修改都可以减掉两个出现奇数次数的字母*/
//            need_to_change -= 2 * k + odd;
//            /*若没有奇数次数的字母，则可以构成回文串*/
//            result.emplace_back(need_to_change <= 0);
//        }
//        return result;
//    }
//    /*优化后的算法，打表记录每个字母在每个状态的奇偶性，位运算减少开销*/
//    vector<bool> canMakePaliQueries(string s, vector<vector<int>> &queries)
//    {
//        /*结果集*/
//        vector<bool> res(queries.size(), 0);
//        /*从(0,0)到(0,n)的[字母-奇偶]映射*/
//        vector<long> hash(s.size() + 1, 0);
//        /*位运算表示奇偶状态*/
//        long stat = 0;
//        // 1表示奇数。0表示偶数
//        for (int i = 0; i < s.size(); ++i)
//        {
//            stat = stat ^ (1 << (s[i] - 'a'));
//            hash[i + 1] = stat;
//        }
//        for (int i = 0; i < queries.size(); ++i)
//        {
//            /*直接比较right和left的状态差异即可，无需遍历*/
//            int tmp = hash[queries[i][1] + 1] ^ hash[queries[i][0]];
//            int odd = 0;
//            while (tmp)
//            {
//                odd++;
//                /*迭代每一位*/
//                tmp = tmp & (tmp - 1);
//            }
//            /*利用整除取消子串长度奇偶性的讨论*/
//            if (odd / 2 <= queries[i][2])
//                res[i] = 1;
//        }
//        return res;
//    }
//};


int main() {


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}