
#include <iostream>				// �������
#include <vector>				// �ɱ䳤������
#include <unordered_map>		// hashmap
#include <stack>				// ջ
#include <string>				// �ַ���

using namespace std;




////////////////////////////////////////////////////////////////////////////////
/// �����OJ����




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


	print<vector<int>>({ 1, 2, 3, 4 });





	return 0;
}