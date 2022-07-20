#include <iostream>
#include <string>

using namespace std;


/*
1781. 所有子字符串美丽值之和
一个字符串的 美丽值 定义为：出现频率最高字符与出现频率最低字符的出现次数之差。

比方说，"abaacc" 的美丽值为 3 - 1 = 2 。
给你一个字符串 s ，请你返回它所有子字符串的 美丽值 之和。

示例 1：

输入：s = "aabcb"
输出：5
解释：美丽值不为零的字符串包括 ["aab","aabc","aabcb","abcb","bcb"] ，每一个字符串的美丽值都为 1 。
示例 2：

输入：s = "aabcbaa"
输出：17


提示：
1 <= s.length <= 500
s 只包含小写英文字母。
 */

class Solution {
public:
    int beautySum(string s) {
        unsigned long length = s.length();
        int answer = 0;

        if (length <= 2) return answer; // 如果字符串长度不大于2，则美丽值一定为0

        for (int i = 0; i < length; ++i) {

            int max = 1, min = 1;
            char minFreqChar = s[i];
            int charFreq[26] = {0};     // 记录字母的频次
            charFreq[s[i] - 'a']++;     // s[i] 字符的频次

            for (int j = i + 1; j < length; ++j) {  // s[i..j] 子字符串

                // ========================== 滑动窗口 ==========================

                int freqIndex = s[j] - 'a';         // 计算 s[j] 这个字符的位置
                charFreq[freqIndex]++;              // 更新它的频次
                if (charFreq[freqIndex] == 1) {
                    min = 1;
                    minFreqChar = s[j];
                    answer += max - min;
                    continue;
                }

                if (s[j] == minFreqChar) { // 更新最小频次的字符
                    min++;
                    for (char k = 0; k < 26; ++k) {
                        if (charFreq[k] > 0 && charFreq[k] < min) {
                            min = charFreq[k];
                            minFreqChar = (char) ('a' + k);
                            break;
                        }
                    }
                }

                if (charFreq[freqIndex] > max) { // 更新最大频次的字符
                    max = charFreq[freqIndex];
                }

                answer += max - min;

                // ========================== 滑动窗口 ==========================
            }
        }

        return answer;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
