
#define ENABLE_DEBUG

#include <bits/stdc++.h>

using namespace std;

#ifdef ENABLE_DEBUG
#define TRACE_ME(format, ...) printf("%s(%d)-<%s>: " format "\n", __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__);
#define RELOCATE()                            \
    do {                                      \
        freopen("D:\\input.txt", "r", stdin); \
    } while (0)

#endif

#ifndef ENABLE_DEBUG
#define TRACE_ME(__fmt__, ...)
#define RELOCATE()
#endif

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode()
        : val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int x)
        : val(x), left(nullptr), right(nullptr) {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {
    }
};

class Solution {

  public:
    int rob(TreeNode *root) {

        return get(root);
    }

    int get(TreeNode *root) {

        if (!root) {
            return 0;
        }

        int delta1 = 0;

        // choose root
        delta1 += root->val;
        if (root->left) {
            delta1 += rob(root->left->left) + rob(root->left->right);
        }
        if (root->right) {
            delta1 += rob(root->right->left) + rob(root->right->right);
        }

        // not choose root
        int delta2 = 0;
        delta2 = rob(root->left) + rob(root->right);

        return max(delta1, delta2);
    }
};

int main() {

    RELOCATE();

    return 0;
}
