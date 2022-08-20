
#include <iostream>				// 输入输出
#include <vector>				// 可变长度数组
#include <unordered_map>		// hashmap
#include <stack>				// 栈
#include <string>				// 字符串

using namespace std;




////////////////////////////////////////////////////////////////////////////////
/// 这里放OJ的类
/**
 * Definition for a binary tree node.
 */

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


class Solution {
public:


	void sub(int begin, int end, vector<int>& nums, TreeNode* tree) {

		int max = nums[begin];
		int index = begin;
		
	
		// 找到最大值
		for (int i = begin + 1; i <= end; i++) {
			if (max < nums[i]) {
				max = nums[i];
				index = i;
			}
		}

		tree->val = max;

		if (index > begin) {
			tree->left = new TreeNode;
			sub(begin, index - 1, nums, tree->left);
		}

		if (index < end) {
			tree->right = new TreeNode;
			sub(index + 1, end, nums, tree->right);
		}
	}


	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

		if (nums.size() == 0) return nullptr;
		TreeNode* tree = new TreeNode;
		sub(0, nums.size() - 1, nums, tree);

		return tree;
	}
};



////////////////////////////////////////////////////////////////////////////////








/// <summary>
/// 输出容器中的内容
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="t"></param>
template<typename T>
void print(T t) {
	for (typename T::const_iterator it = t.begin(); it != t.end(); ++it) {
		cout << *it << endl;
	}
}



int main() {



	Solution s;

	vector<int> nums = { 1, 2, 3 };
	s.constructMaximumBinaryTree(nums);





	return 0;
}