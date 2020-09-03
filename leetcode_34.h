#pragma once

/*
34. Find First and Last Position of Element in Sorted Array

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]


Constraints:

0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
nums is a non decreasing array.
-10^9 <= target <= 10^9
*/

#include<vector>

using namespace std;

/*
since we are looking for two edges, the boundary conditions are changed a little bit in this problem.
overall time is still O(logn)
*/
int findLeft(vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size() - 1;
    while (start + 1 < end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] >= target) {
            end = mid;
        }
        else {
            start = mid;
        }
    }
    if (nums[start] == target) {
        return start;
    }
    else if (nums[end] == target) {
        return end;
    }
    return -1;
}

int findRight(vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size() - 1;
    while (start + 1 < end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] <= target) {
            start = mid;
        }
        else {
            end = mid;
        }
    }
    if (nums[end] == target) {
        return end;
    }
    else if (nums[start] == target) {
        return start;
    }
    return -1;
}

vector<int> searchRange(vector<int>& nums, int target) {
    // edge case
    if (nums.size() == 0) {
        return vector<int>{-1, -1};
    }

    // main logic
    int left = findLeft(nums, target);
    int right = findRight(nums, target);
    return vector<int>{left, right};
}