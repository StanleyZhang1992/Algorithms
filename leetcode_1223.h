#pragma once
/*
1223. Dice Roll Simulation

A die simulator generates a random number from 1 to 6 for each roll. You introduced a constraint to the generator such that it cannot roll the number i more than rollMax[i] (1-indexed) consecutive times.

Given an array of integers rollMax and an integer n, return the number of distinct sequences that can be obtained with exact n rolls.

Two sequences are considered different if at least one element differs from each other. Since the answer may be too large, return it modulo 10^9 + 7.



Example 1:

Input: n = 2, rollMax = [1,1,2,2,2,3]
Output: 34
Explanation: There will be 2 rolls of die, if there are no constraints on the die, there are 6 * 6 = 36 possible combinations. In this case, looking at rollMax array, the numbers 1 and 2 appear at most once consecutively, therefore sequences (1,1) and (2,2) cannot occur, so the final answer is 36-2 = 34.
Example 2:

Input: n = 2, rollMax = [1,1,1,1,1,1]
Output: 30
Example 3:

Input: n = 3, rollMax = [1,1,1,2,2,3]
Output: 181


Constraints:

1 <= n <= 5000
rollMax.length == 6
1 <= rollMax[i] <= 15
*/
#include<algorithm>
#include<vector>

using namespace std;

/*
动态规划，设置dp[n][i]表示长度为n，且最后结尾的数为i的组合数量。
dp[n][i]等于所有长度为n且第(n-1,n-2...,n-rollmax[i])位不为i的组合之和.
*/
int dieSimulator(int n, vector<int>& rollMax) {
    vector<vector<long long>> dp(n + 1, vector<long long>(7, 0));
    long long mod = 1e9 + 7;
    long long res = 0;

    /*initial*/
    for (int i = 1; i <= 6; ++i) {
        for (int j = 1; j <= min(n, rollMax[i - 1]); ++j) {
            dp[j][i] = 1;
        }
    }

    /*dp*/
    for (int i = 2;i <= n; ++i) {
        for (int j = 1; j <= 6; ++j) {
            for (int k = 1; k <= min(rollMax[j - 1], i); ++k) {
                for (int l = 1; l <= 6; ++l) {
                    if (j == l) { continue; }
                    dp[i][j] = (dp[i][j] + dp[i - k][l]) % mod;
                }
            }
        }
    }

    for (int i = 1;i <= 6; ++i) {
        res = (res + dp[n][i]) % mod;
    }

    return (int)res;
}