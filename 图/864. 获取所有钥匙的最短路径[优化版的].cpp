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



struct Node {
    // 距离起点的距离
    int dist;
    // 所在字符
    char curr;
    // 钥匙获取的状态，目标值是target1
    int state;

    Node(int dist, char curr, int state) : dist(dist), curr(curr), state(state) {}
};

// 小顶堆的实现，把dist最小的排在上面
bool operator<(const Node& a, const Node& b)
{
    return a.dist > b.dist;
}

class Solution {
private:
    int R;
    int C;

    unordered_map<char, int> nextDistance(char source,  unordered_map<char, int>& char2loc, vector<string>& grid) {
        int r = char2loc[source] / 100;
        int c = char2loc[source] % 100;

        // bfs查找避免循环，引入一个seen列表
        bool seen[R][C];
        memset(seen, false, sizeof(seen));

        // 返回结果
        unordered_map<char, int> distances;

        // 四个方向
        int directions[5] = {1, 0, -1, 0, 1};

        // 初始化插入起点
        queue<pair<int, int>> q;
        q.push({r, c});
        seen[r][c] = true;

        int steps = 0;
        while (!q.empty()) {
            for (int i = q.size(); i > 0; --i) {
                r = q.front().first;
                c = q.front().second;
                q.pop();

                if (grid[r][c] != source && grid[r][c] != '.') {
                    distances[grid[r][c]] = steps;
                    // 关键实现：一旦找到则不再往前
                    continue;
                }

                for (int j = 0; j < 4; ++j) {
                    int nextR = r + directions[j];
                    int nextC = c + directions[j+1];
                    if (nextR >= 0 && nextR < R && nextC >= 0 && nextC < C && !seen[nextR][nextC] && grid[nextR][nextC] != '#') {
                        seen[nextR][nextC] = true;
                        q.push({nextR, nextC});
                    }
                }
            }
            ++steps;
        }

        // cout << "====== from " << source << endl;
        // for (auto iter = distances.begin(); iter != distances.end(); ++iter)
        // {
        //     cout << iter->first << " " << iter->second << endl;
        // }
        return distances;
    }

public:
    int shortestPathAllKeys(vector<string>& grid) {
        R = grid.size();
        C = grid[0].size();

        // 用一个int来表示二维坐标，这里最大是30，所以用100已经足够
        unordered_map<char, int> char2loc;
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                char curr = grid[r][c];
                if (curr != '.' && curr != '#') {
                    char2loc[curr] = r*100 + c;
                }
            }
        }

        // 距离的关系映射
        unordered_map<char, unordered_map<char, int>> distances;
        for (auto iter = char2loc.begin(); iter != char2loc.end(); ++iter) {
            distances[iter->first] = nextDistance(iter->first, char2loc, grid);
        }

        // 目标状态，一个bit构成数字来表示哪些位置已经有钥匙，而且钥匙是从a开始计算的
        // 考虑到一半是钥匙一半是锁，要除以2
        int target = (1<<(char2loc.size()/2)) - 1;

        // 从（当前节点+状态）到起点的距离映射 : 这里用 char*256 + state 变为一维
        // 这个是方便快速比较使用的
        unordered_map<int, int> destMap;
        destMap['@'*256 + 0] = 0;

        // 小顶堆的队列，距离越小优先取出
        priority_queue<Node> q;
        q.emplace(Node(0, '@', 0));

        while (!q.empty()) {
            Node node = q.top();
            q.pop();
            int nodeDist = node.dist;

            // 找到目标直接返回当前距离，就是最小距离
            if (node.state == target) {
                return nodeDist;
            }

            // 一次遍历当前节点可达的下一个结点
            auto& nexts = distances[node.curr];
            // cout << "==============" << endl;
            // cout << "curr " << node.curr << " state " << node.state << endl;
            for (auto iter = nexts.begin(); iter != nexts.end(); ++iter) {
                int d2 = iter->second;
                int s2 = node.state;
                if (iter->first >= 'a' && iter->first <= 'z') {
                    s2 |= (1 << (iter->first - 'a'));
                } else if (iter->first >= 'A' && iter->first <= 'Z') {
                    // 对于锁的情况，则需要有钥匙，否则忽略
                    if ((s2  & (1 << (iter->first - 'A'))) == 0) {
                        continue;
                    }
                }
                // cout << "try " << iter->first << endl;
                // 只有距离更小的情况才需要插入到 优先队列里
                int currState = iter->first * 256 + s2;
                // 关键实现：这里条件是小于，等于也要忽略，否则会循环
                if ((destMap.find(currState) == destMap.end()) ||  (nodeDist + d2 < destMap[currState])) {
                    // cout << "add next " << iter->first << " with " << nodeDist+d2 << endl;
                    destMap[currState] = nodeDist + d2;
                    q.emplace(Node{nodeDist + d2, iter->first, s2});
                }
            }
        }

        // 默认不能完成返回-1
        return -1;
    }
};


int main() {

    // vector<string> grid = {"@...a", ".###A", "b.BCc"};
    vector<string> grid = {"@abcdeABCDEFf"};

    Solution solution;

    solution.shortestPathAllKeys(grid);


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}