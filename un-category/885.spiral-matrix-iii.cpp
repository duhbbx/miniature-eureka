
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

	inline bool inBox(int x, int y, int row, int col) {

		bool res = 0 <= x && x <= col - 1 && 0 <= y && y <= row - 1;
		
		/*
		std::cout << "x = " << x << ", y = " << y << ", row = " << row << ", col = " << col;
		
		if (res) {
			cout << "    IN  " << endl;
		}
		else {
			cout << endl;
		}

		*/
		return res;
	}

	vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
		int max_row_layer = (rStart - 0) > (rows - rStart) ? (rStart - 0) : (rows - rStart);
		int max_col_layer = (cStart - 0) > (cols - cStart) ? (cStart - 0) : (cols - cStart);
		int max_layer = max_row_layer > max_col_layer ? max_row_layer : max_col_layer;

		vector<vector<int>> lay_point;

		lay_point.push_back({ rStart, cStart });


		int x = 0;
		int y = 0;



		// ѭ�����ٲ�
		for (int i = 1; i <= max_layer; i++) {

			cout << "======================================" << endl;

			// �������һ����
			x = cStart + i;
			y = rStart + 1 - i;

			int last_x = 0, last_y = 0;

			// �ұ�
			for (int j = 0; j < 2 * i; ++j) {
				if (inBox(x, y + j, rows, cols)) {
					lay_point.push_back({ y + j, x });
				}
				// ��¼��ǰ�����һ����
				if (j == 2 * i - 1) {
					last_x = x - 1;
					last_y = y + j;
				}
			}

			x = last_x;
			y = last_y;

			// �±�
			for (int j = 0; j < 2 * i; ++j) {
				if (inBox(x - j, y, rows, cols)) {
					lay_point.push_back({ y, x - j });
				}
				if (j == 2 * i - 1) {
					last_x = x - j;
					last_y = y - 1;
				}
			}

			x = last_x;
			y = last_y;


			// ���

			for (int j = 0; j < 2 * i; ++j) {
				if (inBox(x, y - j, rows, cols)) {
					lay_point.push_back({ y - j,x, });
				}
				if (j == 2 * i - 1) {
					last_x = x + 1;
					last_y = y - j;
				}
			}

			x = last_x;
			y = last_y;

			// �ϱ�
			for (int j = 0; j < 2 * i; ++j) {
				if (inBox(x + j, y, rows, cols)) {
					lay_point.push_back({ y, x + j, });
				}
				if (j == 2 * i - 1) {
					last_x = x + j;
					last_y = y + 1;
				}
			}
		}

		return lay_point;
	}
};



////////////////////////////////////////////////////////////////////////////////

int main() {


	Solution s;

	s.spiralMatrixIII(1, 4, 0, 0);





	return 0;
}