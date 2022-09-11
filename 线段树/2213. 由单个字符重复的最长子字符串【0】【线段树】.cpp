//
// Created by duhbb on 2022/9/11.
//


#include <iostream>              // 输入输出
#include <vector>                // 可变长度数组
#include <unordered_map>         // hashmap
#include <stack>                 // 栈
#include <string>                // 字符串
#include <queue>                 // 队列
#include <climits>               // 极限值
#include <algorithm>             // 算法相关的
#include "../0000 API 模板 类/TreeNode.h"
#include "../0000 API 模板 类/ListNode.h"

using namespace std;




template<typename T>
void print(T t) {


    if (t.empty()) {
        cout << "容器为空............" << endl;
        return;
    }


    for (typename T::const_iterator it = t.begin(); it != t.end() - 1; ++it) {
        cout << *it << ", ";
    }

    cout << *(t.end() - 1) << endl;
}



////////////////////////////////////////////////////////////////////////////////
/// 这里放OJ的类


/*
 *
 * 题目描述
评论 (41)
题解 (78)
提交记录
2213. 由单个字符重复的最长子字符串
给你一个下标从 0 开始的字符串 s 。另给你一个下标从 0 开始、长度为 k 的字符串 queryCharacters ，一个下标从 0 开始、长度也是 k 的整数 下标 数组 queryIndices ，这两个都用来描述 k 个查询。

第 i 个查询会将 s 中位于下标 queryIndices[i] 的字符更新为 queryCharacters[i] 。

返回一个长度为 k 的数组 lengths ，其中 lengths[i] 是在执行第 i 个查询 之后 s 中仅由 单个字符重复 组成的 最长子字符串 的 长度 。

 https://leetcode.cn/problems/longest-substring-of-one-repeating-character/
 *
 */



class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {

        unordered_map<char, vector<vector<int>>> charPositionMap;

        unordered_map<char, int> maxRepeatCharLength;


        int stringSize = s.length();

        int start = 0;
        int end = 1;


        while(end < s.length()) {
            if (s[end] != s[start]) {
                auto iter = charPositionMap.find(s[start]);
                if (iter != charPositionMap.end()) {
                    iter->second.push_back({start, end - 1});
                    if (end - start > maxRepeatCharLength[s[start]]) {
                        maxRepeatCharLength[s[start]] = end - start;
                    }
                } else {
                    charPositionMap.insert(pair<char, vector<vector<int>>>(s[start], {{start, end - 1}}));
                    maxRepeatCharLength[s[start]] = end - start;
                }

                start = end;
            }
            ++end;
        }

        if (end == s.length()) {
            auto iter = charPositionMap.find(s[start]);
            if (iter != charPositionMap.end()) {
                // 将新的值推入
                iter->second.push_back({start, end - 1});

                if (end - start > maxRepeatCharLength[s[start]]) {
                    maxRepeatCharLength[s[start]] = end - start;
                }

            } else {
                charPositionMap.insert(pair<char, vector<vector<int>>>(s[start], {{start, end - 1}}));

                maxRepeatCharLength[s[start]] = end - start;
            }
        }



        return {};
    }

    int maxRepeatString(string& s, int index, char c, unordered_map<char, vector<vector<int>>>& charPositionMap, unordered_map<char, int>& maxRepeatCharLength) {

        char old = s[index];

        for (int i = 0; i < charPositionMap[old].size(); i++) {
            if (charPositionMap[old][i][0] <= index && index <= charPositionMap[old][i][1]) {
                if (charPositionMap[old][i][0] < index) {
                    charPositionMap[old].insert(charPositionMap[old].begin() + i, {charPositionMap[old][i][0], index-1});
                }

                if (index < charPositionMap[old][i][1]) {
                    charPositionMap[old].insert(charPositionMap[old].begin() + i, {index+1, charPositionMap[old][i][0]});
                }
                charPositionMap[old].erase(charPositionMap[old].begin() + i);
                break;
            }
        }

        int maxCharRepeatLength = 0;
        for (int i = 0; i < charPositionMap[old].size(); i++) {
            maxCharRepeatLength = max(0, charPositionMap[old][i][1] - charPositionMap[old][i][0] + 1);
        }
        maxRepeatCharLength[old] = maxCharRepeatLength;


        char newChar = c;

        auto& newCharVector = charPositionMap[newChar];

        for (int i = 0; i < newCharVector.size(); i++) {

        }






        return 0;
    }
};


////////////////////////////////////////////////////////////////////////////////




void printCurrentFileName() {
    string file = __FILE__;
    int pos = file.find_last_of("/");
    string fileName = pos == -1 ? file : file.substr(pos+1);
    cout << "【当前题目为：" << fileName << "】" << endl;
}





int main() {


    printCurrentFileName();


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}