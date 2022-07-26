
#include <iostream>                // 输入输出
#include <vector>                // 可变长度数组
#include <unordered_map>        // hashmap
#include <stack>                // 栈
#include <string>                // 字符串
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
public:
    int isPrefixOfWord(string sentence, string searchWord) {

        int i = 0;
        int num = 0;
        while (true) {
            // 找到第一个非空格的字符
            while (sentence[i] == ' ' && i < sentence.length()) i++;
            // 判断是否没有找到
            if (i >= sentence.length() - 1) return -1;

            num++;
            int flag = 1;
            for (int j = 0; j < searchWord.length(); j++) {

                if (i + j > sentence.length()) return -1;

                if (searchWord[j] != sentence[i+j]) {
                    while (sentence[i] != ' ' && i < sentence.length()) i++;
                    flag = 0;
                    break;
                }
            }

            if (flag == 1) return num;
        }
    }
};


////////////////////////////////////////////////////////////////////////////////


int main() {


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    Solution s;

    cout << s.isPrefixOfWord("i am tired", "you") << endl;

    return 0;
}