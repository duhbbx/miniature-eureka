
#include <iostream>				// �������
#include <vector>				// �ɱ䳤������
#include <unordered_map>		// hashmap
#include <stack>				// ջ
#include <string>				// �ַ���

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
	vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
		int max_row_layer = (rStart - 0) > (rows - rStart) ? (rStart - 0) > (rows - rStart);
		int max_col_layer = (cStart - 0) > (cols - cStart) ? (cStart - 0) : (cols - cStart);
		int max_layer = max_row_layer > max_col_layer ? max_row_layer : max_col_layer;




		for (int i = 0; i < max_layer; i++) {
			
		}
	}
};



////////////////////////////////////////////////////////////////////////////////

int main() {


	print<vector<int>>({ 1, 2, 3, 4 });





	return 0;
}