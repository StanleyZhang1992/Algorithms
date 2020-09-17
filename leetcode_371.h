#pragma once
/*
371. Sum of Two Integers

Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = -2, b = 3
Output: 1
*/
#include<cmath>

int getSum(int a, int b) {
    int x = abs(a);
    int y = abs(b);
    if (x < y) {
        return getSum(b, a);
    }

    int sign = (a > 0) ? 1 : -1;

    if ((a > 0 && b > 0) || (a < 0 && b < 0)) {
        // addition
        while (y != 0) {
            int temp = x ^ y;
            int carry = (x & y) << 1;
            x = temp;
            y = carry;
        }
    }
    else {
        // subtraction
        while (y != 0) {
            int temp = x ^ y;
            int borrow = 0;
            if ((~x & y) != INT_MIN) {
                borrow = (~x & y) << 1;
            }
            x = temp;
            y = borrow;
        }
    }

    return x * sign;
}