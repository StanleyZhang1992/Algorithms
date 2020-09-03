#pragma once
/*
54. Spiral Matrix

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

#include<vector>

using namespace std;

/*
take care of the outer-most layer, then the rest can be taken care of by recursion
O(n) time
*/
void dfs(vector<int>& res, vector<vector<int> >& matrix, int row_upper, int row_down, int col_left, int col_right) {
    // base case
    if (row_upper > row_down || col_left > col_right)
        return;
    if (row_upper == row_down) {
        for (int j = col_left; j <= col_right; ++j) {
            res.push_back(matrix[row_upper][j]);
        }
        return;
    }
    if (col_left == col_right) {
        for (int i = row_upper; i <= row_down; ++i) {
            res.push_back(matrix[i][col_left]);
        }
        return;
    }
    // recursive case
    for (int j = col_left; j <= col_right; ++j) {
        res.push_back(matrix[row_upper][j]);
    }
    for (int i = row_upper + 1; i <= row_down; ++i) {
        res.push_back(matrix[i][col_right]);
    }
    for (int j = col_right - 1; j >= col_left; --j) {
        res.push_back(matrix[row_down][j]);
    }
    for (int i = row_down - 1; i > row_upper; --i) {
        res.push_back(matrix[i][col_left]);
    }
    dfs(res, matrix, row_upper + 1, row_down - 1, col_left + 1, col_right - 1);
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    if (matrix.size() == 0 || matrix[0].size() == 0) {
        return res;
    }
    dfs(res, matrix, 0, matrix.size() - 1, 0, matrix[0].size() - 1);
    return res;
}