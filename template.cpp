
#include <iostream>				// 输入输出
#include <vector>				// 可变长度数组
#include <unordered_map>		// hashmap
#include <stack>				// 栈
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



////////////////////////////////////////////////////////////////////////////////
/// 这里放OJ的类



/*




*/


class Solution {
public:
	int minimumCost(vector<int>& cost) {

		// 从大到小排序
		std::sort(cost.begin(), cost.end(), [](int v1, int v2) {
			return v1 > v2;
			});

		int num = cost.size();
		int sum = 0;

		for (int i = 0; i < num; i++) {
			if (i % 3 < 2) sum += cost[i];
		}

		return sum;
	}
};



////////////////////////////////////////////////////////////////////////////////












int main() {


	/*print<vector<int>>({ 1, 2, 3, 4 });*/

	return 0;
}