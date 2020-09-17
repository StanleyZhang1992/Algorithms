#pragma once
/*
67. Add Binary

Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"


Constraints:

Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.
*/
#include<string>

using namespace std;

string addBinary(string a, string b) {
    int p1 = a.size() - 1;
    int p2 = b.size() - 1;
    int carry = 0;
    string res;
    while (p1 >= 0 || p2 >= 0) {
        int cur1 = (p1 >= 0) ? (a[p1] - '0') : 0;
        int cur2 = (p2 >= 0) ? (b[p2] - '0') : 0;
        string curd = to_string(cur1 ^ cur2 ^ carry);
        carry = (cur1 & cur2 || cur1 & carry || cur2 & carry);
        res += curd;
        p1 -= 1;
        p2 -= 1;
    }
    if (carry) {
        res.push_back('1');
    }
    std::reverse(res.begin(), res.end());
    return res;
}