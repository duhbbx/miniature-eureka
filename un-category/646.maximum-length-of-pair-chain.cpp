
#include <iostream>              // 输入输出
#include <vector>                // 可变长度数组
#include <unordered_map>         // hashmap
#include <stack>                 // 栈
#include <string>                // 字符串
#include <queue>                 // 队列
#include <climits>               // 极限值
#include <algorithm>             // 算法相关的

using namespace std;



/// <summary>
/// 输出容器中的内容
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="t"></param>
template<typename T>
void print(T t) {


    if (!t.empty()) {
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


bool compare(vector<int> a, vector<int> b) {
    if (a[0] < b[0]) {
        return true;
    } else if (a[0] == b[0]) {
        return a[1] < b[1];
    } else {
        return false;
    }
}


class TreeNode {
public:
    int m_index;

    vector<TreeNode> *m_sub_tree_node_list;

    TreeNode(int index) : m_index(index) {
        m_sub_tree_node_list = new vector<TreeNode>();
    }

    ~TreeNode() {
        delete m_sub_tree_node_list;
        m_sub_tree_node_list = nullptr;
    }
};



class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {

        // 先对 pairs 进行自定义的排序
        sort(pairs.begin(), pairs.end(), compare);

        int size = pairs.size();
        for (int i = 0; i < size; i++) {
            
        }




        // 整一个树形结构


        // 构造一个前缀树


        // 深度优先计算最大的层级






        return 0;
    }
};



////////////////////////////////////////////////////////////////////////////////












int main() {


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    cout << "646. 最长数对链" << endl;


    return 0;
}