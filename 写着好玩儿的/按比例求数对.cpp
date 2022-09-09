
#include <iostream>                // 输入输出
#include <vector>                // 可变长度数组
#include <unordered_map>        // hashmap
#include <stack>                // 栈
#include <string>                // 字符串

using namespace std;

////////////////////////////////////////////////////////////////////////////////
/// 这里放OJ的类

class Pair {
private:
    int m_weight;
    int m_height;

public:
    // 构造函数
    Pair(int weight, int height): m_weight(weight), m_height(height) { }


    /**
     * 主要是 snipaste 这个截图软件可以预设截图的大小, 用C++简单的算一个, 嘿嘿
     */
    void calc() {
        for (int i = 400; i <= 1000; i += 20) {
            double height = 1.0 * i * m_height / m_weight;
            cout << i << " " << ceil(height) << endl;
        }
    }
};
////////////////////////////////////////////////////////////////////////////////


/// <summary>
/// 输出容器中的内容
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


//    print<vector<int>>({ 1, 2, 3, 4 });

    Pair pair(256, 144);

    pair.calc();
    return 0;
}