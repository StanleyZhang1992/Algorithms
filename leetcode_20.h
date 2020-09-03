#pragma once

/*
20. Valid Parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.


Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
Example 4:

Input: s = "([)]"
Output: false
Example 5:

Input: s = "{[]}"
Output: true


Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

#include<stack>
#include<string>
#include<unordered_map>

using namespace std;

/*
Use stack to store the left parts
Use hashtable to store the mapping relation
time complexity is O(n) since there's only one pass
*/
bool isValid(string s) {
    // egde case
    if (s.size() == 0) {
        return true;
    }
    // main logic
    stack<char> leftPars;
    unordered_map<char, char> lookup{
        {'}', '{'},
        {']', '['},
        {')', '('}
    };

    int sSize = s.size();
    for (int i = 0; i < sSize; ++i) {
        char curPar = s[i];
        if (lookup.count(curPar)) {
            if (leftPars.empty()) {
                return false;
            }
            char topChar = leftPars.top();
            if (lookup[curPar] == topChar) {
                leftPars.pop();
            }
            else {
                return false;
            }
        }
        else {
            leftPars.push(curPar);
        }
    }

    return leftPars.size() == 0 ? true : false;
}