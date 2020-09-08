#pragma once
/*
322. Coin Change

You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Note:
You may assume that you have an infinite number of each kind of coin.
*/
#include<vector>
#include<algorithm>

using namespace std;

/*
dynamic programming
*/
int coinChange(vector<int>& coins, int amount) {
    vector<vector<int> > dp(coins.size() + 1, vector<int>(amount + 1, INT_MAX));
    dp[0][0] = 0;
    for (int i = 1; i <= coins.size(); ++i) {
        for (int j = 0; j <= amount; ++j) {
            int curCoin = coins[i - 1];
            if (j - curCoin < 0) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                if (dp[i][j - curCoin] == INT_MAX) {
                    dp[i][j - curCoin] -= 1;
                }
                dp[i][j] = min(dp[i - 1][j], dp[i][j - curCoin] + 1);
            }
        }
    }
    return dp[coins.size()][amount] == INT_MAX ? -1 : dp[coins.size()][amount];
}