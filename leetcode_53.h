#pragma once

/*
53. Maximum Subarray

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/
#include<vector>
#include<algorithm>

using namespace std;

/*
the max value at ith idx is related to the max value at i-1th index,
use this as the breakpoint to build up dynamic programming approach
time is O(n)
*/
int maxSubArray(vector<int>& nums) {
    // edge case
    if (nums.size() == 0)
        return 0;

    // main logic
    vector<int> dp(nums.size(), nums[0]);
    int nSize = nums.size();
    int maxVal = nums[0];
    for (int i = 1; i < nSize; ++i) {
        dp[i] = max(nums[i], dp[i - 1] + nums[i]);
        if (dp[i] > maxVal)
            maxVal = dp[i];
    }
    return maxVal;
}