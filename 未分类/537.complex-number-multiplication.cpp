


#include <iostream>                // 输入输出
#include <vector>                // 可变长度数组
#include <unordered_map>        // hashmap
#include <stack>                // 栈
#include <string>                // 字符串

using namespace std;




////////////////////////////////////////////////////////////////////////////////
/// 这里放OJ的类


class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {

        int x1 = 0, y1 = 0, x2 = 0, y2 = 0; // 两个复数的实部和虚部

        int p = num1.length() - 2;

        int base = 1;
        while (p > -1) {
            if (num1[p] == '-') {
                y1 = -y1;
                p -= 2;
                break;
            } else if (num1[p] == '+') {
                --p;
                break;
            } else {
                y1 += base * (num1[p] - '0');
                base *= 10;
                --p;
            }
        }



        base = 1;
        while (p > -1) {
            if (num1[p] == '-') {
                x1 = -x1;
                break;
            } else {
                x1 += base * (num1[p] - '0');
                base *= 10;
                --p;
            }
        }


        p = num2.length() - 2;

        base = 1;
        while (p > -1) {
            if (num2[p] == '-') {
                y2 = -y2;
                p -= 2;
                break;
            } else if (num2[p] == '+') {
                --p;
                break;
            } else {
                y2 += base * (num2[p] - '0');
                base *= 10;
                --p;
            }
        }

        base = 1;
        while (p > -1) {
            if (num2[p] == '-') {
                x2 = -x2;
                break;
            } else {
                x2 += base * (num2[p] - '0');
                base *= 10;
                --p;
            }
        }

        cout << "x1 = " << x1 << ", y1 = " << y1 << " || x2 = " << x2 << ", y2 = " << y2 << endl;


        int x = x1 * x2 - y1 * y2;
        int y = (x1 * y2 + x2 * y1);

        std::string res = "" + to_string(x) + "+" + to_string(y) + "i";

        return res;

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


    print<vector<int>>({ 1, 2, 3, 4 });



    Solution s;
    std::string res = s.complexNumberMultiply("1+2i", "1+-2i");



    cout << "res = " << res;



    return 0;
}