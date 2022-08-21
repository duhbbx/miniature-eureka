
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



	for (typename T::const_iterator it = t.begin(); it != t.end() - 1; ++it) {
		cout << *it << ", ";
	}

	cout << *(t.end() - 1) << endl;
}




////////////////////////////////////////////////////////////////////////////////
/// 这里放OJ的类

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



		// 循环多少层
		for (int i = 1; i <= max_layer; i++) {

			cout << "======================================" << endl;

			// 计算出第一个点
			x = cStart + i;
			y = rStart + 1 - i;

			int last_x = 0, last_y = 0;

			// 右边
			for (int j = 0; j < 2 * i; ++j) {
				if (inBox(x, y + j, rows, cols)) {
					lay_point.push_back({ y + j, x });
				}
				// 记录当前的最后一个点
				if (j == 2 * i - 1) {
					last_x = x - 1;
					last_y = y + j;
				}
			}

			x = last_x;
			y = last_y;

			// 下边
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


			// 左边

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

			// 上边
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