#pragma once
/*
1091. Shortest Path in Binary Matrix

In an N by N square grid, each cell is either empty (0) or blocked (1).

A clear path from top-left to bottom-right has length k if and only if it is composed of cells C_1, C_2, ..., C_k such that:

Adjacent cells C_i and C_{i+1} are connected 8-directionally (ie., they are different and share an edge or corner)
C_1 is at location (0, 0) (ie. has value grid[0][0])
C_k is at location (N-1, N-1) (ie. has value grid[N-1][N-1])
If C_i is located at (r, c), then grid[r][c] is empty (ie. grid[r][c] == 0).
Return the length of the shortest such clear path from top-left to bottom-right.  If such a path does not exist, return -1.



Example 1:

Input: [[0,1],[1,0]]


Output: 2

Example 2:

Input: [[0,0,0],[1,1,0],[1,1,0]]


Output: 4



Note:

1 <= grid.length == grid[0].length <= 100
grid[r][c] is 0 or 1
*/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // sanity check
        if (grid.size() == 0 || grid[0].size() == 0)
            return -1;

        if (grid[0][0] == 1) {
            return -1;
        }

        set<pair<int, int> > visited;
        int steps = 1;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<pair<int, int> > directions{ {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };
        queue<pair<int, int> > q;
        q.push(make_pair(0, 0));
        visited.insert(make_pair(0, 0));
        pair<int, int> last{ 0, 0 };
        while (!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; ++i) {
                pair<int, int> cur = q.front();
                q.pop();
                if (last.first < cur.first || last.second < cur.second) {
                    last = cur;
                }
                if (last == pair<int, int>{rows - 1, cols - 1}) {
                    return steps;
                }
                for (pair<int, int> dir : directions) {
                    int newRow = cur.first + dir.first;
                    int newCol = cur.second + dir.second;
                    pair<int, int> curPair = pair<int, int>{ newRow, newCol };
                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == 0 && visited.count(curPair) == 0) {
                        q.push(make_pair(newRow, newCol));
                        visited.insert(make_pair(newRow, newCol));
                    }
                }
            }
            steps += 1;
        }

        return -1;
    }
};