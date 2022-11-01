//
// Created by tuhooo on 2022/11/1.
//
#include <iostream>              // 输入输出
#include <vector>                // 可变长度数组
#include <unordered_map>         // hashmap
#include <unordered_set>         // 无序集合
#include <stack>                 // 栈
#include <string>                // 字符串
#include <queue>                 // 队列
#include <climits>               // 极限值
#include <algorithm>             // 算法相关的
#include <set>                   // 集合
#include "../0000 API 模板 类/TreeNode.h"
#include "../0000 API 模板 类/ListNode.h"
#include <numeric>
#include <map>
#include <cstring>


using namespace std;


class Solution {
public:

    /**
     * 获取字符数组word在pieceIndex和pieceCharIndex处的字符
     * 如果没有或者为"", 则pieceCharIndex延到下一个, 如果pieceCharIndex超过了word[pieceIndex]
     * 则pieceIndex延到对应的下一个
     * @param word 字符数组
     * @param pieceIndex 字符片段的索引
     * @param pieceCharIndex 字符在字符片段中的位置
     * @param c 读到的字符
     * @return 是否能读到字符
     */
    bool getNext(vector<string> &word, int &pieceIndex, int &pieceCharIndex, char &c) {

        while (pieceIndex < word.size()) {
            while (pieceCharIndex < word[pieceIndex].size()) {
                c = word[pieceIndex][pieceCharIndex];
                ++pieceCharIndex;
                return true;
            }
            ++pieceIndex;
            pieceCharIndex = 0;
        }
        return false;
    }


    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2) {

        int p1 = 0, p1_c_idx1 = 0, p2 = 0, p2_c_idx2 = 0;
        char c1, c2;

        while (true) {

            bool end1 = getNext(word1, p1, p1_c_idx1, c1);
            bool end2 = getNext(word2, p2, p2_c_idx2, c2);

            if (end1 != end2 || c1 != c2) {
                return false;
            }

            if (!end1) {
                return true;
            }

        }
    }
};


int main() {


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}