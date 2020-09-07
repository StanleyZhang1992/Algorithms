#pragma once
/*
207. Course Schedule

There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.

Constraints:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
1 <= numCourses <= 10^5
*/
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

/*
use a hashtable to store the mapping between the prerequisites to courses
and another to store the remaining prerequisites of each course
use a queue to handle all unlocked courses
*/
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // edge case
    if (numCourses <= 0)
        return true;

    // main logic
    vector<int> preRemain(numCourses, 0);
    unordered_map<int, vector<int> > preRecord;
    for (vector<int> p : prerequisites) {
        int crs = p[0];
        int pre = p[1];
        preRemain[crs] += 1;
        preRecord[pre].push_back(crs);
    }

    queue<int> q;
    for (int i = 0; i < preRemain.size(); ++i) {
        if (preRemain[i] == 0) {
            q.push(i);
        }
    }
    int rem = numCourses;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        rem -= 1;
        for (int crs : preRecord[cur]) {
            preRemain[crs] -= 1;
            if (preRemain[crs] == 0)
                q.push(crs);
        }
    }

    return rem == 0;
}