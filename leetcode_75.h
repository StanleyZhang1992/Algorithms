#pragma once
/*
75. Sort Colors

Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?
*/

#include<vector>

using namespace std;

/*
dutch flag problem
we use three pointers
the important thing here is the semantics of the pointers
always guarantee the semantics
*/
void sortColors(vector<int>& nums) {
    // edge case
    if (nums.size() == 0)
        return;

    // main logic
    int nSize = nums.size();
    int i = -1;
    int j = 0;
    int k = nSize;
    while (j < k) {
        if (nums[j] == 1) {
            j += 1;
        }
        else if (nums[j] == 0) {
            std::swap(nums[i + 1], nums[j]);
            i += 1;
            if (i >= j) {
                j += 1;
            }
        }
        else {
            std::swap(nums[j], nums[k - 1]);
            k -= 1;
        }
    }
}