
#include <iostream>				// 输入输出
#include <vector>				// 可变长度数组
#include <unordered_map>		// hashmap
#include <stack>				// 栈
#include <string>				// 字符串
#include <queue>                // 队列
#include <climits>

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
	
	// 平方求幂
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
		if (root == nullptr) return 0;

		int size = 0;
		std::queue<TreeNode*> q;

		q.push(root); ++size;

		int level = 0;
		while (!q.empty()) {

			TreeNode* head = q.front();
			--size;

			if (size == 0) {
				++level;
				size = q.size();
			}



			if (head->left) q.push(head->left);
			if (head->right) q.push(head->right);
			q.pop();
		}

		return level;
	}

	/// <summary>
	/// 
	/// </summary>
	/// <param name="root">当前根节点</param>
	/// <param name="currentX">根节点的X坐标</param>
	/// <param name="currentLevel">当前的层数</param>
	/// <param name="totalLevel">总的层数</param>
	/// <param name="res">记录结果的矩阵</param>
	void recursive(TreeNode* root, int currentX, int currentLevel, int totalLevel, vector<vector<string>>* res) {


		cout << "currentX = " << currentX << ", currentLevel = " << currentLevel << ", totalLevel = " << totalLevel << endl;

		if (root == nullptr) return;


		cout << "1. 准备设置值了" << endl;
		(*res)[currentLevel - 1][currentX] = root->val;    // TODO val 需要转为字符串

		int subTreeNodeNum = ipow(2, totalLevel - currentLevel + 1) - 1;


		if (root->left) {
			int leftNodeX = currentX - ((subTreeNodeNum >> 2) + 1);
			recursive(root->left, leftNodeX, currentLevel + 1, totalLevel, res);
		}


		if (root->right) {
			int rightNodeX = currentX + ((subTreeNodeNum >> 2) + 1);
			recursive(root->left, rightNodeX, currentLevel + 1, totalLevel, res);
		}

	}



	vector<vector<string>> printTree(TreeNode* root) {

		// 计算整棵树的层数
		int level = getLevel(root);

		int full_node_num = ipow(2, level) - 1;

		// 创建矩阵
		vector<vector<string>> res(level, vector<string>(full_node_num, ""));

		recursive(root, full_node_num, 1, level, &res);


		return res;
	}
};




////////////////////////////////////////////////////////////////////////////////












int main() {


	print<vector<int>>({ 1, 2, 3, 4 });

	return 0;
}