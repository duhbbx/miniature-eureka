#include <iostream>              // 输入输出
#include <vector>                // 可变长度数组
#include <unordered_map>         // hashmap
#include <stack>                 // 栈
#include <string>                // 字符串
#include <queue>                 // 队列
#include <climits>               // 极限值
#include <algorithm>             // 算法相关的
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


/*有一个甜甜圈商店，每批次都烤batchSize个甜甜圈。这个店铺有个规则，就是在烤一批新的甜甜圈时，
 * 之前 所有甜甜圈都必须已经全部销售完毕。给你一个整数 batchSize和一个整数数组 groups，
 * 数组中的每个整数都代表一批前来购买甜甜圈的顾客，其中 groups[i]表示这一批顾客的人数。每一位顾客都恰好只要一个甜甜圈。

当有一批顾客来到商店时，他们所有人都必须在下一批顾客来之前购买完甜甜圈。
 如果一批顾客中第一位顾客得到的甜甜圈不是上一组剩下的，那么这一组人都会很开心。

你可以随意安排每批顾客到来的顺序。请你返回在此前提下，最多有多少组人会感到开心。



示例 1：

输入：batchSize = 3, groups = [1,2,3,4,5,6]
输出：4
解释：你可以将这些批次的顾客顺序安排为 [6,2,4,5,1,3] 。那么第 1，2，4，6 组都会感到开心。
示例 2：

输入：batchSize = 4, groups = [1,3,2,5,2,2,1,6]
输出：4

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/maximum-number-of-groups-getting-fresh-donuts
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/


class Solution {
public:
    int maxHappyGroups(int batchSize, vector<int> &groups) {
        int *que = new int[9]{0};                   // 创建一个长度为 9 的全 0 数组
        int res = 0;
        for (int i = 0; i < groups.size(); i++) {
            if (groups[i] % batchSize == 0) {
                res++;                              // 能够一批搞完了优先处理
            } else {
                que[groups[i] % batchSize] += 1;    // 取余记录一下有几个不同的
            }
        }


        // 两两凑一对
        for (int i = 1; i <= (batchSize - 1) / 2; i++) {
            int temp = INT_MAX;
            temp = min(temp, que[i]);
            temp = min(temp, que[batchSize - i]);
            res += temp;
            que[i] -= temp;
            que[batchSize - i] -= temp;
        }


        // batchSize为偶数情况
        if (batchSize % 2 == 0) {
            res += que[batchSize / 2] / 2;
            que[batchSize / 2] -= ((que[batchSize / 2] / 2) * 2);
        }

        // 剩下还没匹配的弄成一个 8 维数组
        int dp[que[1] + 1][que[2] + 1][que[3] + 1][que[4] + 1][que[5] + 1][que[6] + 1][que[7] + 1][que[8] + 1];


        // 这里相当于对剩下的数的全排列
        for (int a = 0; a <= que[1]; a++) {
            for (int b = 0; b <= que[2]; b++) {
                for (int c = 0; c <= que[3]; c++) {
                    for (int d = 0; d <= que[4]; d++) {
                        for (int e = 0; e <= que[5]; e++) {
                            for (int f = 0; f <= que[6]; f++) {
                                for (int g = 0; g <= que[7]; g++) {
                                    for (int h = 0; h <= que[8]; h++) {


                                        dp[a][b][c][d][e][f][g][h] = 0;

                                        int tempsum = a * 1 + b * 2 + c * 3 + d * 4 + e * 5 + f * 6 + g * 7 + h * 8;

                                        if (a > 0) {
                                            dp[a][b][c][d][e][f][g][h] = max(dp[a][b][c][d][e][f][g][h], dp[a - 1][b][c][d][e][f][g][h] + ((tempsum - 1) % batchSize == 0));
                                        }

                                        if (b > 0) {
                                            dp[a][b][c][d][e][f][g][h] = max(dp[a][b][c][d][e][f][g][h], dp[a][b - 1][c][d][e][f][g][h] + ((tempsum - 2) % batchSize == 0));
                                        }

                                        if (c > 0) {
                                            dp[a][b][c][d][e][f][g][h] = max(dp[a][b][c][d][e][f][g][h], dp[a][b][c - 1][d][e][f][g][h] + ((tempsum - 3) % batchSize == 0));
                                        }

                                        if (d > 0) {
                                            dp[a][b][c][d][e][f][g][h] = max(dp[a][b][c][d][e][f][g][h], dp[a][b][c][d - 1][e][f][g][h] + ((tempsum - 4) % batchSize == 0));
                                        }

                                        if (e > 0) {
                                            dp[a][b][c][d][e][f][g][h] = max(dp[a][b][c][d][e][f][g][h], dp[a][b][c][d][e - 1][f][g][h] + ((tempsum - 5) % batchSize == 0));
                                        }

                                        if (f > 0) {
                                            dp[a][b][c][d][e][f][g][h] = max(dp[a][b][c][d][e][f][g][h], dp[a][b][c][d][e][f - 1][g][h] + ((tempsum - 6) % batchSize == 0));
                                        }

                                        if (g > 0) {
                                            dp[a][b][c][d][e][f][g][h] = max(dp[a][b][c][d][e][f][g][h], dp[a][b][c][d][e][f][g - 1][h] + ((tempsum - 7) % batchSize == 0));
                                        }

                                        if (h > 0) {
                                            dp[a][b][c][d][e][f][g][h] = max(dp[a][b][c][d][e][f][g][h], dp[a][b][c][d][e][f][g][h - 1] + ((tempsum - 8) % batchSize == 0));
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return res + dp[que[1]][que[2]][que[3]][que[4]][que[5]][que[6]][que[7]][que[8]];
    }
};

//作者：john_shelvin
//        链接：https://leetcode.cn/problems/maximum-number-of-groups-getting-fresh-donuts/solution/cpp-8zhong-xun-huan-dp-by-john_shelvin-kjog/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


////////////////////////////////////////////////////////////////////////////////






void printCurrentFileName() {
    string file = __FILE__;
    int pos = file.find_last_of("/");
    string fileName = pos == -1 ? file : file.substr(pos + 1);
    cout << "【当前题目为：" << fileName << "】" << endl;
}


int main() {


    printCurrentFileName();

    Solution s;

    vector<int> groups = {1, 3, 2, 5, 2, 2, 1, 6};
    int res = s.maxHappyGroups(4, groups);
    cout << "结果: " << res << endl;

    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}