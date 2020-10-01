#pragma once
/*
694. Number of Distinct Islands
Medium

915

57

Add to List

Share
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Count the number of distinct islands. An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.

Example 1:
11000
11000
00011
00011
Given the above grid map, return 1.
Example 2:
11011
10000
00001
11011
Given the above grid map, return 3.

Notice that:
11
1
and
 1
11
are considered different island shapes, because we do not consider reflection / rotation.
Note: The length of each dimension in the given grid does not exceed 50.
*/

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        int rows = grid.size();
        int cols = grid[0].size();
        set<set<pair<int, int> > > islands;
        set<pair<int, int> > visited;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                set<pair<int, int> > island;
                dfs(i, j, i, j, grid, visited, island);
                if (!island.empty()) {
                    islands.insert(island);
                }
            }
        }
        return islands.size();
    }

    void dfs(int r, int c, int r0, int c0, vector<vector<int>>& grid, set<pair<int, int> >& visited, set<pair<int, int> >& island) {
        int rows = grid.size();
        int cols = grid[0].size();
        pair<int, int> curCoord = make_pair(r, c);
        if (r < 0 || r >= rows || c < 0 || c >= cols || visited.count(curCoord) || grid[r][c] == 0) {
            return;
        }
        visited.insert(curCoord);
        island.insert(make_pair(r - r0, c - c0));
        dfs(r + 1, c, r0, c0, grid, visited, island);
        dfs(r - 1, c, r0, c0, grid, visited, island);
        dfs(r, c + 1, r0, c0, grid, visited, island);
        dfs(r, c - 1, r0, c0, grid, visited, island);
    }
};