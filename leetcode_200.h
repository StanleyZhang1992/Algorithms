#pragma once
/*
200. Number of Islands

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.



Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/
#include<vector>

using namespace std;

/*
classic dfs method
O(m * n) time complexity
*/
class Solution {
public:
    static const vector<pair<int, int> > directions;

    int numIslands(vector<vector<char>>& grid) {
        // null case
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }

        // main logic
        int res = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    res += 1;
                    dfs(i, j, grid, rows, cols);
                }
            }
        }
        return res;
    }

private:
    void dfs(int i, int j, vector<vector<char> >& grid, int& rows, int& cols) {
        // base case
        if (i < 0 || j < 0 || i >= rows || j >= cols || grid[i][j] != '1')
            return;
        // recursive call
        grid[i][j] = '#';
        for (auto dir : Solution::directions) {
            dfs(i + dir.first, j + dir.second, grid, rows, cols);
        }
    }
};
const vector<pair<int, int> > Solution::directions{ {-1, 0}, {0, -1}, {1, 0}, {0, 1} };