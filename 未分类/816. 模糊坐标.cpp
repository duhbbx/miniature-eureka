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
    vector<string> getLegalNumber(string& s, int start, int end) {

        vector<string> res;


        if (s[start] != '0') {  // 如果不包含前缀0的话可以作为整数
            res.push_back(s.substr(start, end - start));

            // 2343000
            // 23345
            if (s[end-1] != '0' && end - start > 1) {   // 如果不包含后缀0且长度大于1就可以做小数

                for (int i = 0; i < end - start - 1; ++i) {
                    string tmp = "";
                    for (int j = start; j < end; ++j) {
                        tmp.push_back(s[j]);
                        if (j - start == i) {
                            tmp.push_back('.');
                        }
                    }

                    res.push_back(tmp);
                }
            }


        } else {                // 如果包含前缀0只能是小数了
            // 0000343434
            // 000343434000
            if (end -start == 1) {
                res.push_back("0");
            }

            if (s[end-1] != '0' && end - start > 1) {
                string tmp = "";

                for (int i = start; i < end; ++i) {

                    tmp.push_back(s[i]);
                    if (i == start) {
                        tmp.push_back('.');
                    }
                }

                res.push_back(tmp);
            }
        }

        return res;

    }
public:


    vector<string> ambiguousCoordinates(string s) {

        int n = s.size();



        vector<string> res;

        for (int i = 2; i < n - 1; ++i) {
            vector<string> first = getLegalNumber(s, 1, i);
            vector<string> second = getLegalNumber(s, i, n - 1);


            cout << s.substr(1, i - 1) << "      " << s.substr(i, n - 1 - i) << endl;


            for (auto& s1 : first) {
                for (auto& s2: second) {
                    res.push_back("(" + s1 + ", " + s2 + ")");
                }
            }


        }

        return res;
    }
};


int main() {


    Solution solution;

    solution.ambiguousCoordinates("(0123)");


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}