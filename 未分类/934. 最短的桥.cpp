//
// Created by tuhooo on 2022/10/25.
//



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



int s[10000];


class Solution {
public:

    int find(int x) {
        if (s[x] == x) {
            return x;
        } else {
            s[x] = find(s[x]);
            return s[x];
        }
    }

    void merge(int x, int y) {
        s[x] = find(y);
    }


    int shortestBridge(vector<vector<int>>& grid) {

        memset(s, 0, sizeof(s));    // 将s清空
        for (int i = 0; i < grid.size() * grid.size(); ++i) {
            s[i] = i;
        }

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid.size(); ++j) {
                if (grid[i][j] ==  0) {
                    continue;
                } else {
                    if (j > 0 && grid[i][j-1] == 1) {
                        merge(i*grid.size()+j, i*grid.size()+j-1);
                    }
                    if (j < grid.size()-1 && grid[i][j+1] == 1) {
                        merge(i*grid.size()+j, i*grid.size()+j +1);
                    }

                    if (i < grid.size()-1 &&  grid[i+1][j] == 1) {
                        merge(i*grid.size() + j, (i+1)*grid.size() + j);
                    }
                }
            }
        }



        for (int i = 0; i < grid.size() * grid.size(); ++i) {
            cout << "i = " << s[i] << endl;
        }

        int res = 10000;
        for (int i = 0; i < grid.size() * grid.size(); ++i) {
            for (int j = 0; j < grid.size() * grid.size(); ++j) {

                if (grid[i/(int) grid.size()][i%(int) grid.size()] == 0 ||
                    grid[j/(int) grid.size()][j%(int) grid.size()] == 0) {
                    continue;
                }
                if (find(i) != find(j)) {
                    res = min(abs(i / (int)grid.size() - j / (int)grid.size() -1 + i % (int)grid.size() + j % (int)grid.size() - 1), res);


                }
            }
        }

        return res;
    }
};


int main() {


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}