#pragma once
/*
84. Largest Rectangle in Histogram
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

The largest rectangle is shown in the shaded area, which has area = 10 unit.

Example:

Input: [2,1,5,6,2,3]
Output: 10
*/

#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

/*
the brute force method takes O(n^2) time
use stack to store useful information to reduce time to O(n)
the stack stores the index of the elements rather than the values
*/
int largestRectangleArea(vector<int>& heights) {
    // edge case
    if (heights.size() == 0) {
        return 0;
    }

    int hSize = heights.size();
    stack<int> s;
    s.push(0);
    int maxArea = 0;
    for (int i = 1; i < heights.size(); ++i) {
        while (!s.empty() && heights[i] < heights[s.top()]) {
            int topIdx = s.top();
            s.pop();
            int width = (s.empty()) ? i : (i - s.top() - 1);
            maxArea = max(maxArea, heights[topIdx] * width);
        }
        s.push(i);
    }

    while (!s.empty()) {
        int topIdx = s.top();
        s.pop();
        if (!s.empty()) {
            maxArea = max(maxArea, heights[topIdx] * (hSize - s.top() - 1));
        }
        else {
            maxArea = max(maxArea, heights[topIdx] * hSize);
        }
    }

    return maxArea;
}