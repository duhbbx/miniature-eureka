#include <iostream>              // 输入输出
#include <vector>                // 可变长度数组
#include <unordered_map>         // hashmap
#include <stack>                 // 栈
#include <string>                // 字符串
#include <queue>                 // 队列
#include <climits>               // 极限值
#include <algorithm>             // 算法相关的

using namespace std;



/// <summary>
/// 输出容器中的内容
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="t"></param>
template<typename T>
void print(T t) {


    if (!t.empty()) {
        cout << "容器为空............" << endl;
        return;
    }


    for (typename T::const_iterator it = t.begin(); it != t.end() - 1; ++it) {
        cout << *it << ", ";
    }

    cout << *(t.end() - 1) << endl;
}



////////////////////////////////////////////////////////////////////////////////
/// 这里放OJ的类


class Solution {
public:
    int minOperations(vector<string>& logs) {

        int res = 0;
        for (int i = 0; i < logs.size(); i++) {

            if (logs[i][1] == '.') {
                if (res) {
                    --res;
                }
            }
            else if (logs[i][0] != '.') {
                res++;
            }
        }

        return res;
    }
};



////////////////////////////////////////////////////////////////////////////////












int main() {

    cout << "题目: 1598. 文件夹操作日志搜集器" << endl;

    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}