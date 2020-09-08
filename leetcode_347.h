#pragma once
/*
347. Top K Frequent Elements

Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
You can return the answer in any order.
*/
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

/*
use customized priority queue to store the elements and pop to the res vector
*/
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> cache;
    for (int n : nums) {
        cache[n] += 1;
    }

    auto myComp = [&cache](int i, int j) {
        if (cache[i] > cache[j])
            return true;
        else
            return false;
    };
    priority_queue<int, vector<int>, decltype(myComp)> minHeap(myComp);
    for (auto p : cache) {
        int cur = p.first;
        if (minHeap.size() < k) {
            minHeap.push(cur);
        }
        else {
            int heapTop = minHeap.top();
            if (p.second > cache[heapTop]) {
                minHeap.pop();
                minHeap.push(cur);
            }
        }
    }

    vector<int> res;
    while (!minHeap.empty()) {
        res.push_back(minHeap.top());
        minHeap.pop();
    }

    return res;
}