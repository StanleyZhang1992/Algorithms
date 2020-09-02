#pragma once
#include<vector>

using namespace std;

// find the first missing positive integer in the given array of numbers
/*
Use hashtable is one way, however the space complexity is high.
If we use the array itself as the hashtable we can reduce the space complexity to O(1)
The first missing number must be in the range of [1, n+1], n is the length of the given array.
*/
int firstMissingPositive(vector<int>& nums) {
    int nSize = nums.size();
    bool existOne = false;
    for (int i = 0; i < nSize; ++i) {
        if (nums[i] == 1) {
            existOne = true;
        }
        if (nums[i] <= 0 || nums[i] > nSize) {
            nums[i] = 1;
        }
    }
    if (existOne == false)
        return 1;

    for (int i = 0; i < nSize; ++i) {
        nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
    }

    int first = nSize + 1;
    for (int i = 0; i < nSize; ++i) {
        if (nums[i] > 0) {
            first = i + 1;
            break;
        }
    }
    return first;
}