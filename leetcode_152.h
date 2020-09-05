#pragma once
/*
152. Maximum Product Subarray

Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

#include<vector>
#include<algorithm>

using namespace std;

/*
use two dp vectors to store the max and min product
O(n) time to find the max product
*/
int maxProduct(vector<int>& nums) {
    // edge case
    if (nums.size() == 0)
        return 0;

    // main logic
    int nSize = nums.size();
    vector<int> dpMax(nSize, nums[0]);
    vector<int> dpMin(nSize, nums[0]);
    int res = nums[0];
    for (int i = 1; i < nSize; ++i) {
        dpMax[i] = max(max(dpMax[i - 1] * nums[i], dpMin[i - 1] * nums[i]), nums[i]);
        dpMin[i] = min(min(dpMax[i - 1] * nums[i], dpMin[i - 1] * nums[i]), nums[i]);
        res = max(res, dpMax[i]);
    }
    return res;
}