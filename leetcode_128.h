#pragma once
/*
128. Longest Consecutive Sequence

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

/*
use hashtable to store all numbers
then while iterating each number, check only those who has larger items and count the total length
O(n) time
O(n) space
*/
int longestConsecutive(vector<int>& nums) {
    std::unordered_set<int> cache = std::unordered_set<int>(nums.begin(), nums.end());
    int res = 0;
    for (int n : nums) {
        if (cache.count(n - 1)) {
            continue;
        }
        int cur = n;
        int longestSeq = 1;
        while (cache.count(cur + 1)) {
            longestSeq += 1;
            cur += 1;
        }
        res = max(res, longestSeq);
    }
    return res;
}