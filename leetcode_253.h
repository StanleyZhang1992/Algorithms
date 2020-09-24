#pragma once
/*
253. Meeting Rooms II

Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

Example 1:

Input: [[0, 30],[5, 10],[15, 20]]
Output: 2
Example 2:

Input: [[7,10],[2,4]]
Output: 1
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/
#include<vector>
#include<queue>

using namespace std;

int minMeetingRooms(vector<vector<int>>& intervals) {
    auto myComp = [](vector<int>& i1, vector<int>& i2) {
        return i1[0] < i2[0];
    };
    std::sort(intervals.begin(), intervals.end(), myComp);
    int rooms = 0;
    priority_queue<int, vector<int>, std::greater<int> > pq;

    for (vector<int>& meeting : intervals) {
        if (pq.empty()) {
            rooms += 1;
            pq.push(meeting[1]);
        }
        else {
            if (pq.top() > meeting[0]) {
                pq.push(meeting[1]);
                rooms += 1;
            }
            else {
                pq.pop();
                pq.push(meeting[1]);
            }
        }
    }

    return rooms;
}