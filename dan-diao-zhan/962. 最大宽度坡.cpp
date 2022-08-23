
#include <iostream>                // 输入输出
#include <vector>                // 可变长度数组
#include <unordered_map>        // hashmap
#include <stack>                // 栈
#include <string>                // 字符串

using namespace std;




////////////////////////////////////////////////////////////////////////////////
/// 这里放OJ的类


/// <summary>
/// 这题把我卡的死死的，我以为刷了一个单调栈的，就可以了，结果这个愣是把我钉死了
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

        // 将索引 0 推入到栈中
        s.push(0);    // push 0 是几个意思?

        // 以索引 0 开始生成一个严格单调的栈
        for (int i = 1; i < n; i++) {
            if (nums[s.top()] > nums[i]) {
                s.push(i);
            }
        }

        // 倒着回来再来一次
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


    print<vector<int>>({ 1, 2, 3, 4, 5});





    return 0;
}