
#include <bits/stdc++.h>


using namespace std;



class Solution {
public:

    void dfs(int start, int end, vector<int>& path, vector<vector<int>>& res, vector<vector<int>>& graph) {
        if (start == end) {
            res.push_back(path);
            return;
        }

        for (auto& counterpart : graph[start]) {
            path.push_back(counterpart);
            dfs(counterpart, end, path, res, graph);
            path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path;
        path.push_back(0);
        dfs(0, graph.size()-1, path, res, graph);
        return res;
    }
};



int main() {


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}