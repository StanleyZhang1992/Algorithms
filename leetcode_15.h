#pragma once

/*
15. 3Sum

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

#include<vector>
#include<algorithm>

using namespace std;


/*
Sort first
Then set each element as the anchor and use two pointers to iterate over the rest of the array
Time complexity is O(n^2)
*/
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int> > res;
    // edge case
    if (nums.size() == 0)
        return res;

    // main logic
    std::sort(nums.begin(), nums.end(), std::less<int>());
    int cur = 0;
    while (cur < nums.size()) {
        while (cur > 0 && cur < nums.size() && nums[cur] == nums[cur - 1]) {
            cur += 1;
        }
        if (cur == nums.size()) {
            break;
        }
        int left = cur + 1;
        int right = nums.size() - 1;
        while (left < right) {
            int target = -nums[cur];
            int s = nums[left] + nums[right];
            if (s == target) {
                res.push_back({ nums[cur], nums[left], nums[right] });
                left += 1;
                while (left < nums.size() && nums[left] == nums[left - 1]) {
                    left += 1;
                }
            }
            else if (s < target) {
                left += 1;
            }
            else {
                right -= 1;
            }
        }
        cur += 1;
    }

    return res;
}