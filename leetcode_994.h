#pragma once
/*
994. Rotting Oranges

In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.



Example 1:



Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.


Note:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
grid[i][j] is only 0, 1, or 2.
*/
#include<vector>
#include<queue>

using namespace std;

vector<pair<int, int> > directions;

int orangesRotting(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    directions = vector<pair<int, int> >{ {-1, 0}, {0, -1}, {0, 1}, {1, 0} };

    int fresh = 0;
    queue<pair<int, int> > q;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 2) {
                q.push(make_pair(i, j));
            }
            else if (grid[i][j] == 1) {
                fresh += 1;
            }
        }
    }

    int round = 0;
    while (fresh > 0 && !q.empty()) {
        round += 1;
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i) {
            pair<int, int> coord = q.front();
            q.pop();
            int row = coord.first;
            int col = coord.second;
            for (pair<int, int>& dir : directions) {
                int newRow = row + dir.first;
                int newCol = col + dir.second;
                if (newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols || grid[newRow][newCol] == 0 || grid[newRow][newCol] == 2) {
                    continue;
                }
                if (grid[newRow][newCol] == 1) {
                    fresh -= 1;
                    grid[newRow][newCol] = 2;
                    q.push(make_pair(newRow, newCol));
                }
            }
        }
    }


    return (fresh == 0) ? round : -1;
}