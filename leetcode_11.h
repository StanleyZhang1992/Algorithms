#pragma once
#include<vector>
#include<algorithm>

using namespace std;

/*
Use sliding window to iterate over the array only once
*/
int maxArea(vector<int>& height) {
    // edge case
    if (height.size() == 0)
        return 0;

    // main logic
    int maxSize = 0;
    int left = 0;
    int right = height.size() - 1;
    while (left < right) {
        int curSize = (right - left) * min(height[left], height[right]);
        maxSize = max(maxSize, curSize);
        if (height[left] < height[right]) {
            left += 1;
        }
        else {
            right -= 1;
        }
    }

    return maxSize;
}