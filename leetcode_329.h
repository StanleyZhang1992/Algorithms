#pragma once
/*
329. Longest Increasing Path in a Matrix

Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

Input: nums =
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:

Input: nums =
[
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
*/
#include<vector>
#include<algorithm>

using namespace std;

/*
use dfs to search for the longest increasing sequence
use cache matrix to store the explored results so it saves the effort to repeat the same search in the future
O(m * n) time complexity
O(m * n) space complexity
*/
vector<pair<int, int> > directions;

int dfs(int i, int j, vector<vector<int> >& matrix, vector<vector<int> >& cache) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    // base case
    if (cache[i][j] != 0) {
        return cache[i][j];
    }
    // recursive case
    cache[i][j] = 1;
    for (pair<int, int> dir : directions) {
        int cur = matrix[i][j];
        int neighborR = i + dir.first;
        int neighborC = j + dir.second;
        if (neighborR < 0 || neighborR >= rows || neighborC < 0 || neighborC >= cols ||
            cur >= matrix[neighborR][neighborC]) {
            continue;
        }
        int neighbor = dfs(neighborR, neighborC, matrix, cache);
        cache[i][j] = max(cache[i][j], neighbor + 1);
    }

    return cache[i][j];
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    // edge case
    if (matrix.size() == 0 || matrix[0].size() == 0) {
        return 0;
    }
    // main logic
    int rows = matrix.size();
    int cols = matrix[0].size();
    int res = 0;
    directions = vector<pair<int, int> >{ {-1,0}, {1,0}, {0,1}, {0,-1} };
    vector<vector<int> > cache(rows, vector<int>(cols, 0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int cur = dfs(i, j, matrix, cache);
            res = max(cur, res);
        }
    }
    return res;
}