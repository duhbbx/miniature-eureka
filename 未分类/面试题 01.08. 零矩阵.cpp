#include <iostream>              // 输入输出
#include <vector>                // 可变长度数组
#include <unordered_map>         // hashmap
#include <unordered_set>         // 无序集合
#include <stack>                 // 栈
#include <string>                // 字符串
#include <queue>                 // 队列
#include <climits>               // 极限值
#include <algorithm>             // 算法相关的
#include <set>                   // 集合
#include "../0000 API 模板 类/TreeNode.h"
#include "../0000 API 模板 类/ListNode.h"


using namespace std;


template<typename T>
void print(T t) {


    if (t.empty()) {
        cout << "容器为空............" << endl;
        return;
    }


    for (typename T::const_iterator it = t.begin(); it != t.end() - 1; ++it) {
        cout << *it << ", ";
    }

    cout << *(t.end() - 1) << endl;
}

void printCurrentFileName() {
    string file = __FILE__;
    int pos = file.find_last_of("/");
    string fileName = pos == -1 ? file : file.substr(pos + 1);
    cout << "\n【当前题目为：" << fileName << "】" << endl;
}




////////////////////////////////////////////////////////////////////////////////
/// 这里放OJ的类

class Solution {
public:



    inline void setRowZero(vector<vector<int>> &matrix, int row) {
        for (int i = 0; i < matrix[0].size(); ++i) {
            // matrix[row][i] = 0;
            std::fill(matrix[row].begin(), matrix[row].end(),0);
        }
    }

    inline void setColZero(vector<vector<int>> &matrix, int col) {
        for (int i = 0; i < matrix.size(); ++i) {
            matrix[i][col] = 0;
        }
    }

    void setZeroes(vector<vector<int>> &matrix) {

        // 提示，不必开辟两个数组，可以使用matrix的空间，实现 o(1)

        vector<int> row(matrix.size(), 0);
        vector<int> col(matrix[0].size(), 0);

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == 0) {
                    if (row[i] == 0) {
                        row[i] = 1;
                    }

                    if (col[j] == 0) {
                        col[j] = 1;
                    }

                }

            }
        }

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {

                if (row[i] == 1) {
                    setRowZero(matrix, i);

                    row[i] = 0;
                }

                if (col[j] == 1) {
                    setColZero(matrix, j);
                    col[j] = 0;

                }

            }
        }
    }
};

////////////////////////////////////////////////////////////////////////////////

int main() {


    printCurrentFileName();


    Solution solution;


    vector<vector<int>> mat = {{1,1,1},{1,0,1},{1,1,1}};

    solution.setZeroes(mat);


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}