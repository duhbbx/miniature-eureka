
#include <iostream>				// �������
#include <vector>				// �ɱ䳤������
#include <unordered_map>		// hashmap
#include <stack>				// ջ
#include <string>				// �ַ���
#include <queue>                // ����

using namespace std;



/// <summary>
/// ��������е�����
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
/// �����OJ����


class Solution {
public:
	int isPrefixOfWord(string sentence, string searchWord) {

		int i = 0;
		int num = 0;
		while (true) {
			// �ҵ���һ���ǿո���ַ�
			while (sentence[i] == ' ' && i < sentence.length()) i++;
			// �ж��Ƿ�û���ҵ�
			if (i >= sentence.length() - 1) return -1;

			num++;
			int flag = 1;
			for (int j = 0; j < searchWord.length(); j++) {

				if (i + j > sentence.length()) return -1;

				if (searchWord[j] != sentence[i+j]) {
					while (sentence[i] != ' ' && i < sentence.length()) i++;
					flag = 0;
					break;
				}
			}

			if (flag == 1) return num;
		}
	}
};


////////////////////////////////////////////////////////////////////////////////


int main() {


	/*print<vector<int>>({ 1, 2, 3, 4 });*/

	Solution s;

	cout << s.isPrefixOfWord("i am tired", "you") << endl;

	return 0;
}