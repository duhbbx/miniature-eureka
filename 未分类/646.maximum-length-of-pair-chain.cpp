
#include <iostream>              // �������
#include <vector>                // �ɱ䳤������
#include <unordered_map>         // hashmap
#include <stack>                 // ջ
#include <string>                // �ַ���
#include <queue>                 // ����
#include <climits>               // ����ֵ
#include <algorithm>             // �㷨��ص�

using namespace std;



/// <summary>
/// ��������е�����
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="t"></param>
template<typename T>
void print(T t) {


    if (!t.empty()) {
        cout << "����Ϊ��............" << endl;
        return;
    }


    for (typename T::const_iterator it = t.begin(); it != t.end() - 1; ++it) {
        cout << *it << ", ";
    }

    cout << *(t.end() - 1) << endl;
}



////////////////////////////////////////////////////////////////////////////////
/// �����OJ����


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

        // �ȶ� pairs �����Զ��������
        sort(pairs.begin(), pairs.end(), compare);

        int size = pairs.size();
        for (int i = 0; i < size; i++) {
            
        }




        // ��һ�����νṹ


        // ����һ��ǰ׺��


        // ������ȼ������Ĳ㼶






        return 0;
    }
};



////////////////////////////////////////////////////////////////////////////////












int main() {


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    cout << "646. �������" << endl;


    return 0;
}