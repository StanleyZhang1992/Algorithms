#pragma once
#include<vector>
#include<unordered_map>

using namespace std;

/*
There are many ways to approach this problem.
For example: we can use brute force (i.e. search in every pair); we can sort the array first and then use two pointers
But the best way to do it, in terms of the minimal time complexity would be using a hashtable
The hashtable saves the index info that can pair with the current element to make the target sum.
*/
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> cache;
    int nSize = nums.size();
    for (int i = 0; i < nSize; ++i) {
        int rm = target - nums[i];
        if (!cache.count(rm)) {
            cache.insert({ nums[i], i });
        }
        else {
            return vector<int>{i, cache[rm]};
        }
    }
    return vector<int>{};
}