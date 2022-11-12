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
#include "../../../0000 API 模板 类/TreeNode.h"
#include "../../../0000 API 模板 类/ListNode.h"


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

/*
[2,3,5,8,13,21,34]
[7,13,11]
[0,1,2,0,0,0,0,1,1,1,1,2,2,2,2]

 */
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {




        vector<TreeNode*> q;

        q.push_back(root);

        int level = 0;
        while(!q.empty()) {

            int n = q.size();
            for (int i = 0; i < n; i++) {
                if (q.front()->left) {
                    q.push_back(q.front()->left);
                }

                if (q.front()->right) {
                    q.push_back(q.front()->right);
                }

                q.erase(q.begin());
            }

            ++level;

            if (level % 2 == 1) {
                int i = 0, j = q.size() - 1;
                while(i < j) {
                    int tmp = q[i]->val;
                    q[i]->val = q[j]->val;
                    q[j]->val = tmp;
                    ++i;
                    --j;
                }
            }
        }


        return root;
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

    TreeNode* root = new TreeNode(7);
    TreeNode* left = new TreeNode(13);
    TreeNode* right = new TreeNode(11);

    root->left = left;
    root->right = right;

    solution.reverseOddLevels(root);


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}