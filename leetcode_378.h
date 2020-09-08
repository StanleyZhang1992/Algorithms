#pragma once
/*
378. Kth Smallest Element in a Sorted Matrix

Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
Note:
You may assume k is always valid, 1 ≤ k ≤ n2.
*/
#include<vector>
#include<algorithm>

using namespace std;

/*
flatten the matrix into an array then sort
O(nlogn) time
*/
int kthSmallest(vector<vector<int>>& matrix, int k) {
    vector<int> cache;
    for (vector<int> row : matrix) {
        for (int e : row) {
            cache.push_back(e);
        }
    }
    std::sort(cache.begin(), cache.end(), std::less<int>());
    return cache[k - 1];
}