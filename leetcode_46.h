#pragma once

/*
46. Permutations

Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/
#include<vector>

using namespace std;

/*
factorial time complexity
use cache to store the visited element to avoid visiting again
*/
void dfs(vector<int>& path, vector<vector<int> >& res, vector<int>& nums, vector<bool>& cache) {
    // base case
    if (path.size() == nums.size()) {
        res.push_back(path);
        return;
    }
    // recursive case
    for (int i = 0; i < nums.size(); ++i) {
        if (cache[i]) {
            continue;
        }
        path.push_back(nums[i]);
        cache[i] = true;
        dfs(path, res, nums, cache);
        path.pop_back();
        cache[i] = false;
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int> > res;
    // sanity check
    if (nums.size() == 0)
        return res;

    // main logic
    vector<int> path;
    vector<bool> cache(nums.size(), false);
    dfs(path, res, nums, cache);
    return res;
}