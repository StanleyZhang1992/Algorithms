#pragma once
/*
315. Count of Smaller Numbers After Self

You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example 1:

Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.


Constraints:

0 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
*/
#include<vector>

using namespace std;

/*
use a self-defined data structure to relate numbers to its index
divide and conquer algorithm runs in O(nlogn) time, like merge sort
*/
class Item {
public:
    int index;
    int val;

    Item(int index, int val) {
        this->index = index;
        this->val = val;
    }
};

void merge(vector<Item>& items, int lo, int loEnd, int hi, int hiEnd, vector<int>& counts) {
    vector<Item> merged;
    int counter = 0;
    int loTemp = lo;
    while (lo <= loEnd && hi <= hiEnd) {
        if (items[lo].val > items[hi].val) {
            counter += 1;
            merged.push_back(items[hi]);
            hi += 1;
        }
        else {
            counts[items[lo].index] += counter;
            merged.push_back(items[lo]);
            lo += 1;
        }
    }

    while (lo <= loEnd) {
        counts[items[lo].index] += counter;
        merged.push_back(items[lo]);
        lo += 1;
    }

    while (hi <= hiEnd) {
        merged.push_back(items[hi]);
        hi += 1;
    }

    std::copy(merged.begin(), merged.end(), items.begin() + loTemp);
}

void mergeSort(vector<Item>& items, int start, int end, vector<int>& counts) {
    // base case
    if (start >= end) {
        return;
    }
    // recursive case
    int mid = start + (end - start) / 2;
    mergeSort(items, start, mid, counts);
    mergeSort(items, mid + 1, end, counts);
    merge(items, start, mid, mid + 1, end, counts);
}

vector<int> countSmaller(vector<int>& nums) {
    vector<Item> items;
    for (int i = 0; i < nums.size(); ++i) {
        items.emplace_back(i, nums[i]);
    }
    int start = 0;
    int end = nums.size() - 1;
    vector<int> counts(nums.size(), 0);
    mergeSort(items, start, end, counts);
    return counts;
}