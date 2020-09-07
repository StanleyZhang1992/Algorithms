#pragma once
/*
300. Longest Increasing Subsequence

Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?
*/
#include<vector>
#include<algorithm>

using namespace std;

/*
dynamic programming cache stores the LIS so far
O(n^2) time complexity
*/
int lengthOfLIS(vector<int>& nums) {
    // edge case
    if (nums.size() == 0)
        return 0;

    // main logic
    int nSize = nums.size();
    vector<int> dp(nSize, 1);
    int res = 1;
    for (int i = 0; i < nSize; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
            res = max(res, dp[i]);
        }
    }

    return res;
}