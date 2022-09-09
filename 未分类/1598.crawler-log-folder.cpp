#include <iostream>              // �������
#include <vector>                // �ɱ䳤������
#include <unordered_map>         // hashmap
#include <stack>                 // ջ
#include <string>                // �ַ���
#include <queue>                 // ����
#include <climits>               // ����ֵ
#include <algorithm>             // �㷨��ص�

using namespace std;



/// <summary>
/// ��������е�����
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="t"></param>
template<typename T>
void print(T t) {


    if (!t.empty()) {
        cout << "����Ϊ��............" << endl;
        return;
    }


    for (typename T::const_iterator it = t.begin(); it != t.end() - 1; ++it) {
        cout << *it << ", ";
    }

    cout << *(t.end() - 1) << endl;
}



////////////////////////////////////////////////////////////////////////////////
/// �����OJ����


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

    cout << "��Ŀ: 1598. �ļ��в�����־�Ѽ���" << endl;

    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}