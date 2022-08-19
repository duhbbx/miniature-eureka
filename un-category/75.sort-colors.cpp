
#include <iostream>				// 输入输出
#include <vector>				// 可变长度数组
#include <unordered_map>		// hashmap
#include <stack>				// 栈
#include <string>				// 字符串

using namespace std;




////////////////////////////////////////////////////////////////////////////////
/// 这里放OJ的类

/*
给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

必须在不使用库的sort函数的情况下解决这个问题。



示例 1：

输入：nums = [2, 0, 2, 1, 1, 0]
输出：[0, 0, 1, 1, 2, 2]
示例 2：

输入：nums = [2, 0, 1]
输出：[0, 1, 2]

*/





class Solution {
public:
	void sortColors(vector<int>& nums) {

		// [2 1 2 0 1 0]

		if (nums.size() == 0 || nums.size() == 1) return;

		// 既然你状态有限，那我直接对状态进行计数不就可以了，哈哈
		int counter[] = { 0, 0, 0 };

		for (auto i : nums) {
			if (i == 0)
				counter[0]++;
			else if (i == 1)
				counter[1]++;
			else
				counter[2]++;
		}

		int begin = 0;
		int end = 0;
		for (int i = 0; i < 3; i++) {
			end = begin + counter[i];

			for (int j = begin; j < end; j++)
				nums[j] = i;

			begin = end;
		}
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
		cout << *it << ", ";
	}

	cout << endl;
}



int main() {

	vector<int> nums = { 2, 1, 2, 0, 1, 0 };
	Solution s;
	s.sortColors(nums);

	print(nums);

	return 0;
}