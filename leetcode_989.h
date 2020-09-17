#pragma once
/*
989. Add to Array-Form of Integer

For a non-negative integer X, the array-form of X is an array of its digits in left to right order.  For example, if X = 1231, then the array form is [1,2,3,1].

Given the array-form A of a non-negative integer X, return the array-form of the integer X+K.



Example 1:

Input: A = [1,2,0,0], K = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234
Example 2:

Input: A = [2,7,4], K = 181
Output: [4,5,5]
Explanation: 274 + 181 = 455
Example 3:

Input: A = [2,1,5], K = 806
Output: [1,0,2,1]
Explanation: 215 + 806 = 1021
Example 4:

Input: A = [9,9,9,9,9,9,9,9,9,9], K = 1
Output: [1,0,0,0,0,0,0,0,0,0,0]
Explanation: 9999999999 + 1 = 10000000000


Note：

1 <= A.length <= 10000
0 <= A[i] <= 9
0 <= K <= 10000
If A.length > 1, then A[0] != 0
*/
#include<vector>

using namespace std;

vector<int> addToArrayForm(vector<int>& A, int K) {
    vector<int> B;
    while (K > 0) {
        B.push_back(K % 10);
        K = K / 10;
    }
    std::reverse(B.begin(), B.end());

    int p1 = A.size() - 1;
    int p2 = B.size() - 1;
    int carry = 0;
    vector<int> res;
    while (p1 >= 0 || p2 >= 0) {
        int curA = (p1 >= 0) ? A[p1] : 0;
        int curB = (p2 >= 0) ? B[p2] : 0;
        int curS = curA + curB + carry;
        carry = curS / 10;
        res.push_back(curS % 10);
        p1 -= 1;
        p2 -= 1;
    }
    if (carry) {
        res.push_back(1);
    }
    std::reverse(res.begin(), res.end());
    return res;
}