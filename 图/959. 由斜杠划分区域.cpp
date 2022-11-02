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


#define IDX(m) (4 * i + j + (m))
#define MAXN 4000

class Solution {
public:

    vector<int> fa;

    int row;
    int col;
    int n;

    int count;

    Solution() : fa(vector<int>(MAXN)) {

    }

    void mergeUpDownBlock() {

        int x = 4 * (row * n + col) + 2;
        int y = 4 * ((row + 1) * n + col) + 0;

        merge(x, y);
    }

    void mergeLeftRightBlock() {
        int x = 4 * (row * n + col) + 1;
        int y = 4 * (row * n + (col + 1)) + 3;

        merge(x, y);
    }

    void mergeSameBlock(int x, int y) {
        x = 4 * (row * n + col) + x;
        y = 4 * (row * n + col) + y;

        merge(x, y);
    }

    void merge(int x, int y) {
        int fx = find(x);
        int fy = find(y);

        if (fx == fy) {
            return;
        }

        fa[fx] = fy;

        --count;
    }

    int find(int x) {

        if (x == fa[x]) {
            return x;
        } else {
            fa[x] = find(fa[x]);
            return fa[x];
        }
    }


    int regionsBySlashes(vector<string>& grid) {


        iota(fa.begin(), fa.end(), 0);

        n = grid.size();
        int subTriangleNum = 4 * n * n;
        count = subTriangleNum;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {


                this->row = i;
                this->col = j;


                char currChar = grid[i][j];
                if (currChar == '/') {
                    mergeSameBlock(0, 3);
                    mergeSameBlock(1, 2);
                } else if (currChar == '\\') {
                    mergeSameBlock(0, 1);
                    mergeSameBlock(2, 3);
                } else {
                    mergeSameBlock(0, 1);
                    mergeSameBlock(1, 2);
                    mergeSameBlock(2, 3);
                    mergeSameBlock(3, 0);
                }

                if (i < n - 1) {
                    mergeUpDownBlock();
                }

                if (j < n - 1) {
                    mergeLeftRightBlock();
                }
            }
        }


        return count;
    }
};




int main() {


    Solution solution;

    vector<string> grid ={" /","/ "};

    solution.regionsBySlashes(grid);


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}