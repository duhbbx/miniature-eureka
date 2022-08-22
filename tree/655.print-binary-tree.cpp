
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
	vector<vector<string>> printTree(TreeNode* root) {

	}
};




////////////////////////////////////////////////////////////////////////////////












int main() {


	/*print<vector<int>>({ 1, 2, 3, 4 });*/

	return 0;
}