//
// Created by duhbb on 2022/9/16.
//
#include <iostream>              // 输入输出
#include <vector>                // 可变长度数组
#include <unordered_map>         // hashmap
#include <stack>                 // 栈
#include <string>                // 字符串
#include <queue>                 // 队列
#include <climits>               // 极限值
#include <algorithm>             // 算法相关的
#include <set>                   // 集合
#include "../0000 API 模板 类/TreeNode.h"
#include "../0000 API 模板 类/ListNode.h"


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



////////////////////////////////////////////////////////////////////////////////
/// 这里放OJ的类

class Solution {
public:
    int rectangleArea(vector<vector<int>> &rectangles) {
        int n = rectangles.size();      // 矩形的个数
        vector<int> hbound;
        for (const auto &rect: rectangles) {                                // 矩形的上边界和下边界放到 vector 中
            hbound.push_back(rect[1]);                                      // 下边界
            hbound.push_back(rect[3]);                                      // 上边界
        }
        sort(hbound.begin(), hbound.end());                                 // 对 vector 进行排序
        hbound.erase(unique(hbound.begin(), hbound.end()), hbound.end());   // 去重
        int m = hbound.size();                                              // 去重之后边界的个数
        // 「思路与算法部分」的 length 数组并不需要显式地存储下来
        // length[i] 可以通过 hbound[i+1] - hbound[i] 得到
        vector<int> seg(m - 1);                                             // y 轴方向上一共有 m - 1 个段
        vector<tuple<int, int, int>> sweep;                                 // sweep 是扫描线的意思？
        for (int i = 0; i < n; ++i) {
            sweep.emplace_back(rectangles[i][0], i, 1);                     // 左边界
            sweep.emplace_back(rectangles[i][2], i, -1);                    // 右边界
        }
        sort(sweep.begin(), sweep.end());                                   // 排序的依据是什么，另外这里没有去重哦

        long long ans = 0;
        for (int i = 0; i < sweep.size(); ++i) {                            // 遍历扫描线中的坐标
            int j = i;                                                      // j 可以看成当前扫描段的起点
            // 找到第一个不同, 当前扫的区间就是 [i, j]
            while (j + 1 < sweep.size() && get<0>(sweep[i]) == get<0>(sweep[j + 1])) {
                ++j;
            }
            // 这种情况就是 i 和 j已经是最右边界了
            if (j + 1 == sweep.size()) {
                break;
            }
            // 一次性地处理掉一批横坐标相同的左右边界
            for (int k = i; k <= j; ++k) {
                auto &&[_, idx, diff] = sweep[k];
                int left = rectangles[idx][1], right = rectangles[idx][3];
                for (int x = 0; x < m - 1; ++x) {
                    if (left <= hbound[x] && hbound[x + 1] <= right) {
                        seg[x] += diff;
                    }
                }
            }
            int cover = 0;
            for (int k = 0; k < m - 1; ++k) {
                if (seg[k] > 0) {
                    cover += (hbound[k + 1] - hbound[k]);
                }
            }
            ans += static_cast<long long>(cover) * (get<0>(sweep[j + 1]) - get<0>(sweep[j]));
            i = j;
        }
        return ans % static_cast<int>(1e9 + 7);
    }
};

//作者：LeetCode-Solution
//        链接：https://leetcode.cn/problems/rectangle-area-ii/solution/ju-xing-mian-ji-ii-by-leetcode-solution-ulqz/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

////////////////////////////////////////////////////////////////////////////////




void printCurrentFileName() {
    string file = __FILE__;
    int pos = file.find_last_of("/");
    string fileName = pos == -1 ? file : file.substr(pos + 1);
    cout << "\n【当前题目为：" << fileName << "】" << endl;
}


int main() {


    printCurrentFileName();


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}