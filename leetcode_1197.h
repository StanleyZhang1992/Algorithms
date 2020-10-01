#pragma once
/*
1197. Minimum Knight Moves

In an infinite chess board with coordinates from -infinity to +infinity, you have a knight at square [0, 0].

A knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.



Return the minimum number of steps needed to move the knight to the square [x, y].  It is guaranteed the answer exists.



Example 1:

Input: x = 2, y = 1
Output: 1
Explanation: [0, 0] → [2, 1]
Example 2:

Input: x = 5, y = 5
Output: 4
Explanation: [0, 0] → [2, 1] → [4, 2] → [3, 4] → [5, 5]


Constraints:

|x| + |y| <= 300
*/

class Solution {
public:
    int minKnightMoves(int x, int y) {
        pair<int, int> target = make_pair(x, y);
        if (target == make_pair(0, 0))
            return 0;
        int res = 0;
        vector<pair<int, int> > directions{ {1, 2},{1, -2},{2, 1},{2, -1},
                                           {-1, 2},{-1, -2},{-2, 1},{-2, -1} };
        int max_x = max(0, x) + 2;
        int min_x = min(0, x) - 2;
        int max_y = max(0, y) + 2;
        int min_y = min(0, y) - 2;
        queue<pair<int, int> > q;
        q.push(make_pair(0, 0));
        set<pair<int, int> > visited;
        visited.insert(make_pair(0, 0));
        while (!q.empty()) {
            res += 1;
            int qSize = q.size();
            for (int i = 0; i < qSize; ++i) {
                pair<int, int> pos = q.front();
                q.pop();
                for (pair<int, int> p : directions) {
                    pair<int, int> newPos =
                        make_pair(pos.first + p.first, pos.second + p.second);
                    if (newPos == target) {
                        return res;
                    }
                    if (visited.count(newPos) || newPos.first < min_x || newPos.first > max_x || newPos.second < min_y || newPos.second > max_y) {
                        continue;
                    }
                    q.push(newPos);
                    visited.insert(newPos);
                }
            }
        }

        return res;
    }
};