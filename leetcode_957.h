#pragma once
/*
957. Prison Cells After N Days

There are 8 prison cells in a row, and each cell is either occupied or vacant.

Each day, whether the cell is occupied or vacant changes according to the following rules:

If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
Otherwise, it becomes vacant.
(Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.)

We describe the current state of the prison in the following way: cells[i] == 1 if the i-th cell is occupied, else cells[i] == 0.

Given the initial state of the prison, return the state of the prison after N days (and N such changes described above.)



Example 1:

Input: cells = [0,1,0,1,1,0,0,1], N = 7
Output: [0,0,1,1,0,0,0,0]
Explanation:
The following table summarizes the state of the prison on each day:
Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
Day 7: [0, 0, 1, 1, 0, 0, 0, 0]

Example 2:

Input: cells = [1,0,0,1,0,0,1,0], N = 1000000000
Output: [0,0,1,1,1,1,1,0]


Note:

cells.length == 8
cells[i] is in {0, 1}
1 <= N <= 10^9
*/
#include<vector>
#include<map>

using namespace std;

map<vector<int>, vector<int> > cache;

vector<int> prisonAfterNDays(vector<int>& cells, int N) {

    map<vector<int>, int> seen;

    int day = 0;
    int cycle_length = 0;
    bool fast_forward = false;
    while (N > 0) {
        if (!seen.count(cells)) {
            seen.insert({ cells, day });
            update(cells);
            N -= 1;
            day += 1;
        }
        else {
            int prev_day = seen[cells];
            cycle_length = day - prev_day;
            fast_forward = true;
            break;
        }
    }

    if (fast_forward) {
        N %= cycle_length;
        while (N > 0) {
            update(cells);
            N -= 1;
        }
    }

    return cells;
}

void update(vector<int>& cells) {
    if (cache.count(cells)) {
        cells = cache[cells];
        return;
    }

    vector<int> original = cells;
    int cSize = cells.size();

    for (int i = 1; i < cSize - 1; ++i) {
        int prev = cells[i - 1];
        int next = cells[i + 1];
        if (prev > 0) {
            if (next > 0) {
                cells[i] = (cells[i] > 0) ? 1 : -1;
            }
            else {
                cells[i] = (cells[i] > 0) ? 2 : 0;
            }
        }
        else {
            if (next > 0) {
                cells[i] = (cells[i] > 0) ? 2 : 0;
            }
            else {
                cells[i] = (cells[i] > 0) ? 1 : -1;
            }
        }
    }

    for (int i = 0; i < cSize; ++i) {
        if (cells[i] == 2)
            cells[i] = 0;
        else if (cells[i] == -1)
            cells[i] = 1;
    }


    cells[0] = 0;
    cells[cSize - 1] = 0;

    cache[original] = cells;
}