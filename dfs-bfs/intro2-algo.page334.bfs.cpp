
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


private:
	vector<string>* m_vertex;

	vector<vector<int>>* m_adjacent_matrix;

	int m_vertex_num;

public:
	Solution() {

		m_vertex = new vector<string>({ "r", "s", "t", "u", "v", "w", "x", "y" });
		m_vertex_num = m_vertex->size();
		// �����ڽӾ���
		m_adjacent_matrix = new vector<vector<int>>(m_vertex_num, vector<int>(m_vertex_num));


		


	}







};






////////////////////////////////////////////////////////////////////////////////












int main() {


	/*print<vector<int>>({ 1, 2, 3, 4 });*/

	return 0;
}