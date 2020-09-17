#pragma once
/*
415. Add Strings

Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/
#include<string>

using namespace std;

string addStrings(string num1, string num2) {
    int p1 = num1.size() - 1;
    int p2 = num2.size() - 1;
    int carry = 0;
    string res;
    while (p1 >= 0 && p2 >= 0) {
        int cur1 = num1[p1] - '0';
        int cur2 = num2[p2] - '0';
        int curs = carry + cur1 + cur2;
        carry = curs / 10;
        int curd = curs % 10;
        string curc = to_string(curd);
        res += curc;
        p1 -= 1;
        p2 -= 1;
    }
    while (p1 >= 0) {
        int cur1 = num1[p1] - '0';
        int curs = cur1 + carry;
        carry = curs / 10;
        int curd = curs % 10;
        string curc = to_string(curd);
        res += curc;
        p1 -= 1;
    }
    while (p2 >= 0) {
        int cur2 = num2[p2] - '0';
        int curs = cur2 + carry;
        carry = curs / 10;
        int curd = curs % 10;
        string curc = to_string(curd);
        res += curc;
        p2 -= 1;
    }
    if (carry) {
        res.push_back('1');
    }
    std::reverse(res.begin(), res.end());
    return res;
}