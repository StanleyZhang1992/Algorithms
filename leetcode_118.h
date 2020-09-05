#pragma once
/*
118. Pascal's Triangle

Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
#include<vector>

using namespace std;

/*
classic dynamic programming
time complexity is the size of the triangle
*/
vector<vector<int>> generate(int numRows) {
    int row = 0;
    vector<vector<int> > res;
    while (row < numRows) {
        if (row == 0) {
            res.push_back(vector<int>(1, 1));
        }
        else {
            vector<int> curRow;
            for (int j = 0; j <= row; ++j) {
                if (j == 0 || j == row) {
                    curRow.push_back(1);
                }
                else {
                    int curNum = res[row - 1][j] + res[row - 1][j - 1];
                    curRow.push_back(curNum);
                }
            }
            res.push_back(curRow);
        }
        row += 1;
    }
    return res;
}