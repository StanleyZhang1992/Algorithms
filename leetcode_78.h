#pragma once
/*
78. Subsets

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
#include<vector>

using namespace std;

/*
classic backtracking with dfs
use idx as the tracker
factorial time
*/
void dfs(vector<int>& path, int idx, vector<vector<int> >& res, vector<int>& nums) {
    // base case
    if (idx > nums.size())
        return;
    // recursive case
    res.push_back(path);
    for (int i = idx; i < nums.size(); ++i) {
        path.push_back(nums[i]);
        dfs(path, i + 1, res, nums);
        path.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int> > res;
    // sanity check
    if (nums.size() == 0)
        return res;

    vector<int> path;
    dfs(path, 0, res, nums);
    return res;
}