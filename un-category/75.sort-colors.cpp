
#include <iostream>				// 输入输出
#include <vector>				// 可变长度数组
#include <unordered_map>		// hashmap
#include <stack>				// 栈
#include <string>				// 字符串

using namespace std;


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



////////////////////////////////////////////////////////////////////////////////
/// 这里放OJ的类

/*
给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地对它们进行排序，

使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

必须在不使用库的sort函数的情况下解决这个问题。


示例 1：

输入：nums = [2, 0, 2, 1, 1, 0]
输出：[0, 0, 1, 1, 2, 2]
示例 2：

输入：nums = [2, 0, 1]
输出：[0, 1, 2]

*/



/*

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

*/

/*



class Solution {
public:
	void sortColors(vector<int>& nums) {
		int n = nums.size();
		int p0 = 0, p1 = 0;
		for (int i = 0; i < n; ++i) {
			if (nums[i] == 1) {
				swap(nums[i], nums[p1]);
				++p1;
			}
			else if (nums[i] == 0) {
				swap(nums[i], nums[p0]);
				if (p0 < p1) {
					swap(nums[i], nums[p1]);
				}
				++p0;
				++p1;
			}

			print(nums);
		}
	}
};

*/


class Solution {
public:
	void partition(vector<int>& nums) {
		int n = nums.size();
		int p0 = 0, p1 = n - 1;
		int s = 0;
		while (p0 < p1) {
			while (nums[p1] > nums[s])
				--p1;

			if (p1 != s) {
				swap(nums[s], nums[p1]);
				s = p1;
				--p1;
			}

			while (nums[p0] < nums[s]) {
				++p0;
			}

			if (p0 != s) {
				swap(nums[s], nums[p0]);
				s = p0;
				++p0;
			}

			print(nums);
		}
	}
};

////////////////////////////////////////////////////////////////////////////////












int main() {

	vector<int> nums = { 3, 1, 1, 2, 3, 4, 2, 5, 6, 8, 1 };
	Solution s;
	s.partition(nums);

	print(nums);

	return 0;
}