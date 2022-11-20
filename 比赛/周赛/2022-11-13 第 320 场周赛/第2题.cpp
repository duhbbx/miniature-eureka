
#include <bits/stdc++.h>

using namespace std;



//6242. 二叉搜索树最近节点查询

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> res;
        for (auto& q : queries) {
            int maxVal = 10000000;
            int minVal = 0;
            TreeNode* r = root;
            while(r) {
                if (r->val == q) {
                    minVal = r->val;
                    maxVal = r->val;
                    break;
                } else if (r->val < q) {
                    minVal = max(r->val, minVal);
                    r = r->right;
                } else {
                    maxVal = min(r->val, maxVal);
                    r = r->left;
                }
            }

            res.push_back({minVal == 0 ? -1 : minVal, maxVal == 10000000 ? -1 : maxVal});
        }
        return res;
    }
};


int main() {


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}