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



class StockSpanner {

private:
    unordered_map<int, pair<int, int>> m;  // 记录每个位置的序号的
    int idx = -1;

public:
    StockSpanner() {

    }

    int next(int price) {

        int res;
        ++idx;

        if (idx == 0) {
            m[0] = pair<int, int>(price, -1);
            res = 1;
        } else {
            res = 1;

            int last = idx-1;

            while(last >= 0 && m[last].first <= price) {
                res += last - m[last].second;
                last = m[last].second;
            }

            m[idx] = pair<int, int>(price, last);
        }

        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */




int main() {





    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}