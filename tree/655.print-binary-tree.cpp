
#include <iostream>				// �������
#include <vector>				// �ɱ䳤������
#include <unordered_map>		// hashmap
#include <stack>				// ջ
#include <string>				// �ַ���
#include <queue>                // ����
#include <climits>

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



// Definition for a binary tree node.
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
	vector<vector<string>> printTree(TreeNode* root) {

	}
};




////////////////////////////////////////////////////////////////////////////////












int main() {


	/*print<vector<int>>({ 1, 2, 3, 4 });*/

	return 0;
}