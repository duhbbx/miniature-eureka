//
// Created by duhbb on 2022/9/18.
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

struct Island {
    set<vector<int>> points;
    int area;
};


class Solution {
public:
    int largestIsland(vector<vector<int>> &grid) {

        queue<vector<int>> q;

        vector<Island*> islands;

        int maxIsland = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {

                if (grid[i][j] != 1) {
                    continue;
                }

                int sum = 0;
                Island *island = new Island;
                q.push({i, j});
                while (!q.empty()) {
                    int n = q.size();
                    for (int k = 0; k < n; ++k) {
                        sum += 1;

                        int x = q.front()[0];
                        int y = q.front()[1];

                        grid[x][y] = 2;

                        q.pop();
                        island->points.insert({x, y});
                        if (y - 1 >= 0 && grid[x][y - 1] == 1) { q.push({x, y - 1}); grid[x][y-1] = 3; }
                        if (y + 1 < grid.size() && grid[x][y + 1] == 1) {q.push({x, y + 1}); grid[x][y+1] =3; }
                        if (x - 1 >= 0 && grid[x - 1][y] == 1) {q.push({x - 1, y}); grid[x-1][y] = 3;}
                        if (x + 1 < grid[i].size() && grid[x + 1][y] == 1) {q.push({x + 1, y}); grid[x+1][y] = 3;}
                    }
                }

                island->area = sum;
                maxIsland = max(sum, maxIsland);
                islands.push_back(island);
            }
        }

        int res = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] != 0) {
                    continue;
                }

                int x = i;
                int y = j;

                if (y - 1 >= 0 && grid[x][y - 1] == 0 && y + 1 < grid.size() && grid[x][y + 1] == 0 && x - 1 >= 0 && grid[x - 1][y] == 0 && x + 1 < grid[i].size() && grid[x + 1][y] == 0) {
                    continue;
                }

                int sum = 0;



                set<Island*> choose;


                for (auto& island : islands) {
                    if (y - 1 >= 0 && grid[x][y - 1] == 2 && island->points.find({x, y - 1}) != island->points.end() && choose.find(island) == choose.end()) {
                        sum += island->area;
                        choose.insert(island);
                    }

                    if (y + 1 < grid.size() && grid[x][y + 1] == 2 && island->points.find({x, y + 1}) != island->points.end() && choose.find(island) == choose.end()) {
                        sum += island->area;
                        choose.insert(island);
                    }

                    if (x - 1 >= 0 && grid[x - 1][y] == 2 && island->points.find({x-1, y}) != island->points.end() && choose.find(island) == choose.end()) {
                        sum += island->area;
                        choose.insert(island);
                    }

                    if (x + 1 < grid[i].size() && grid[x + 1][y] == 2 && island->points.find({x+1, y}) != island->points.end() && choose.find(island) == choose.end()) {
                        sum += island->area;
                        choose.insert(island);
                    }
                }

                sum += 1;

                res = max(sum, res);
            }
        }

        return max(maxIsland, res);
    }
};



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

    vector<vector<int>> grid = {
            {1, 1},
            {1, 1}
    };

    solution.largestIsland(grid);

    return 0;
}