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
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {

        int res = 0;
        int n = status.size();

        queue<int> queue1;

        for (auto initialBox : initialBoxes) {
            if (status[initialBox] == 0) {
                status[initialBox] = 2;     //得到盒子但是没有打开
            } else {
                status[initialBox] = 3;     //得到盒子而且已经打开了,但是未访问
                queue1.push(initialBox);
            }
        }

        vector<int> obtainedKeys(n);

        while(!queue1.empty()) {
            int len = queue1.size();
            for (int i = 0; i < len; ++i) {
                auto cur = queue1.front();  //得到当前已经打开且未访问的盒子
                queue1.pop();
                if (status[cur] == 4) {
                    continue;
                }
                status[cur] = 4;            //已经访问当前的盒子了

                // 记下来我们打开这个盒子拿到的key
                for(auto key : keys[cur]) {
                    obtainedKeys[key] = 1;
                }

                //看看我们从cur这个盒子中获得了哪些新盒子
                for(auto newBox : containedBoxes[cur]) {
                    if (status[newBox] == 0) {
                        status[newBox] = 2; //没有得到钥匙盒子只能是关闭的状态
                    } else {
                        status[newBox] = 3; //得到了盒子但是没有访问
                        queue1.push(newBox);
                    }
                }

                for (int j = 0; j < n; ++j) {
                    if (obtainedKeys[j] == 1 && status[j] == 2) {
                        status[j] = 3;
                        queue1.push(j);
                    }
                }
                /* 这个地方要用index循环,不能用增强的
                for (auto key : obtainedKeys) {
                    if (key == 1 && status[key] == 2) {
                        status[key] = 3;
                        queue1.push(key);
                    }
                }*/

                res += candies[cur];
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