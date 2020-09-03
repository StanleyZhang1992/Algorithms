#pragma once

/*
56. Merge Intervals

Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

Constraints:

intervals[i][0] <= intervals[i][1]
*/
#include<vector>
#include<algorithm>

using namespace std;

/*
use sorting to arrange the intervals so the problem is simplified
takes O(nlogn) time
*/
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int> > res;
    if (intervals.size() == 0)
        return res;

    auto myComp = [](vector<int>& in1, vector<int>& in2) {
        if (in1.front() < in2.front()) {
            if (in1.front() == in2.front()) {
                if (in1.end() < in2.end()) {
                    return true;
                }
                else {
                    return false;
                }
            }
            else {
                return true;
            }
        }
        else {
            return false;
        }
    };
    std::sort(intervals.begin(), intervals.end(), myComp);

    res.push_back(intervals[0]);
    int iSize = intervals.size();
    for (int i = 1; i < iSize; ++i) {
        vector<int> curIn = intervals[i];
        if (curIn.front() > res.back().back()) {
            res.push_back(curIn);
        }
        else {
            res.back().back() = max(res.back().back(), curIn.back());
        }
    }

    return res;
}