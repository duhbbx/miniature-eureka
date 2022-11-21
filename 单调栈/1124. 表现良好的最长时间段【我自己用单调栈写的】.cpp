
#include <iostream>                // 输入输出
#include <vector>                // 可变长度数组
#include <unordered_map>        // hashmap
#include <stack>                // 栈
#include <string>                // 字符串

using namespace std;



string title = "1124. 表现良好的最长时间段";


////////////////////////////////////////////////////////////////////////////////
/// 这里放OJ的类


class Solution {
public:

    int longestWPI(vector<int>& hours) {
        int n = hours.size();

        vector<int> prefixSum(n + 1);

        for (int i = 0; i < n; ++i) {
            prefixSum[i+1] = prefixSum[i] + (hours[i] > 8 ? 1 : -1);
        }

        stack<int> stack1;

        for (int i = 0; i <= n; ++i) {
            if (stack1.empty() || prefixSum[i] < prefixSum[stack1.top()]) {
                stack1.push(i);
            }
        }

        int res = 0;

        for (int j = n; j >= 0; --j) {
            while(!stack1.empty() && prefixSum[stack1.top()] < prefixSum[j]) {

                res = max(j - stack1.top(), res);
                stack1.pop();

            }

            if (stack1.empty()) {
                break;
            }
        }

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

    Solution solution;

    vector<int> nums = {6, 6, 9};
    solution.longestWPI(nums);





    return 0;
}