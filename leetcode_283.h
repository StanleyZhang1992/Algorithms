#pragma once
/*
283. Move Zeroes

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/
#include<vector>

using namespace std;

/*
pointer i used to collect all non-zero elements
pointer j used to iterate over the array
O(n) time complexity
*/
void moveZeroes(vector<int>& nums) {
    int i = 0;
    int j = 0;
    int nSize = nums.size();
    while (j < nSize) {
        if (nums[j] != 0) {
            nums[i] = nums[j];
            i += 1;
        }
        j += 1;
    }
    while (i < nSize) {
        nums[i] = 0;
        i += 1;
    }
}