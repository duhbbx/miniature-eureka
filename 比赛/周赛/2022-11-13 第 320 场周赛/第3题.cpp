
#include <bits/stdc++.h>

using namespace std;


// 6243. 到达首都的最少油耗
class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int cost = 0;
        int n = roads.size() + 1;
        vector<int> indegree(n);
        vector<int> represents(n, 1);

        vector<unordered_set<int>> graph(n);

        for (auto& i : roads) {
            ++indegree[i[0]];
            ++indegree[i[1]];

            graph[i[0]].insert(i[1]);
            graph[i[1]].insert(i[0]);
        }

        queue<int> queue1;

        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 1 && i != 0) {
                queue1.push(i);
            }
        }

        while(!queue1.empty()) {

            int len = queue1.size();


            for (int i = 0; i < len; ++i) {

                int v = queue1.front();

                int nei = *graph[v].begin();
                represents[nei] += represents[v];
                cost += 1LL * (represents[v] - 1) / seats + 1;
                represents[v] = 0;
                indegree[v] = 0;

                --indegree[nei];
                graph[nei].erase(v);
                if (indegree[nei] == 1 && nei != 0) {
                    queue1.push(nei);
                }
                queue1.pop();
            }
        }

        return cost;

    }
};


int main() {


    Solution solution;

    vector<vector<int>> nums = {{0,1},{1,2}};
    int seats = 3;

    int cost = solution.minimumFuelCost(nums, seats);


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}