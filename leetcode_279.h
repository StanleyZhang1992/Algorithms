#pragma once
/*
279. Perfect Squares

Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/
#include<vector>
#include<algorithm>

using namespace std;

/*
use dynamic programming to store the information of maxSquare numbers of each number from 0 to n
O(n^2) time complexity
*/
int numSquares(int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 0; i <= n; ++i) {
        dp[i] = i;
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = 1; i - j * j >= 0; ++j) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }

    return dp[n];
}