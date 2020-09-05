#pragma once

/*
79. Word Search

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.


Constraints:

board and word consists only of lowercase and uppercase English letters.
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3
*/
#include<vector>
#include<string>

using namespace std;

/*
use dfs to search for the word.
mark the visited place as '#" and convert it back to its original char after dfs is done
*/
vector<pair<int, int> > directions;
bool dfs(int i, int j, int idx, string& word, vector<vector<char> >& board) {
    int rows = board.size();
    int cols = board[0].size();
    // base case
    if (i < 0 || j < 0 || i >= rows || j >= cols || board[i][j] != word[idx]) {
        return false;
    }
    if (idx == word.size() - 1)
        return true;
    // recursive case
    char temp = board[i][j];
    board[i][j] = '#';
    for (pair<int, int> dir : directions) {
        if (dfs(i + dir.first, j + dir.second, idx + 1, word, board) == true) {
            return true;
        }
    }
    board[i][j] = temp;
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    // edge case
    if (board.size() == 0 || board[0].size() == 0)
        return false;
    // main logic
    directions = vector<pair<int, int> >{ {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
    int rows = board.size();
    int cols = board[0].size();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            bool e = dfs(i, j, 0, word, board);
            if (e)
                return true;
        }
    }
    return false;
}