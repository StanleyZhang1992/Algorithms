#pragma once
/*
289. Game of Life

According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state. The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.
Example:
Input:
Follow up:

Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
*/
#include<vector>

using namespace std;

/*
use two special marks to mark die->live and live->die elements so that they don't confuse the count neightbor algorithm
update the matrix during the second time of iteration
*/
int countNeighbor(int i, int j, vector<vector<int> >& board) {
    int live = 0;
    for (auto dirt : directions) {
        int row = i + dirt.first;
        int col = j + dirt.second;
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size())
            continue;
        int curNeighbor = board[row][col];
        if (curNeighbor == 1 || curNeighbor == 2) {
            live += 1;
        }
    }
    return live;
}

vector<pair<int, int> > directions;
void gameOfLife(vector<vector<int>>& board) {
    // edge case
    if (board.size() == 0 || board[0].size() == 0) {
        return;
    }

    // main logic
    directions = vector<pair<int, int> >{
        {-1, -1},
        {-1, 0},
        {-1, 1},
        {0, -1},
        {0, 1},
        {1, -1},
        {1, 0},
        {1, 1}
    };
    int rows = board.size();
    int cols = board[0].size();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int live = countNeighbor(i, j, board);
            if (board[i][j] == 1) {   // live
                if (live < 2 || live > 3)   // live->die
                    board[i][j] = 2;
            }
            else {  // dead
                if (live == 3) // die->live
                    board[i][j] = -1;
            }
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (board[i][j] == 2)
                board[i][j] = 0;
            if (board[i][j] == -1)
                board[i][j] = 1;
        }
    }
}