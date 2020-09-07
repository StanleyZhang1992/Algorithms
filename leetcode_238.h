#pragma once
/*
238. Product of Array Except Self

Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
*/
#include<vector>

using namespace std;

/*
use two vectors to store pre and post product
the current product can be calculated by multiplying pre-post products
*/
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> pre(nums.size(), 1);
    vector<int> suf(nums.size(), 1);
    for (int i = 1; i < nums.size(); ++i) {
        pre[i] = pre[i - 1] * nums[i - 1];
    }
    for (int j = nums.size() - 2; j >= 0; --j) {
        suf[j] = suf[j + 1] * nums[j + 1];
    }
    for (int i = 0; i < nums.size(); ++i) {
        pre[i] = pre[i] * suf[i];
    }
    return pre;
}