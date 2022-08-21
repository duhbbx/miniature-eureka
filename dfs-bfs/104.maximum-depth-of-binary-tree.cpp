
#include <iostream>             // 输入输出
#include <vector>               // 可变长度数组
#include <unordered_map>        // hashmap
#include <stack>                // 栈
#include <string>				// 字符串
#include <queue>                // 队列
using namespace std;



/// <summary>
/// 输出容器中的内容
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="t"></param>
template<typename T>
void print(T t) {



	for (typename T::const_iterator it = t.begin(); it != t.end() - 1; ++it) {
		cout << *it << ", ";
	}

	cout << *(t.end() - 1) << endl;
}



/*
Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



////////////////////////////////////////////////////////////////////////////////
/// 这里放OJ的类




class Solution {
public:
	int maxDepth(TreeNode* root) {

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
};


class Solution1 {
public:
	int maxDepth(TreeNode* root) {

		if (root == nullptr) return 0;

		int size = 0;
		std::queue<TreeNode*> q;

		q.push(root); ++size;

		int level = 0;
		while (!q.empty()) {
			while (size > 0) {
				TreeNode* head = q.front();
				q.pop();
				if (head->left) q.push(head->left);
				if (head->right) q.push(head->right);
				--size;
			}

			++level;
			size = q.size();
		}

		return level;
	}
};



////////////////////////////////////////////////////////////////////////////////


int main() {


	print<vector<int>>({ 1, 2, 3, 4 });





	return 0;
}