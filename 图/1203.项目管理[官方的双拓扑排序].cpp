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

    vector<int> topologySort(vector<int>& deg, vector<vector<int>>& graph, vector<int>& items) {
        return {};
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {

        vector<vector<int>> groupItem(n + m);       //每个组里面执行的项目,项目数从m个扩充到m+n个
        vector<vector<int>> groupGraph(n + m);      //组间的依赖图
        vector<vector<int>> itemGraph(n);           //组内的依赖图
        vector<int> groupDegree(n+m, 0);            //组间的入度数组
        vector<int> itemDegree(n,0);                //组内的入度数组
        vector<int> id(n+m);
        iota(id.begin(), id.end(), 0);              //id从0到n+m-1

        int leftId = m;
        for (int i = 0; i < n; ++i) {
            if (group[i] == -1) {
                group[i] = leftId++;                //给未分配的item分配一个groupId
            }
            groupItem[group[i]].emplace_back(i);    //每个组有哪些项目就确定了
        }

        for (int i = 0; i < n; ++i) {
            int curGroupId = group[i];              //第i个项目所属的组
            for(auto& item:beforeItems[i]) {        //第i个项目依赖的项目
                int beforeGroupId = group[item];    //第i个项目依赖的项目所属的组的id
                if (beforeGroupId == curGroupId) {  //项目i和项目item属于同一个组
                    itemDegree[i] += 1;             //项目i的入度数加1
                    itemGraph[item].emplace_back(i);//有向图的边从item指向i
                } else {                            //否则的话项目i和所依赖的项目item不是同一个组
                    groupDegree[curGroupId] += 1;   //当前项目的入度数加1
                    groupGraph[beforeGroupId].emplace_back(curGroupId); // 有向图的边由被依赖的项目指向依赖的项目
                }
            }
        }

        //组间的拓扑排序
        vector<int> groupTopologySort = topologySort(groupDegree, groupGraph, id);
        if (groupTopologySort.size() == 0) {        //拓扑排序失败了
            return vector<int>{};
        }

        vector<int> ans;

        //组内的拓扑排序
        for (auto& curGroupId : groupTopologySort) {
            int size = groupItem[curGroupId].size();//获取当前组的项目
            if (size == 0) {                        //当前组没有项目
                continue;                           //继续下一个组的拓扑排序
            }
            vector<int> res = topologySort(itemDegree, itemGraph, groupItem[curGroupId]);
            if (res.size() == 0) {                  //组内的拓扑排序失败了
                return vector<int>{};               //只要拓扑排序失败了就返回{}
            }
            for (auto& item : res) {                //将排序好的结果加到ans中
                ans.emplace_back(item);
            }
        }

        return ans;
    }
};


int main() {


    std::cout << "项目管理" << std::endl;

    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}