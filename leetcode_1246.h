#pragma once
/*
1246. Palindrome Removal

Given an integer array arr, in one move you can select a palindromic subarray arr[i], arr[i+1], ..., arr[j] where i <= j, and remove that subarray from the given array. Note that after removing a subarray, the elements on the left and on the right of that subarray move to fill the gap left by the removal.

Return the minimum number of moves needed to remove all numbers from the array.



Example 1:

Input: arr = [1,2]
Output: 2
Example 2:

Input: arr = [1,3,4,1,5]
Output: 3
Explanation: Remove [4] then remove [1,3,1] then remove [5].


Constraints:

1 <= arr.length <= 100
1 <= arr[i] <= 20
*/
#include<vector>
#include<algorithm>

using namespace std;

int minimumMoves(vector<int>& arr) {
    vector<vector<int> > dp(arr.size(), vector<int>(arr.size(), INT_MAX));
    for (int i = 0; i < arr.size(); ++i) {
        dp[i][i] = 1;
    }
    for (int i = 1; i < arr.size(); ++i) {
        dp[i][i - 1] = 1;
    }
    for (int i = arr.size() - 2; i >= 0; --i) {
        for (int j = i + 1; j < arr.size(); ++j) {
            if (arr[i] == arr[j]) {
                dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
            }
            for (int k = i; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
        }
    }
    return dp[0][arr.size() - 1];
}