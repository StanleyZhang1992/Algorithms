#pragma once
/*
162. Find Peak Element

A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -∞.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 1 or 5
Explanation: Your function can return either index number 1 where the peak element is 2,
             or index number 5 where the peak element is 6.
Follow up: Your solution should be in logarithmic complexity.
*/
#include<vector>

using namespace std;

/*
the range between start and end pointers will always contain the peak
each time eliminate half of the range
O(logn) time
*/
int findPeakElement(vector<int>& nums) {
    // edge case
    if (nums.size() == 0)
        return -1;
    if (nums.size() == 1)
        return 0;

    // main logic
    int nSize = nums.size();
    int start = 0;
    int end = nSize - 1;
    while (start < end) {
        int mid = start + (end - start) / 2;
        if (mid == 0) {
            if (nums[mid] > nums[mid + 1]) {
                return mid;
            }
            else {
                start = mid + 1;
            }
        }
        else if (mid == nSize - 1) {
            if (nums[mid] > nums[mid - 1]) {
                return mid;
            }
            else {
                end = mid - 1;
            }
        }
        else {
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            }
            else if (nums[mid] < nums[mid + 1]) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
    }
    return start;
}