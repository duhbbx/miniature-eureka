
#include <iostream>                // �������
#include <vector>                // �ɱ䳤������
#include <unordered_map>        // hashmap
#include <stack>                // ջ
#include <string>                // �ַ���

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