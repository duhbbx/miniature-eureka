
#include <iostream>                // �������
#include <vector>                // �ɱ䳤������
#include <unordered_map>        // hashmap
#include <stack>                // ջ
#include <string>                // �ַ���

using namespace std;




////////////////////////////////////////////////////////////////////////////////
/// �����OJ����


/// <summary>
/// ������ҿ��������ģ�����Ϊˢ��һ������ջ�ģ��Ϳ����ˣ���������ǰ��Ҷ�����
/// </summary>
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {

        stack<int> s;
        int n = nums.size();
        int len = 0;

        if (n == 0) {
            return 0;
        }

        // ������ 0 ���뵽ջ��
        s.push(0);    // push 0 �Ǽ�����˼?

        // ������ 0 ��ʼ����һ���ϸ񵥵���ջ
        for (int i = 1; i < n; i++) {
            if (nums[s.top()] > nums[i]) {
                s.push(i);
            }
        }

        // ���Ż�������һ��
        for (int i = n - 1; i > 0; i--) {
            while (!s.empty() && nums[s.top()] <= nums[i]) {
                len = max(len, i - s.top());
                s.pop();
            }

            if (s.empty()) {
                return len;
            }
        }

        return len;
    }
};



////////////////////////////////////////////////////////////////////////////////







/// <summary>
/// ��������е�����
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


    print<vector<int>>({ 1, 2, 3, 4, 5});





    return 0;
}