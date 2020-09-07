#pragma once
/*
227. Basic Calculator II

Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

Example 1:

Input: "3+2*2"
Output: 7
Example 2:

Input: " 3/2 "
Output: 1
Example 3:

Input: " 3+5 / 2 "
Output: 5
Note:

You may assume that the given expression is always valid.
Do not use the eval built-in library function.
*/
#include<string>
#include<stack>

using namespace std;

/*
use a stack to store the previous number and sign
*/
int calculate(string s) {
    stack<int> stk;
    char sign = '+';
    int sSize = s.size();
    int num = 0;
    for (int i = 0; i < sSize; ++i) {
        char c = s[i];
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        }
        if (c != ' ' && !isdigit(c) || i == sSize - 1) {
            if (sign == '+') {
                stk.push(num);
            }
            else if (sign == '-') {
                stk.push(-num);
            }
            else if (sign == '*') {
                int cur = stk.top();
                stk.pop();
                stk.push(cur * num);
            }
            else if (sign == '/') {
                int cur = stk.top();
                stk.pop();
                stk.push(cur / num);
            }
            sign = c;
            num = 0;
        }
    }

    int res = 0;
    while (!stk.empty()) {
        res += stk.top();
        stk.pop();
    }
    return res;
}