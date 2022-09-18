#include <iostream>              // 输入输出
#include <vector>                // 可变长度数组
#include <unordered_map>         // hashmap
#include <stack>                 // 栈
#include <string>                // 字符串
#include <queue>                 // 队列
#include <climits>               // 极限值
#include <algorithm>             // 算法相关的
#include <set>                   // 集合
#include "../../0000 API 模板 类/TreeNode.h"
#include "../../0000 API 模板 类/ListNode.h"


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



class MyTreeNode {
public:
    unordered_map<char, MyTreeNode*> v;

    char c;

    int n;
};


class Solution {
public:

    int get(MyTreeNode* root, string& s) {

        int sum = 0;
        MyTreeNode* cur = root;
        for (int k = 0; k < s.length(); k++) {
            cur = cur->v[s[k]];
            sum += cur->n;
        }

        return sum;
    }

    vector<int> sumPrefixScores(vector<string> &words) {

        MyTreeNode* root = new MyTreeNode;

        MyTreeNode* cur = root;

        for (string& s : words) {
            for (char c : s) {
                if (cur->v.find(c) == cur->v.end()) {
                    cur->v[c] = new MyTreeNode;
                    cur->v[c]->n = 1;
                    cur = cur->v[c];
                } else {
                    cur->v[c]->n++;
                    cur = cur->v[c];
                }
            }

            cur = root;
        }


        vector<int> res;
        for (string& s : words) {

            int sum = get(root, s);

            res.push_back(sum);
        }


        return res;
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


    vector<string> v = {"abcd"};

    solution.sumPrefixScores(v);


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}