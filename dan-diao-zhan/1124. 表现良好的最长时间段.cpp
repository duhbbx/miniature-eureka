
#include <iostream>				// �������
#include <vector>				// �ɱ䳤������
#include <unordered_map>		// hashmap
#include <stack>				// ջ
#include <string>				// �ַ���

using namespace std;



string title = "1124. �������õ��ʱ���";


////////////////////////////////////////////////////////////////////////////////
/// �����OJ����


class Solution {
public:
	/// <summary>
	/// 1124. �������õ��ʱ���
	/// ��ν���������õ�ʱ��Ρ�����ζ�����ʱ���ڣ������۵����������ϸ� ���ڡ������۵���������
	/// ���㷵�ء���������ʱ��Ρ�����󳤶ȡ�
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


		// ��ǰ׺��
		vector<int> presum(n + 1, 0);
		for (int i = 1; i < n + 1; i++) {
			presum[i] = presum[i - 1] + score[i - 1];
		}

		// ˳�����ɵ���ջ
		stack<int> s;
		for (int i = 0; i < n + 1; i++) {
			if (s.empty() || presum[s.top()] > presum[i]) {
				s.push(i);
			}
		}

		// ����ɨ�����飬����󳤶�
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
/// ��������е�����
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