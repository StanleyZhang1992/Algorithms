#pragma once

/*
42. Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/

#include<vector>
#include<algorithm>

using namespace std;

/*
Use cache to store the maxHeight from left and from right, then for each column we can find the trapped water there.
time complexity is O(n)
space complexity is O(n)
*/
int trap(vector<int>& height) {
    // edge case
    if (height.size() == 0)
        return 0;

    // main logic
    int hSize = height.size();
    vector<int> leftMax(hSize, 0);
    vector<int> rightMax(hSize, 0);
    leftMax[0] = height[0];
    rightMax[hSize - 1] = height[hSize - 1];
    for (int i = 1; i < hSize; ++i) {
        leftMax[i] = max(leftMax[i - 1], height[i]);
    }
    for (int j = hSize - 2; j >= 0; --j) {
        rightMax[j] = max(rightMax[j + 1], height[j]);
    }
    int res = 0;
    for (int i = 0; i < hSize; ++i) {
        int cur = min(leftMax[i], rightMax[i]) - height[i];
        res += cur;
    }
    return res;
}