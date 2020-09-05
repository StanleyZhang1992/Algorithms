#pragma once
/*
121. Best Time to Buy and Sell Stock

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/
#include<vector>
#include<algorithm>

using namespace std;

/*
use either dynamic programming or sliding window method
O(n) time
*/
int maxProfit(vector<int>& prices) {
    return slidingWindow(prices);
}

int dp(vector<int>& prices) {
    // edge case
    if (prices.size() == 0)
        return 0;

    // main logic
    vector<vector<int> > dp(prices.size(), vector<int>(2, 0));
    dp[0][1] = -prices[0];
    int pSize = prices.size();
    for (int i = 1; i < pSize; ++i) {
        dp[i][1] = max(dp[i - 1][1], -prices[i]);
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
    }

    return dp[pSize - 1][0];
}

int slidingWindow(vector<int>& prices) {
    // edge case
    if (prices.size() == 0)
        return 0;

    int buy = 0;
    int sell = 0;
    int maxProfit = 0;
    while (sell < prices.size()) {
        maxProfit = max(maxProfit, prices[sell] - prices[buy]);
        if (prices[sell] < prices[buy]) {
            buy = sell;
        }
        sell += 1;
    }
    return maxProfit;
}