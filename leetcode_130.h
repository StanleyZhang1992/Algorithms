#pragma once
/*
130. Surrounded Regions

Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/

#include<vector>

using namespace std;

/*
use dfs to scan the graph
start from the four edges, if there is 'O' area, then the areas it can reach will become 'O' eventually
*/
void dfs(int i, int j, vector<vector<char> >& board) {
    // base case
    int rows = board.size();
    int cols = board[0].size();
    if (i < 0 || j < 0 || i >= rows || j >= cols)
        return;
    if (board[i][j] != 'O')
        return;
    // recursive case
    board[i][j] = '#';
    dfs(i - 1, j, board);
    dfs(i + 1, j, board);
    dfs(i, j - 1, board);
    dfs(i, j + 1, board);

}

void solve(vector<vector<char>>& board) {
    // edge case
    if (board.size() == 0 || board[0].size() == 0) {
        return;
    }

    // main logic
    int rows = board.size();
    int cols = board[0].size();
    for (int i = 0; i < rows; ++i) {
        if (board[i][0] == 'O') {
            dfs(i, 0, board);
        }
        if (board[i][cols - 1] == 'O') {
            dfs(i, cols - 1, board);
        }
    }
    for (int j = 0; j < cols; ++j) {
        if (board[0][j] == 'O') {
            dfs(0, j, board);
        }
        if (board[rows - 1][j] == 'O') {
            dfs(rows - 1, j, board);
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }
            if (board[i][j] == '#') {
                board[i][j] = 'O';
            }

        }
    }
}