
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
	
	// ƽ������
	int ipow(int base, int exp) {
		int result = 1;
		for (;;) {
			if (exp & 1)
				result *= base;
			exp >>= 1;
			if (!exp)
				break;
			base *= base;
		}

		return result;
	}

	int getLevel(TreeNode* root) {
		return 2;
	}

	/// <summary>
	/// 
	/// </summary>
	/// <param name="root">��ǰ���ڵ�</param>
	/// <param name="currentX">���ڵ��X����</param>
	/// <param name="currentLevel">��ǰ�Ĳ���</param>
	/// <param name="totalLevel">�ܵĲ���</param>
	/// <param name="res">��¼����ľ���</param>
	void recursive(TreeNode* root, int currentX, int currentLevel, int totalLevel, vector<vector<string>>* res) {

	}



	vector<vector<string>> printTree(TreeNode* root) {

		// �����������Ĳ���
		int level = getLevel(root);

		int full_node_num = ipow(2, level) - 1;

		// ��������
		vector<vector<string>> res(level, vector<string>(full_node_num, ""));

		recursive(root, full_node_num, 1, &res);


	}
};




////////////////////////////////////////////////////////////////////////////////












int main() {


	/*print<vector<int>>({ 1, 2, 3, 4 });*/

	return 0;
}