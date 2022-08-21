
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


class Solution {


private:
	vector<string>* m_vertex;

	vector<vector<int>>* m_adjacent_matrix;

	int m_vertex_num;

public:
	Solution() {

		m_vertex = new vector<string>({ "r", "s", "t", "u", "v", "w", "x", "y" });
		m_vertex_num = m_vertex->size();
		// 定义邻接矩阵
		m_adjacent_matrix = new vector<vector<int>>(m_vertex_num, vector<int>(m_vertex_num));


		


	}







};






////////////////////////////////////////////////////////////////////////////////












int main() {


	/*print<vector<int>>({ 1, 2, 3, 4 });*/

	return 0;
}