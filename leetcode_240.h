#pragma once
/*
240. Search a 2D Matrix II

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Example:

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
*/
#include<vector>

using namespace std;

/*
start from the bottom left, perform zig-zag search
O(m + n) time complexity
*/
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // edge case
    if (matrix.size() == 0 || matrix[0].size() == 0) {
        return false;
    }
    // main logic
    int rows = matrix.size();
    int cols = matrix[0].size();
    int row = matrix.size() - 1;
    int col = 0;
    while (row >= 0 && col < cols) {
        int curVal = matrix[row][col];
        if (curVal == target) {
            return true;
        }
        else if (curVal > target) {
            row -= 1;
        }
        else {
            col += 1;
        }
    }

    return false;
}