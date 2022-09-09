
#include <iostream>                // 输入输出
#include <vector>                // 可变长度数组
#include <unordered_map>        // hashmap
#include <stack>                // 栈
#include <string>                // 字符串

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



class MovingAverage {
public:
    /** Initialize your data structure here. */

    MovingAverage(int size) {
        m_window_size = size;
        m_sum = 0;
        m_seq = 0;
        m_array = new int[size];
        for (int i = 0; i < size; i++) m_array[i] = 0;
    }

    double next(int val) {
        int index = (m_seq) % m_window_size;
        m_seq++;
        m_sum = m_sum - m_array[index] + val;
        m_array[index] = val;

        return 1.0 * m_sum / ((m_seq >= m_window_size) ? m_window_size : m_seq);
    }

private:
    int* m_array;
    int m_sum;
    int m_seq;
    int m_window_size;

};


////////////////////////////////////////////////////////////////////////////////












int main() {


    print<vector<int>>({ 1, 2, 3, 4 });





    return 0;
}