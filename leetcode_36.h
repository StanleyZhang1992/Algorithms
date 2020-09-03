#pragma once

/*
36. Valid Sudoku

Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

A partially filled sudoku which is valid.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Example 1:

Input:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: true
Example 2:

Input:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being
    modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
The given board contain only digits 1-9 and the character '.'.
The given board size is always 9x9.
*/

#include<vector>
#include<unordered_set>

using namespace std;

/*
use i-j-k to validate each box.
time complexity is O(1) since the board's size is fixed
*/
bool isValidSudoku(vector<vector<char>>& board) {
    // edge case
    if (board.size() == 0 || board[0].size() == 0)
        return true;

    // validate the rows
    for (int i = 0; i < 9; ++i) {
        std::unordered_set<int> cache;
        for (int j = 0; j < 9; ++j) {
            int cur = board[i][j];
            if (cur == '.') {
                continue;
            }
            else {
                if (cache.count(cur)) {
                    return false;
                }
                else {
                    cache.insert(cur);
                }
            }
        }
    }

    // validate the cols
    for (int j = 0; j < 9; ++j) {
        std::unordered_set<int> cache;
        for (int i = 0; i < 9; ++i) {
            int cur = board[i][j];
            if (cur == '.') {
                continue;
            }
            else {
                if (cache.count(cur)) {
                    return false;
                }
                else {
                    cache.insert(cur);
                }
            }
        }
    }

    // validate the boxes
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::unordered_set<int> cache;
            for (int k = 0; k < 9; ++k) {
                int cur = board[i * 3 + k / 3][j * 3 + k % 3];
                if (cur == '.') {
                    continue;
                }
                else {
                    if (cache.count(cur)) {
                        return false;
                    }
                    else {
                        cache.insert(cur);
                    }
                }
            }
        }
    }

    return true;
}