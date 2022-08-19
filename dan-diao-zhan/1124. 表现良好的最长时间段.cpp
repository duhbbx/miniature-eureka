
#include <iostream>				// 输入输出
#include <vector>				// 可变长度数组
#include <unordered_map>		// hashmap
#include <stack>				// 栈
#include <string>				// 字符串

using namespace std;



string title = "1124. 表现良好的最长时间段";


////////////////////////////////////////////////////////////////////////////////
/// 这里放OJ的类


class Solution {
public:
	/// <summary>
	/// 1124. 表现良好的最长时间段
	/// 所谓「表现良好的时间段」，意味在这段时间内，「劳累的天数」是严格 大于「不劳累的天数」。
	/// 请你返回「表现良好时间段」的最大长度。
	/// </summary>
	/// <param name="hours"></param>
	/// <returns></returns>
	int longestWPI(vector<int>& hours) {

		int n = hours.size();
		int len = 0;
		if (n == 0) {
			return len;
		}

		vector<int> score(n);
		for (int i = 0; i < n; i++) {
			score[i] = hours[i] > 8 ? 1 : -1;
		}


		// 求前缀和
		vector<int> presum(n + 1, 0);
		for (int i = 1; i < n + 1; i++) {
			presum[i] = presum[i - 1] + score[i - 1];
		}

		// 顺序生成单调栈
		stack<int> s;
		for (int i = 0; i < n + 1; i++) {
			if (s.empty() || presum[s.top()] > presum[i]) {
				s.push(i);
			}
		}

		// 倒序扫描数组，求最大长度
		len = n;
		int ans = 0;
		
		while (len > ans) {
			while (!s.empty() && presum[s.top()] < presum[len]) {
				ans = max(ans, len - s.top());
				s.pop();
			}

			len -= 1;
		}

		return ans;
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


	cout << title << endl;

	print<vector<int>>({ 1, 2, 3, 4 });





	return 0;
}