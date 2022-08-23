
#include <iostream>                // 输入输出
#include <vector>                // 可变长度数组
#include <unordered_map>        // hashmap
#include <stack>                // 栈
#include <string>                // 字符串
#include <algorithm>

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

    // 打印最后一个数据
    cout << *(t.end() - 1) << endl;
}


////////////////////////////////////////////////////////////////////////////////
/// 这里放OJ的类

/*

给定一个 24 小时制（小时:分钟 "HH:MM"）的时间列表，找出列表中任意两个时间的最小时间差并以分钟数表示。

 

示例 1：

输入：timePoints = ["23:59","00:00"]
输出：1
示例 2：

输入：timePoints = ["00:00","23:59","00:00"]
输出：0


*/

class Solution {
public:

    int get(string& s) {
        return 60 * ((s[0] - '0') * 10 + (s[1] - '0')) + 10 * (s[3] - '0') + (s[4] - '0');
    }

    int findMinDifference(vector<string>& timePoints) {
        if (timePoints.size() > 1440) return 0;


        if (timePoints.size() < 2) return 0;

        vector<int> list(timePoints.size(), 0);

        for (int i = 0; i < timePoints.size(); i++) {
            list[i] = get(timePoints[i]);
        }

        sort(list.begin(), list.end());

        int interval = list[1] - list[0];
        for (int i = 1; i < list.size(); ++i) {
            int tmp = list[i] - list[i - 1];
            if (tmp < interval) interval = tmp;
        }

        int inverse = 24 * 60 - list.back() + list.front();
        if (interval > inverse) interval = inverse;
        // print<vector<int>>(list);

        return interval;
    }
};


////////////////////////////////////////////////////////////////////////////////










int main() {


    print<vector<int>>({ 1, 2, 3, 4 });



    Solution s;

    vector<string> timePoints = { "23:59", "00:01" };

    

    cout << s.findMinDifference(timePoints) << endl;

    return 0;
}