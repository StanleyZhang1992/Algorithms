#pragma once
/*
1012. Numbers With Repeated Digits

Given a positive integer N, return the number of positive integers less than or equal to N that have at least 1 repeated digit.

Example 1:

Input: 20
Output: 1
Explanation: The only positive number (<= 20) with at least 1 repeated digit is 11.
Example 2:

Input: 100
Output: 10
Explanation: The positive numbers (<= 100) with atleast 1 repeated digit are 11, 22, 33, 44, 55, 66, 77, 88, 99, and 100.
Example 3:

Input: 1000
Output: 262


Note:

1 <= N <= 10^9
*/
#include<vector>

using namespace std;

int A(int i, int j) {
    return f(i) / f(i - j);
}

int f(int i) {
    if (i == 0 || i == 1) {
        return 1;
    }
    return i * f(i - 1);
}

int numDupDigitsAtMostN(int N) {
    int Ncopy = N;
    int len = 0;
    vector<int> digits;
    while (N > 0) {
        len += 1;
        digits.push_back(N % 10);
        N /= 10;
    }

    int total = 0;
    // case 1
    for (int i = 0; i <= len - 2; ++i) {
        total += 9 * A(9, i);
    }

    // case 2
    vector<int> used(10, 0);
    for (int i = len - 1; i >= 0; --i) {
        int curDigit = digits[i];
        for (int j = (i == len - 1) ? 1 : 0; j < curDigit; ++j) {
            if (used[j] > 0) {
                continue;
            }
            else {
                total += A(10 - (len - i), i);
            }
        }
        used[curDigit] += 1;

        if (used[curDigit] > 1) {
            break;
        }
        if (i == 0) {
            total += 1;
        }
    }

    return Ncopy - total;
}