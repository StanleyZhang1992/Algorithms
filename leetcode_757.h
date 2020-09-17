#pragma once
/*
757. Set Intersection Size At Least Two

An integer interval [a, b] (for integers a < b) is a set of all consecutive integers from a to b, including a and b.

Find the minimum size of a set S such that for every integer interval A in intervals, the intersection of S with A has size at least 2.

Example 1:
Input: intervals = [[1, 3], [1, 4], [2, 5], [3, 5]]
Output: 3
Explanation:
Consider the set S = {2, 3, 4}.  For each interval, there are at least 2 elements from S in the interval.
Also, there isn't a smaller size set that fulfills the above condition.
Thus, we output the size of this set, which is 3.
Example 2:
Input: intervals = [[1, 2], [2, 3], [2, 4], [4, 5]]
Output: 5
Explanation:
An example of a minimum sized set is {1, 2, 3, 4, 5}.
Note:

intervals will have length in range [1, 3000].
intervals[i] will have length 2, representing some integer interval.
intervals[i][j] will be an integer in [0, 10^8].
*/
#include<vector>
#include<algorithm>

using namespace std;

int intersectionSizeTwo(vector<vector<int>>& intervals) {
    auto myComp = [](vector<int>& itv1, vector<int>& itv2) {
        return (itv1[0] != itv2[0]) ? (itv1[0] < itv2[0]) : (itv1[1] > itv2[1]);
    };
    std::sort(intervals.begin(), intervals.end(), myComp);
    int res = 0;
    vector<int> todo(intervals.size(), 2);
    for (int i = intervals.size() - 1; i >= 0; --i) {
        int curTodo = todo[i];
        int start = intervals[i][0];
        for (int j = start; j < start + curTodo; ++j) {
            for (int k = 0; k < intervals.size(); ++k) {
                if (j >= intervals[k][0] && j <= intervals[k][1] && todo[i] > 0) {
                    todo[k] -= 1;
                }
            }
            res += 1;
        }
    }
    return res;
}