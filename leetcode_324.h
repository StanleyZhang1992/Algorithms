#pragma once
/*
324. Wiggle Sort II

Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example 1:

Input: nums = [1, 5, 1, 1, 6, 4]
Output: One possible answer is [1, 4, 1, 5, 1, 6].
Example 2:

Input: nums = [1, 3, 2, 2, 3, 1]
Output: One possible answer is [2, 3, 1, 3, 1, 2].
Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?
*/
#include<vector>
#include<algorithm>

using namespace std;

/*
sort the array in descending order then pick element one after the second other
*/
void wiggleSort(vector<int>& nums) {
    vector<int> dup = vector<int>(nums.begin(), nums.end());
    std::sort(dup.begin(), dup.end(), std::greater<int>());
    int j = 0;
    for (int i = 1; i < nums.size(); i += 2) {
        nums[i] = dup[j];
        j += 1;
    }
    for (int i = 0; i < nums.size(); i += 2) {
        nums[i] = dup[j];
        j += 1;
    }
}