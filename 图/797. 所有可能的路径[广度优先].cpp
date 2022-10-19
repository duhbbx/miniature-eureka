
#include <bits/stdc++.h>


using namespace std;



class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        unordered_map<int, vector<vector<int>>> m;
        queue<int> q;
        q.emplace(0);
        m[0] = {{0}};
        int endVertex = graph.size() - 1;
        vector<vector<int>> res;

        vector<int> visited(graph.size(), 0);



        while(!q.empty()) {
            int len = q.size();

            for (int i = 0; i < len; ++i) {



                int currVertex = q.front();
                q.pop();

                for (int j = 0; j < graph[currVertex].size(); ++j) {

                    int adjacentVertex = graph[currVertex][j];
                    vector<vector<int>> newPath(m[currVertex]);
                    for (auto &np: newPath) {
                        np.push_back(adjacentVertex);
                    }

                    if (adjacentVertex == endVertex) {
                        res.insert(res.end(), newPath.begin(), newPath.end());
                    } else {
                        m[adjacentVertex].insert(m[adjacentVertex].end(), newPath.begin(), newPath.end());
                        q.push(adjacentVertex);
                    }
                }

                m.erase(currVertex);
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