#pragma once
/*
628. Maximum Product of Three Numbers

Given an integer array, find three numbers whose product is maximum and output the maximum product.

Example 1:

Input: [1,2,3]
Output: 6


Example 2:

Input: [1,2,3,4]
Output: 24


Note:

The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.
*/
#include<vector>
#include<algorithm>

using namespace std;

int maximumProduct(vector<int>& nums) {
    int min1 = INT_MAX;
    int min2 = INT_MAX;
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    int max3 = INT_MIN;

    for (int n : nums) {
        if (n > max1) {
            max3 = max2;
            max2 = max1;
            max1 = n;
        }
        else if (n > max2) {
            max3 = max2;
            max2 = n;
        }
        else if (n > max3) {
            max3 = n;
        }

        if (n < min1) {
            min2 = min1;
            min1 = n;
        }
        else if (n < min2) {
            min2 = n;
        }
    }

    int cand1 = max1 * max2 * max3;
    int cand2 = max1 * min1 * min2;

    return max(cand1, cand2);
}