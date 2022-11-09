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
#include <random>

using namespace std;

class Solution {

    vector<vector<int>> rects;

    vector<long> prefixSum;

    independent_bits_engine<default_random_engine,64,unsigned long long int> engine;

public:
    Solution(vector<vector<int>>& rects) : prefixSum(rects.size() + 1, 0) {

        this->rects = rects;

        for (int i = 0; i < rects.size(); ++i) {

            int a = rects[i][0];
            int b = rects[i][1];
            int x = rects[i][2];
            int y = rects[i][3];

            prefixSum[i+1] = prefixSum[i] + (x - a + 1) * (y - b + 1);

            cout << prefixSum[i+1] << ", ";


        }
        cout << endl;
    }



    vector<int> pick(int i) {
        int x = (rand() % (rects[i][2]-rects[i][0]+1))+ rects[i][0];
        int y = (rand() % (rects[i][3]-rects[i][1]+1))+ rects[i][1];
        return {x, y};
    }

    int binary_search(long int val) {

        int l = 0, r = rects.size();

        int m = (l + r) >> 1;
        while(l < r) {

            if (prefixSum[(l+r)/2] <= val) {
                l = m;
            } else {
                r = m;
            }
        }

        cout << "val = " << val <<  ",          m = " << m << endl;
        return m;
    }

    vector<int> pick() {




        long int area = engine() % (prefixSum[rects.size()]);

        int m = binary_search(area);

        return pick(m);
    }
};

int main() {


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}