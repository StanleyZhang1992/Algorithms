#pragma once
/*
215. Kth Largest Element in an Array

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/
#include<vector>
#include<queue>

using namespace std;

/*
use heap structure
to find the kth largest element, we need a minheap to iterate over the array and evict the smaller elements
eventually what's left in the heap would be the k largest elements and the top one is the kth largest
O(n) time
*/
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, std::greater<int>> heap;
    for (int n : nums) {
        if (heap.size() < k) {
            heap.push(n);
        }
        else {
            if (n > heap.top()) {
                heap.pop();
                heap.push(n);
            }
        }
    }
    return heap.top();
}