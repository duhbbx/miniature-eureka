//
// Created by duhbb on 2022/11/5.
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

    bool parseBoolExpr(string expression) {

        stack<char> operandStack;
        stack<char> operatorStack;

        for (int i = 0; i < expression.size(); ++i) {

            char curr = expression[i];
            if (curr == '|' || curr == '&' || curr == '!') {
                operandStack.push(curr);
                operatorStack.push(curr);
            } else if (curr == '(' || curr == ',') {
                continue;
            } else if (curr != ')') {
                operandStack.push(curr);
            } else {
                char currOperator = operatorStack.top();
                operatorStack.pop();
                char operand_1 = operandStack.top();
                operandStack.pop();

                if (currOperator == '!') {
                    operand_1 = (operand_1 == 't') ? 'f' : 't';
                } else {
                    while(operandStack.top() != '&' && operandStack.top() != '|') {
                        char operand_2 = operandStack.top();
                        operandStack.pop();
                        if (currOperator == '&') {
                            operand_1 = (operand_1 == 'f' || operand_2 == 'f') ? 'f' : 't';
                        } else {
                            operand_1 = (operand_1 == 'f' && operand_2 == 'f') ? 'f' : 't';
                        }
                    }
                }
                operandStack.pop();
                operandStack.push(operand_1);
            }
        }

        return operandStack.top() == 't';
    }
};

int main() {


    Solution solution;

//    string expr = "&(|(f))";
    string expr = "|(&(t,f,t),!(t))";

    solution.parseBoolExpr(expr);


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}