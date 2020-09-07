#pragma once
/*
295. Find Median from Data Stream

Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

For example,
[2,3,4], the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.


Example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3)
findMedian() -> 2


Follow up:

If all integer numbers from the stream are between 0 and 100, how would you optimize it?
If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?
*/
#include<queue>

using namespace std;

/*
use two heaps to keep track of the two median numbers
lookup takes O(1) time
insert takes O(logn) time
*/
class MedianFinder {
public:

    priority_queue<int, vector<int>, std::greater<int> > minHeap;
    priority_queue<int, vector<int>, std::less<int> > maxHeap;

    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if (maxHeap.empty()) {
            maxHeap.push(num);
            return;
        }

        if (num < maxHeap.top()) {
            maxHeap.push(num);
        }
        else {
            minHeap.push(num);
        }

        if (maxHeap.size() - minHeap.size() == 2) {
            int popNum = maxHeap.top();
            maxHeap.pop();
            minHeap.push(popNum);
        }
        if (minHeap.size() > maxHeap.size()) {
            int popNum = minHeap.top();
            minHeap.pop();
            maxHeap.push(popNum);
        }
    }

    double findMedian() {
        if (minHeap.size() == maxHeap.size()) {
            int maxVal = maxHeap.top();
            int minVal = minHeap.top();
            return (static_cast<double>(maxVal) + static_cast<double>(minVal)) / 2;
        }
        else {
            return maxHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */